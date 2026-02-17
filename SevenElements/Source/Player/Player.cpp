#include "DxLib.h"
#include <math.h>
#include "Player.h"
#include "../Input/Input.h"

#define PLAYER_MOVE_SPEED (5.0f)
#define PLAYER_DEFAULT_POS_X (800)
#define PLAYER_DEFAULT_POS_Y (450)
#define PLAYER_POS_Y_MIN (800)
#define GRAVITY (0.5f)
#define PLAYER_JUMP_POWER (10.0f)
#define PLAYER_DEFAULT_LEVEL (1)
#define ELEMENTS_TEXT_DIF (128.0f)
#define ELEMENTS_NUM_MAX (7)

PlayerData g_PlayerData = { 0 };

int elementsTextHandle[] = { 0 };

void InitPlayer()
{
	g_PlayerData.pos.x = 0.0f;
	g_PlayerData.pos.y = 0.0f;

	g_PlayerData.move.x = 0.0f;
	g_PlayerData.move.y = 0.0f;

	for (int i = 0; i < ELEMENTS_NUM_MAX; i ++)
	{
		elementsTextHandle[i] = { 0 };
	}

	g_PlayerData.level = 0;
	g_PlayerData.selectState = -1;

	g_PlayerData.active = false;
	g_PlayerData.randing = false;
	g_PlayerData.selectElements = false;
}

void LoadPlayer()
{
	g_PlayerData.playerHandle = LoadGraph("Data/Player/Player(pre).png");

	for (int i = 0; i < ELEMENTS_NUM_MAX; i++)
	{
		switch (i)
		{
		case 0:
			elementsTextHandle[i] = LoadGraph("Data/Player/Fire(pre).png");
			break;
		case 1:
			elementsTextHandle[i] = LoadGraph("Data/Player/Water(pre).png");
			break;
		case 2:
			elementsTextHandle[i] = LoadGraph("Data/Player/Thonder(pre).png");
			break;
		case 3:
			elementsTextHandle[i] = LoadGraph("Data/Player/Wind(pre).png");
			break;
		case 4:
			elementsTextHandle[i] = LoadGraph("Data/Player/Ground(pre).png");
			break;
		case 5:
			elementsTextHandle[i] = LoadGraph("Data/Player/Ice(pre).png");
			break;
		case 6:
			elementsTextHandle[i] = LoadGraph("Data/Player/Iron(pre).png");
			break;
		default:
			break;
		}
	}
}

void StartPlayer()
{
	g_PlayerData.active = true;
	g_PlayerData.pos.x = PLAYER_DEFAULT_POS_X;
	g_PlayerData.pos.y = PLAYER_DEFAULT_POS_Y;
	g_PlayerData.level = PLAYER_DEFAULT_LEVEL;
}

void StepPlayer()
{
	if (!g_PlayerData.active) return;

	if (g_PlayerData.pos.y < PLAYER_POS_Y_MIN)
	{
		g_PlayerData.move.y += GRAVITY;
		g_PlayerData.randing = false;
	}
	else
	{
		g_PlayerData.randing = true;
		g_PlayerData.move.y = 0;
	}

	if (IsInputKey(KEY_RIGHT))
	{
		g_PlayerData.move.x = PLAYER_MOVE_SPEED;
	}
	else if (IsInputKey(KEY_LEFT))
	{
		g_PlayerData.move.x = -PLAYER_MOVE_SPEED;
	}
	else
	{
		g_PlayerData.move.x = 0;
	}

	if (IsTriggerKey(KEY_UP))
	{
		if (g_PlayerData.randing)
		{
			g_PlayerData.move.y -= PLAYER_JUMP_POWER;
		}
	}

	if (IsTriggerKey(KEY_X))
	{
		if (!g_PlayerData.selectElements)
		{
			g_PlayerData.selectElements = true;
		}
		else
		{
			g_PlayerData.selectElements = false;
			g_PlayerData.selectState = -1;
		}
	}

	if (IsTriggerKey(KEY_Z))
	{
		if (g_PlayerData.selectElements)
		{
			if (g_PlayerData.selectState < g_PlayerData.level - 1)
			{
				g_PlayerData.selectState++;
			}
			else
			{
				g_PlayerData.selectState = 0;
			}
		}
	}

	if (IsTriggerKey(KEY_A))
	{
		if (g_PlayerData.level < 7)
		{
			g_PlayerData.level++;
		}
		else
		{
			g_PlayerData.level = PLAYER_DEFAULT_LEVEL;
		}
	}
}

void UpdatePlayer()
{
	if (!g_PlayerData.active) return;

	g_PlayerData.pos.x += g_PlayerData.move.x;
	g_PlayerData.pos.y += g_PlayerData.move.y;
}

void DrawPlayer()
{
	if (!g_PlayerData.active) return;

	DrawGraph(g_PlayerData.pos.x, g_PlayerData.pos.y, g_PlayerData.playerHandle, TRUE);

	if (g_PlayerData.selectElements)
	{
		int playerCenterX = (int)g_PlayerData.pos.x + PLAYER_WIDTH / 2;
		int playerCenterY = (int)g_PlayerData.pos.y + PLAYER_HEIGHT / 2;

		int textRotation = sinf(DX_PI_F);

		for (int i = 0; i < g_PlayerData.level; i++)
		{
			if (i == g_PlayerData.selectState)
			{
				DrawRotaGraph(playerCenterX - ELEMENTS_TEXT_DIF * -sinf(DX_TWO_PI_F * i / g_PlayerData.level)
					, playerCenterY - ELEMENTS_TEXT_DIF * cosf(DX_TWO_PI_F * i / g_PlayerData.level),
					2, 0, elementsTextHandle[i], TRUE);
			}
			else
			{
				DrawRotaGraph(playerCenterX - ELEMENTS_TEXT_DIF * -sinf(DX_TWO_PI_F * i / g_PlayerData.level)
					, playerCenterY - ELEMENTS_TEXT_DIF * cosf(DX_TWO_PI_F * i / g_PlayerData.level),
					1, 0, elementsTextHandle[i], TRUE);
			}
		}
	}
}

void FinPlayer()
{
	DeleteGraph(g_PlayerData.playerHandle);
	for (int i = 0; i < ELEMENTS_NUM_MAX; i++)
	{
		DeleteGraph(elementsTextHandle[i]);
	}
}


PlayerData GetPlayer()
{
	return g_PlayerData;
}

void PlayerHitMap()
{

}