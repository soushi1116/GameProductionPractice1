#include "DxLib.h"
#include <math.h>
#include "Player.h"
#include "../Input/Input.h"
#include "../Elements/ElementsManager.h"
#include "../Elements/Iron.h"
#include "../Elements//Ground.h"
#include "../Elements/Water.h"
#include "../Gimmick/GimmickManager.h"
#include "../Gimmick/Tree.h"
#include "../Gimmick/AirBalloon.h"
#include "../Gimmick/WoodBlock.h"
#include "../Map/Block.h"
#include "../Sound/SoundManager.h"
#include "../Camera/Camera.h"
#include "../Scene/SceneManager.h"

#define PLAYER_MOVE_SPEED (5.0f)
#define PLAYER_RUN_SPEED (7.0f)
#define PLAYER_DEFAULT_POS_X (800)
#define PLAYER_DEFAULT_POS_Y (450)
#define PLAYER_POS_Y_MIN (800)
#define PLAYER_GRAVITY (0.5f)
#define PLAYER_JUMP_POWER (15.0f)
#define PLAYER_DEFAULT_LEVEL (8)
#define ELEMENTS_TEXT_DIF (128.0f)
#define ELEMENTS_NUM_MAX (8)
#define DOUBLE_PUSH_TIME (10)
#define PLAYER_ANIM_INTERVAL (40)
#define PLAYER_ACTION_FREEZE_TIME (20)
#define PLAYER_MAP_COLLISION_OFFSET (0.05f)
#define PLAYER_WATER_BUOYANCY (0.5f)
#define PLAYER_DIE_SCENE_CHANGE_INTERVAL (180)

PlayerData g_PlayerData = { 0 };
PlayerData g_PrevPlayerData = { 0 };

int g_ElementsTextHandle[ELEMENTS_NUM_MAX] = { 0 };

void CalcBoxCollision(PlayerData player, float& x, float& y, float& w, float& h);

void InitPlayer()
{
	g_PlayerData.posX = 0.0f;
	g_PlayerData.posY = 0.0f;

	g_PlayerData.move.x = 0.0f;
	g_PlayerData.move.y = 0.0f;

	for (int i = 0; i < ELEMENTS_NUM_MAX; i ++)
	{
		g_ElementsTextHandle[i] = { 0 };
	}

	g_PlayerData.level = 0;
	g_PlayerData.selectState = -1;
	g_PlayerData.runTimer = 0;
	g_PlayerData.animTimer = 0;
	g_PlayerData.sceneChangeTimer = 0;
	g_PlayerData.life = 0;

	g_PlayerData.active = false;
	g_PlayerData.randing = false;
	g_PlayerData.selectElements = false;
	g_PlayerData.runRight = false;
	g_PlayerData.runLeft = false;
	g_PlayerData.isTurn = false;
	g_PlayerData.action = false;
	g_PlayerData.ridingAirBalloon = false;
	g_PlayerData.hitWarp = false;
	g_PlayerData.inWater = false;
	g_PlayerData.die = false;
	g_PlayerData.clear = false;

	g_PlayerData.playAnim = PLAYER_ANIM_NONE;
}

void LoadPlayer()
{
	g_PlayerData.animation[PLAYER_ANIM_STOP].handle
		= LoadGraph("Data/Player/Stop.png");
	g_PlayerData.animation[PLAYER_ANIM_RUN_1].handle
		= LoadGraph("Data/Player/Running-1.png");
	g_PlayerData.animation[PLAYER_ANIM_RUN_2].handle
		= LoadGraph("Data/Player/Running-2.png");
	g_PlayerData.animation[PLAYER_ANIM_RUN_3].handle
		= LoadGraph("Data/Player/Running-3.png");
	g_PlayerData.animation[PLAYER_ANIM_JUMP].handle
		= LoadGraph("Data/Player/Jump.png");
	g_PlayerData.animation[PLAYER_ANIM_FALL].handle
		= LoadGraph("Data/Player/Fall.png");
	g_PlayerData.animation[PLAYER_ANIM_ACTION].handle
		= LoadGraph("Data/Player/Action.png");
	g_PlayerData.animation[PLAYER_ANIM_DEATH].handle
		= LoadGraph("Data/Player/Death.png");

	for (int i = 0; i < ELEMENTS_NUM_MAX; i++)
	{
		switch (i)
		{
		case 0:
			g_ElementsTextHandle[i] = LoadGraph("Data/Icon/CancelIcon.png");
			break;
		case 1:
			g_ElementsTextHandle[i] = LoadGraph("Data/Icon/FireIcon.png");
			break;
		case 2:
			g_ElementsTextHandle[i] = LoadGraph("Data/Icon/WaterIcon.png");
			break;
		case 3:
			g_ElementsTextHandle[i] = LoadGraph("Data/Icon/ThunderIcon.png");
			break;
		case 4:
			g_ElementsTextHandle[i] = LoadGraph("Data/Icon/WindIcon.png");
			break;
		case 5:
			g_ElementsTextHandle[i] = LoadGraph("Data/Icon/GroundIcon.png");
			break;
		case 6:
			g_ElementsTextHandle[i] = LoadGraph("Data/Icon/IceIcon.png");
			break;
		case 7:
			g_ElementsTextHandle[i] = LoadGraph("Data/Icon/IronIcon.png");
			break;
		default:
			break;
		}
	}
}

void StartPlayer()
{
	g_PlayerData.active = true;
	g_PlayerData.posX = PLAYER_DEFAULT_POS_X;
	g_PlayerData.posY = PLAYER_DEFAULT_POS_Y;
	g_PlayerData.level = PLAYER_DEFAULT_LEVEL;
	g_PlayerData.life = PLAYER_DEFAULT_LIFE;

	StartPlayerAnimation(PLAYER_ANIM_STOP);
}

void StepPlayer()
{
	if (!g_PlayerData.active) return;

	if (g_PlayerData.die)
	{
		g_PlayerData.sceneChangeTimer++;
	}

	if (g_PlayerData.die) return;

	g_PrevPlayerData = g_PlayerData;

	if (g_PlayerData.move.y < 0.0f || g_PlayerData.move.y > PLAYER_GRAVITY)
	{
		g_PlayerData.randing = false;
	}
	
	g_PlayerData.move.y += PLAYER_GRAVITY;	


	if (IsTriggerKey(KEY_X) || IsTriggerPad(PAD_Y))
	{
		if (g_PlayerData.action) return;

		g_PlayerData.action = true;

		g_PlayerData.animTimer = 0;

		float playerCenterX = g_PlayerData.posX + PLAYER_WIDTH / 2;
		float playerCenterY = g_PlayerData.posY + PLAYER_HEIGHT / 2;

		switch (g_PlayerData.selectState)
		{
		case 0:
			g_PlayerData.selectElements = false;
			break;

		case 1:
			Action((int)playerCenterX, (int)playerCenterY, ELEMENT_TYPE_FIRE, g_PlayerData.isTurn);
			g_PlayerData.selectElements = false;
			break;

		case 2:
			Action((int)playerCenterX, (int)playerCenterY, ELEMENT_TYPE_WATER, g_PlayerData.isTurn);
			g_PlayerData.selectElements = false;
			break;

		case 3:
			Action((int)playerCenterX, (int)playerCenterY, ELEMENT_TYPE_THUNDER, g_PlayerData.isTurn);
			g_PlayerData.selectElements = false;
			break;

		case 4:
			Action((int)playerCenterX, (int)playerCenterY, ELEMENT_TYPE_WIND, g_PlayerData.isTurn);
			g_PlayerData.selectElements = false;
			break;

		case 5:
			Action((int)playerCenterX, (int)playerCenterY, ELEMENT_TYPE_GROUND, g_PlayerData.isTurn);
			g_PlayerData.selectElements = false;
			break;

		case 6:
			Action((int)playerCenterX, (int)playerCenterY, ELEMENT_TYPE_ICE, g_PlayerData.isTurn);
			g_PlayerData.selectElements = false;
			break;

		case 7:
			Action((int)playerCenterX, (int)playerCenterY, ELEMENT_TYPE_IRON, g_PlayerData.isTurn);
			g_PlayerData.selectElements = false;
			break;

		default:
			break;
		}
	}

	if (g_PlayerData.action)
	{
		g_PlayerData.animTimer++;
		if (g_PlayerData.randing)
		{
			g_PlayerData.move.x = 0;
		}
	}
	else if (IsInputKey(KEY_RIGHT) || IsInputPad(PAD_RIGHT))
	{
		g_PlayerData.animTimer++;

		g_PlayerData.isTurn = false;

		g_PlayerData.runLeft = false;

		if (g_PlayerData.runRight)
		{
			g_PlayerData.move.x = PLAYER_RUN_SPEED;
		}
		else
		{
			g_PlayerData.move.x = PLAYER_MOVE_SPEED;
		}
	}
	else if (IsInputKey(KEY_LEFT) || IsInputPad(PAD_LEFT))
	{
		g_PlayerData.animTimer++;

		g_PlayerData.isTurn = true;

		g_PlayerData.runRight = false;

		if (g_PlayerData.runLeft)
		{
			g_PlayerData.move.x = -PLAYER_RUN_SPEED;
		}
		else
		{
			g_PlayerData.move.x = -PLAYER_MOVE_SPEED;
		}
	}
	else
	{
		g_PlayerData.move.x = 0;

		g_PlayerData.animTimer = 0;

		if (g_PlayerData.runRight || g_PlayerData.runLeft)
		{
			g_PlayerData.runTimer++;
		}
	}

	/*if (IsTriggerKey(KEY_RIGHT) || IsTriggerPad(PAD_RIGHT) || IsTriggerKey(KEY_LEFT) || IsTriggerPad(PAD_LEFT))
	{
		if (g_PlayerData.randing)
		{
			if (g_PlayerData.runLeft || g_PlayerData.runRight)
			{
				if (!IsPlayingBGM(BGM_RUN))
				{
					PlayBGM(BGM_RUN);
				}
			}
			else
			{
				if (!IsPlayingBGM(BGM_WALK))
				{
					PlayBGM(BGM_WALK);
				}
			}
		}
	}*/

	if (g_PlayerData.runTimer >= DOUBLE_PUSH_TIME)
	{
		g_PlayerData.runRight = false;
		g_PlayerData.runLeft = false;
		g_PlayerData.runTimer = 0;
	}

	if (IsReleaseKey(KEY_RIGHT) || IsReleasePad(PAD_RIGHT))
	{
		if (!g_PlayerData.runRight)
		{
			g_PlayerData.runRight = true;
		}
		StopBGM(BGM_WALK);
		StopBGM(BGM_RUN);
	}

	if (IsReleaseKey(KEY_LEFT) || IsReleasePad(PAD_LEFT))
	{
		if (!g_PlayerData.runLeft)
		{
			g_PlayerData.runLeft = true;
		}
		StopBGM(BGM_WALK);
		StopBGM(BGM_RUN);
	}

	if (IsTriggerKey(KEY_UP) || IsTriggerPad(PAD_B))
	{
		if (g_PlayerData.hitWarp)
		{
			g_PlayerData.posX += MAP_CHIP_WIDTH * 4;
			g_PlayerData.hitWarp = false;
		}
		else if (g_PlayerData.randing && !g_PlayerData.action)
		{
			g_PlayerData.randing = false;
			g_PlayerData.move.y -= PLAYER_JUMP_POWER;

			PlaySE(SE_JUMP);
		}
		else if (g_PlayerData.inWater)
		{
			g_PlayerData.move.y -= PLAYER_JUMP_POWER;
		}
	}

	if (IsTriggerKey(KEY_Z) || IsTriggerPad(PAD_X))
	{		
		if (!g_PlayerData.selectElements)
		{
			g_PlayerData.selectElements = true;
			g_PlayerData.selectState = 0;
			return;
		}

		if (g_PlayerData.selectState < g_PlayerData.level - 1)
		{
			g_PlayerData.selectState++;
		}
		else
		{
			g_PlayerData.selectState = 0;
		}
		
	}

	if (IsTriggerKey(KEY_A))
	{
		if (g_PlayerData.level < 8)
		{
			g_PlayerData.level++;
		}
		else
		{
			g_PlayerData.level = PLAYER_DEFAULT_LEVEL;
		}
	}

	if (IsTriggerKey(KEY_C))
	{
		PlayerHitEnemy();
	}
}

void UpdatePlayer()
{
	if (!g_PlayerData.active) return;

	g_PlayerData.hitWarp = false;

	if (g_PlayerData.sceneChangeTimer > PLAYER_DIE_SCENE_CHANGE_INTERVAL)
	{
		ChangeScene(SCENE_TITLE);
	}

	if (g_PlayerData.randing)
	{
		if (fabsf(g_PlayerData.move.x) == PLAYER_MOVE_SPEED)
		{
			if (!IsPlayingBGM(BGM_WALK))
			{
				PlayBGM(BGM_WALK);
			}
		}
		else if (fabsf(g_PlayerData.move.x) == PLAYER_RUN_SPEED)
		{
			if (!IsPlayingBGM(BGM_RUN))
			{
				PlayBGM(BGM_RUN);
			}
		}
	}
	else
	{
		StopBGM(BGM_WALK);
		StopBGM(BGM_RUN);
	}

	if (g_PlayerData.inWater)
	{
		g_PlayerData.move.x *= PLAYER_WATER_BUOYANCY;
		g_PlayerData.move.y *= PLAYER_WATER_BUOYANCY;
	}

	g_PlayerData.posX += g_PlayerData.move.x;
	g_PlayerData.posY += g_PlayerData.move.y;

	if (g_PlayerData.die)
	{
		g_PlayerData.move.x = 0.0f;
		StopBGM(BGM_WALK);
		StopBGM(BGM_RUN);
	}

	if (g_PlayerData.animTimer > PLAYER_ANIM_INTERVAL)
	{
		g_PlayerData.animTimer = 0;
	}

	if (g_PlayerData.animTimer > PLAYER_ACTION_FREEZE_TIME)
	{
		g_PlayerData.action = false;
	}

	if (g_PlayerData.inWater)
	{
		g_PlayerData.inWater = false;
	}

	if (g_PlayerData.life <= 0)
	{
		g_PlayerData.die = true;
	}

	UpdatePlayerAnimation();
}

void DrawPlayer()
{
	if (!g_PlayerData.active) return;

	CameraData camera = GetCamera();

	PlayerAnimationType animType = g_PlayerData.playAnim;
	AnimationData* animData = &g_PlayerData.animation[animType];
	if (!g_PlayerData.isTurn)
	{
		DrawAnimation(animData, g_PlayerData.posX - camera.posX, g_PlayerData.posY - camera.posY);
	}
	else
	{
		DrawTurnAnimation(animData, g_PlayerData.posX - camera.posX, g_PlayerData.posY - camera.posY);
	}

	if (g_PlayerData.selectElements)
	{
		int playerCenterX = (int)g_PlayerData.posX + PLAYER_WIDTH / 2 - camera.posX;
		int playerCenterY = (int)g_PlayerData.posY + PLAYER_HEIGHT / 2 - camera.posY;

		int textRotation = sinf(DX_PI_F);

		for (int i = 0; i < g_PlayerData.level; i++)
		{
			if (i == g_PlayerData.selectState)
			{
				DrawRotaGraph(playerCenterX - ELEMENTS_TEXT_DIF * -sinf(DX_TWO_PI_F * i / g_PlayerData.level)
					, playerCenterY - ELEMENTS_TEXT_DIF * cosf(DX_TWO_PI_F * i / g_PlayerData.level),
					2, 0, g_ElementsTextHandle[i], TRUE);
			}
			else
			{
				DrawRotaGraph(playerCenterX - ELEMENTS_TEXT_DIF * -sinf(DX_TWO_PI_F * i / g_PlayerData.level)
					, playerCenterY - ELEMENTS_TEXT_DIF * cosf(DX_TWO_PI_F * i / g_PlayerData.level),
					1, 0, g_ElementsTextHandle[i], TRUE);
			}
		}
	}
}

void FinPlayer()
{
	DeleteGraph(g_PlayerData.playerHandle);
	for (int i = 0; i < ELEMENTS_NUM_MAX; i++)
	{
		DeleteGraph(g_ElementsTextHandle[i]);
	}
}


PlayerData GetPlayer()
{
	return g_PlayerData;
}

void StartPlayerAnimation(PlayerAnimationType anim)
{
	if (anim == g_PlayerData.playAnim) return;

	g_PlayerData.playAnim = anim;

	AnimationData* animData = &g_PlayerData.animation[anim];

	StartAnimation(animData, g_PlayerData.posX, g_PlayerData.posY);
}

void UpdatePlayerAnimation()
{
	if (!g_PlayerData.active) return;

	if (g_PlayerData.die)
	{
		StartPlayerAnimation(PLAYER_ANIM_DEATH);
	}
	else if (g_PlayerData.action)
	{
		StartPlayerAnimation(PLAYER_ANIM_ACTION);
	}
	else if (!g_PlayerData.randing)
	{
		if (g_PlayerData.move.y < 0.0f)
		{
			StartPlayerAnimation(PLAYER_ANIM_JUMP);
		}
		else
		{
			StartPlayerAnimation(PLAYER_ANIM_FALL);
		}
	}
	else if (IsInputKey(KEY_RIGHT) || IsInputKey(KEY_LEFT) || IsInputPad(PAD_RIGHT) || IsInputPad(PAD_LEFT))
	{
		if (g_PlayerData.animTimer >= 0 && g_PlayerData.animTimer < 10)
		{
			StartPlayerAnimation(PLAYER_ANIM_RUN_2);
		}
		else if (g_PlayerData.animTimer >= 10 && g_PlayerData.animTimer < 20)
		{
			StartPlayerAnimation(PLAYER_ANIM_RUN_1);
		}
		else if (g_PlayerData.animTimer >= 20 && g_PlayerData.animTimer < 30)
		{
			StartPlayerAnimation(PLAYER_ANIM_RUN_2);
		}
		else if (g_PlayerData.animTimer >= 30 && g_PlayerData.animTimer < 40)
		{
			StartPlayerAnimation(PLAYER_ANIM_RUN_3);
		}
	}
	else
	{
		StartPlayerAnimation(PLAYER_ANIM_STOP);
	}
}

void SpawnPlayer(float posX, float posY)
{
	if (!g_PlayerData.active)
	{
		g_PlayerData.active = true;
		g_PlayerData.posX = posX;
		g_PlayerData.posY = posY;
		g_PlayerData.level = PLAYER_DEFAULT_LEVEL;
		g_PlayerData.life = PLAYER_DEFAULT_LIFE;

		StartPlayerAnimation(PLAYER_ANIM_STOP);
	}
}

void PlayerRand()
{
	PlaySE(SE_RAND);

	if (fabsf(g_PlayerData.move.x) == PLAYER_MOVE_SPEED)
	{
		PlayBGM(BGM_WALK);
	}
	else if (fabsf(g_PlayerData.move.x) == PLAYER_RUN_SPEED)
	{
		PlayBGM(BGM_RUN);
	}

	g_PlayerData.randing = true;
}

void PlayerHitNormalBlockX(MapChipData mapChipData)
{
	/*PlayerData player = g_PlayerData;
	BlockData* block = mapChipData.data;
	const float POS_OFFSET = PLAYER_MAP_COLLISION_OFFSET;
	const float SIZE_OFFSET = PLAYER_MAP_COLLISION_OFFSET * 2;

	player.isTurn = g_PrevPlayerData.isTurn;

	player.posX = g_PlayerData.posX;
	player.posY = g_PrevPlayerData.posY;

	float x, y, w, h;
	CalcBoxCollision(player, x, y, w, h);

	if (CheckSquareSquare(x + POS_OFFSET, y + POS_OFFSET, w - SIZE_OFFSET, h - SIZE_OFFSET,
		block->pos.x, block->pos.y, MAP_CHIP_WIDTH, MAP_CHIP_HEIGHT))
	{
		if (player.move.x > 0.0f)
		{
			g_PlayerData.posX -= (x + w) - block->pos.x;
		}
		else if (player.move.x < 0.0f)
		{
			g_PlayerData.posX += (block->pos.x + MAP_CHIP_WIDTH) - x;
		}
	}*/
}

void PlayerHitNormalBlockY(MapChipData mapChipData)
{
	/*PlayerData player = g_PlayerData;
	BlockData* block = mapChipData.data;
	const float POS_OFFSET = PLAYER_MAP_COLLISION_OFFSET;
	const float SIZE_OFFSET = PLAYER_MAP_COLLISION_OFFSET * 2;

	player.isTurn = g_PrevPlayerData.isTurn;

	float x, y, w, h;
	CalcBoxCollision(player, x, y, w, h);

	if (CheckSquareSquare(x + POS_OFFSET, y + POS_OFFSET, w - SIZE_OFFSET, h - SIZE_OFFSET,
		block->pos.x, block->pos.y, MAP_CHIP_WIDTH, MAP_CHIP_HEIGHT))
	{

		g_PlayerData.move.y = 0.0f;

		if (player.move.y > 0.0f)
		{
			g_PlayerData.posY -= (y + h) - block->pos.y;
			g_PlayerData.randing = true;
		}
		else if (player.move.y < 0.0f)
		{
			g_PlayerData.posY += (block->pos.y + MAP_CHIP_HEIGHT) - y;
		}
	}*/
}

void PlayerHitBlock(int index)
{
	PlayerData player = GetPlayer();
	BlockData* block = GetBlocks(index);
	player.isTurn = g_PrevPlayerData.isTurn;

	player.posX = g_PlayerData.posX;
	player.posY = g_PrevPlayerData.posY;

	for (int i = 0; i < BLOCK_MAX; i++)
	{
		if (i != index) continue;

		if (player.move.x > 0.0f && player.posY + PLAYER_HEIGHT > block->pos.y)
		{
			if (player.posY < block->pos.y + MAP_CHIP_HEIGHT)
			{
				g_PlayerData.posX = block->pos.x - PLAYER_WIDTH;
			}
		}
		else if (player.move.x < 0.0f && player.posY + PLAYER_HEIGHT > block->pos.y)
		{
			if (player.posY < block->pos.y + MAP_CHIP_HEIGHT)
			{
				g_PlayerData.posX = block->pos.x + MAP_CHIP_WIDTH;
			}
		}

		if (player.posY <= block->pos.y - PLAYER_HEIGHT)
		{
			if (g_PrevPlayerData.posX == block->pos.x + MAP_CHIP_WIDTH) continue;
			if (g_PrevPlayerData.posX + PLAYER_WIDTH == block->pos.x) continue;

			if (!g_PlayerData.randing)
			{
				PlayerRand();
			}

			g_PlayerData.move.y = 0.0f;
			g_PlayerData.posY = block->pos.y - PLAYER_HEIGHT;
		}
		else if (g_PlayerData.move.y < 0.0f && g_PrevPlayerData.posY > block->pos.y + MAP_CHIP_HEIGHT)
		{
			if (g_PrevPlayerData.posX == block->pos.x + MAP_CHIP_WIDTH) continue;
			if (g_PrevPlayerData.posX + PLAYER_WIDTH == block->pos.x) continue;

			g_PlayerData.move.y = 0.0f;
			g_PlayerData.posY = block->pos.y + MAP_CHIP_HEIGHT;
			
		}

		break;
	}
}

void PlayerHitIron(int index)
{
	PlayerData player = GetPlayer();
	VECTOR ironPos = GetElementPos(index, ELEMENT_TYPE_IRON);

	player.isTurn = g_PrevPlayerData.isTurn;

	player.posX = g_PlayerData.posX;
	player.posY = g_PrevPlayerData.posY;

	if (player.move.x > 0.0f && player.posY + PLAYER_HEIGHT > ironPos.y)
	{
		if (player.posY < ironPos.y + IRON_HEIGHT)
		{
			g_PlayerData.posX = ironPos.x - PLAYER_WIDTH;
		}
	}
	else if (player.move.x < 0.0f && player.posY + PLAYER_HEIGHT > ironPos.y)
	{
		if (player.posY < ironPos.y + IRON_HEIGHT)
		{
			g_PlayerData.posX = ironPos.x + IRON_WIDTH;
		}
	}

	if (player.posY <= ironPos.y - PLAYER_HEIGHT)
	{
		if (g_PrevPlayerData.posX == ironPos.x + IRON_WIDTH) return;
		if (g_PrevPlayerData.posX + PLAYER_WIDTH == ironPos.x) return;

		if (!g_PlayerData.randing)
		{
			PlayerRand();
		}

		g_PlayerData.move.y = 0.0f;
		g_PlayerData.posY = ironPos.y - PLAYER_HEIGHT;
	}
	else if (g_PlayerData.move.y < 0.0f && g_PrevPlayerData.posY > ironPos.y + IRON_HEIGHT)
	{
		if (g_PrevPlayerData.posX == ironPos.x + IRON_WIDTH) return;
		if (g_PrevPlayerData.posX + PLAYER_WIDTH == ironPos.x) return;

		g_PlayerData.move.y = 0.0f;
		g_PlayerData.posY = ironPos.y + IRON_HEIGHT;
	}
}

void PlayerHitGround(int index)
{
	PlayerData player = GetPlayer();
	VECTOR groundPos = GetElementPos(index, ELEMENT_TYPE_GROUND);

	player.isTurn = g_PrevPlayerData.isTurn;

	player.posX = g_PlayerData.posX;
	player.posY = g_PrevPlayerData.posY;

	if (player.move.x > 0.0f && player.posY + PLAYER_HEIGHT > groundPos.y)
	{
		if (player.posY < groundPos.y + GROUND_HEIGHT)
		{
			g_PlayerData.posX = groundPos.x - PLAYER_WIDTH;
		}
	}
	else if (player.move.x < 0.0f && player.posY + PLAYER_HEIGHT > groundPos.y)
	{
		if (player.posY < groundPos.y + GROUND_HEIGHT)
		{
			g_PlayerData.posX = groundPos.x + GROUND_WIDTH;
		}
	}

	if (player.posY <= groundPos.y - PLAYER_HEIGHT)
	{
		if (g_PrevPlayerData.posX == groundPos.x + GROUND_WIDTH) return;
		if (g_PrevPlayerData.posX + PLAYER_WIDTH == groundPos.x) return;

		if (!g_PlayerData.randing)
		{
			PlayerRand();
		}

		g_PlayerData.move.y = 0.0f;
		g_PlayerData.posY = groundPos.y - PLAYER_HEIGHT;
	}
	else if (g_PlayerData.move.y < 0.0f && g_PrevPlayerData.posY > groundPos.y + GROUND_HEIGHT)
	{
		if (g_PrevPlayerData.posX == groundPos.x + GROUND_WIDTH) return;
		if (g_PrevPlayerData.posX + PLAYER_WIDTH == groundPos.x) return;

		g_PlayerData.move.y = 0.0f;
		g_PlayerData.posY = groundPos.y + GROUND_HEIGHT;
	}
}

void PlayerHitWater(int index)
{
	if (!IsWaterFreeze(index))
	{
		if (!g_PlayerData.inWater)
		{
			g_PlayerData.inWater = true;
		}
	}
	else
	{
		PlayerData player = GetPlayer();
		VECTOR waterPos = GetElementPos(index, ELEMENT_TYPE_WATER);

		player.isTurn = g_PrevPlayerData.isTurn;

		player.posX = g_PlayerData.posX;
		player.posY = g_PrevPlayerData.posY;

		if (player.move.x > 0.0f && player.posY + PLAYER_HEIGHT > waterPos.y)
		{
			if (player.posY < waterPos.y + GROUND_HEIGHT)
			{
				g_PlayerData.posX = waterPos.x - PLAYER_WIDTH;
			}
		}
		else if (player.move.x < 0.0f && player.posY + PLAYER_HEIGHT > waterPos.y)
		{
			if (player.posY < waterPos.y + WATER_HEIGHT)
			{
				g_PlayerData.posX = waterPos.x + WATER_WIDTH;
			}
		}

		if (player.posY <= waterPos.y - PLAYER_HEIGHT)
		{
			if (g_PrevPlayerData.posX == waterPos.x + WATER_WIDTH) return;
			if (g_PrevPlayerData.posX + PLAYER_WIDTH == waterPos.x) return;

			if (!g_PlayerData.randing)
			{
				PlayerRand();
			}

			g_PlayerData.move.y = 0.0f;
			g_PlayerData.posY = waterPos.y - PLAYER_HEIGHT;
		}
		else if (g_PlayerData.move.y < 0.0f && g_PrevPlayerData.posY > waterPos.y + WATER_HEIGHT)
		{
			if (g_PrevPlayerData.posX == waterPos.x + WATER_WIDTH) return;
			if (g_PrevPlayerData.posX + PLAYER_WIDTH == waterPos.x) return;

			g_PlayerData.move.y = 0.0f;
			g_PlayerData.posY = waterPos.y + WATER_HEIGHT;
		}
	}
}

void PlayerHitTree(int index)
{
	PlayerData player = GetPlayer();
	VECTOR treePos = GetGimmickPos(index, GIMMICK_TYPE_TREE);

	player.isTurn = g_PrevPlayerData.isTurn;

	player.posX = g_PlayerData.posX;
	player.posY = g_PrevPlayerData.posY;

	if (player.move.x > 0.0f && player.posY + PLAYER_HEIGHT > treePos.y)
	{
		g_PlayerData.posX = treePos.x - PLAYER_WIDTH;
	}
	else if (player.move.x < 0.0f && player.posY + PLAYER_HEIGHT > treePos.y)
	{
		g_PlayerData.posX = treePos.x + TREE_WIDTH;
	}

	if (player.posY <= treePos.y - PLAYER_HEIGHT)
	{
		if (!g_PlayerData.randing)
		{
			PlayerRand();
		}

		g_PlayerData.move.y = 0.0f;
		g_PlayerData.posY = treePos.y - PLAYER_HEIGHT;
	}
	else if (g_PlayerData.move.y < 0.0f && g_PrevPlayerData.posY > treePos.y + TREE_HEIGHT)
	{
		g_PlayerData.move.y = 0.0f;
		g_PlayerData.posY = treePos.y + TREE_HEIGHT;
	}
}

void PlayerHitAirBalloon(int index)
{
	PlayerData player = GetPlayer();
	VECTOR airBalloonPos = GetGimmickPos(index, GIMMICK_TYPE_AIRBALLOON);

	player.isTurn = g_PrevPlayerData.isTurn;

	player.posX = g_PlayerData.posX;
	player.posY = g_PrevPlayerData.posY;

	if (g_PlayerData.randing)
	{
		if (player.move.x > 0.0f && player.posY + PLAYER_HEIGHT > airBalloonPos.y)
		{
			g_PlayerData.posX = airBalloonPos.x - PLAYER_WIDTH;
		}
		else if (player.move.x < 0.0f && player.posY + PLAYER_HEIGHT > airBalloonPos.y)
		{
			g_PlayerData.posX = airBalloonPos.x + AIRBALLOON_WIDTH;
		}

		if (player.posY <= airBalloonPos.y - PLAYER_HEIGHT)
		{
			if (!g_PlayerData.randing)
			{
				PlayerRand();
			}

			g_PlayerData.move.y = 0.0f;
			g_PlayerData.posY = airBalloonPos.y - PLAYER_HEIGHT;
		}
		else if (g_PlayerData.move.y < 0.0f && g_PrevPlayerData.posY > airBalloonPos.y + AIRBALLOON_HEIGHT)
		{
			g_PlayerData.move.y = 0.0f;
			g_PlayerData.posY = airBalloonPos.y + AIRBALLOON_HEIGHT;
		}
	}
	else
	{
		RideAirBalloon(airBalloonPos);
	}
}

void PlayerHitWoodBlock(int index)
{
	PlayerData player = GetPlayer();
	VECTOR woodBlockPos = GetGimmickPos(index, GIMMICK_TYPE_WOODBLOCK);

	player.isTurn = g_PrevPlayerData.isTurn;

	player.posX = g_PlayerData.posX;
	player.posY = g_PrevPlayerData.posY;

	if (player.move.x > 0.0f && player.posY + PLAYER_HEIGHT > woodBlockPos.y)
	{
		g_PlayerData.posX = woodBlockPos.x - PLAYER_WIDTH;
	}
	else if (player.move.x < 0.0f && player.posY + PLAYER_HEIGHT > woodBlockPos.y)
	{
		g_PlayerData.posX = woodBlockPos.x + WOODBLOCK_WIDTH;
	}

	if (player.posY <= woodBlockPos.y - PLAYER_HEIGHT)
	{
		if (!g_PlayerData.randing)
		{
			PlayerRand();
		}

		g_PlayerData.move.y = 0.0f;
		g_PlayerData.posY = woodBlockPos.y - PLAYER_HEIGHT;
	}
	else if (g_PlayerData.move.y < 0.0f && g_PrevPlayerData.posY > woodBlockPos.y + WOODBLOCK_HEIGHT)
	{
		g_PlayerData.move.y = 0.0f;
		g_PlayerData.posY = woodBlockPos.y + WOODBLOCK_HEIGHT;
	}
}

void PlayerHitWarp()
{
	g_PlayerData.hitWarp = true;
}

void PlayerHitEnemy()
{
	PlaySE(SE_DAMAGE);
	g_PlayerData.life--;
}

void RideAirBalloon(VECTOR airBalloonPos)
{
	g_PlayerData.posX = airBalloonPos.x;
	g_PlayerData.posY = airBalloonPos.y;
	g_PlayerData.move.x = 0.0f;
	g_PlayerData.posY = PLAYER_POS_Y_MIN - PLAYER_HEIGHT;
	g_PlayerData.randing = true;
	g_PlayerData.move.y = 0.0f;
}

void CalcBoxCollision(PlayerData player, float& x, float& y, float& w, float& h)
{
	x = player.isTurn ?
		player.posX + PLAYER_WIDTH - player.boxCollision.posX - player.boxCollision.width :
		player.posX + player.boxCollision.posY;
	y = player.posY + player.boxCollision.posY;
	w = player.boxCollision.width;
	h = player.boxCollision.height;
}