#include "DxLib.h"
#include "S_Kurosawa.h"
#include "../../Player/Player.h"
#include "../../Effect/AnimationEffect.h"
#include "../../Input/Input.h"
#include"../../Scene/SceneManager.h"
#include "../../Elements/ElementsManager.h"
#include "../../Map/MapManager.h"
#include "../../Collision/Collision.h"
#include "../../Gimmick/Gimmick.h"
#include "../../Map/Block.h"
#include "../../UI/UIImage.h"
#include "../../Sound/SoundManager.h"
#include "../../Camera/Camera.h"
#include "../../Warp/Warp.h"
#include "../../GameSetting/GameSetting.h"

KurosawaData g_KurosawaData = { 0 };
LifeData g_LifeData[PLAYER_LIFE_MAX] = { 0 };
int g_LifeHandle = 0;
int g_DieTextHandle = 0;
int g_ClearTextHandle = 0;
VECTOR dieTextPos = VGet(0.0f, 0.0f, 0.0f);
VECTOR clearTextPos = VGet(0.0f, 0.0f, 0.0f);

#define TEXTPOS_X (200)
#define TEXTPOS_Y (0)
#define BLOCK_NUM_MAX (32)
#define MAP_POS_Y (700)
#define GIMMICK_TREE_POS_X (300)
#define GIMMICK_TREE_POS_Y (500)
#define GIMMICK_AIRBALLOON_POS_X (1000)
#define GIMMICK_AIRBALLOON_POS_Y (600)
#define GIMMICK_WOODBLOCK_POS_X (300)
#define GIMMICK_WOODBLOCK_POS_Y (750)
#define PLAYER_SPAWN_POS_X (2000.0f)
#define PLAYER_SPAWN_POS_Y (600.0f)
#define SLIDE_TEXT_POS_X (550.0f)
#define SLIDE_TEXT_POS_Y (-100.0f)
#define SLIDE_TEXT_MOVE_Y (10.0f);

void InitKuroScene()
{
	InitPlayer();

	InitAnimationEffect();

	InitElementsManager();

	g_KurosawaData.textHandle = 0;

	InitMap();

	InitUIImage();

	InitWarp();

	InitCamera();
}

void LoadKuroScene()
{
	LoadPlayer();

	LoadAnimationEffect();

	LoadElementsManager();

	g_KurosawaData.textHandle = LoadGraph("Data/Player/SceneForKurosawa.png");

	g_LifeHandle = LoadGraph("Data/UI/Heart.png");
	g_DieTextHandle = LoadGraph("Data/UI/DiedText.png");
	g_ClearTextHandle = LoadGraph("Data/UI/ClearText.png");

	LoadMap();

	LoadWarp();

	LoadUIImage();
}

void StartKuroScene()
{
	//StartPlayer();
	SpawnPlayer(PLAYER_SPAWN_POS_X, PLAYER_SPAWN_POS_Y);

	StartElementsManager();

	CreateWarp(MAP_CHIP_WIDTH * 24, MAP_CHIP_HEIGHT * 17);
	//CreateWarp(MAP_CHIP_WIDTH * 50, MAP_CHIP_HEIGHT * 17);

	StartMap();

	CreateUIImage(UI_IMAGE_LIFETEXT, 30.0f, 50.0f);

	LifeData* life = g_LifeData;
	for (int i = 0; i < PLAYER_LIFE_MAX; i++, life++)
	{
		life->pos.x = (float)(200 + i * 60);
		life->pos.y = 50.0f;
	}

	dieTextPos.x = SLIDE_TEXT_POS_X;
	dieTextPos.y = SLIDE_TEXT_POS_Y;

	clearTextPos.x = SLIDE_TEXT_POS_X;
	clearTextPos.y = SLIDE_TEXT_POS_Y;

	PlayBGM(BGM_PLAY);
}

void StepKuroScene()
{
	StepPlayer();

	StepAnimationEffect();

	StepElementsManager();

	if (IsTriggerKey(KEY_K))
	{
		ChangeScene(SCENE_TITLE);
	}

	StepCamera();
}

void UpdateKuroScene()
{
	UpdatePlayer();

	PlayerData player = GetPlayer();
	if (player.die && dieTextPos.y < SCREEN_HEIGHT / 2)
	{
		dieTextPos.y += SLIDE_TEXT_MOVE_Y;
	}

	PlayerData player = GetPlayer();
	if (player.clear && clearTextPos.y < SCREEN_HEIGHT / 2)
	{
		clearTextPos.y += SLIDE_TEXT_MOVE_Y;
	}

	UpdateAnimationEffect();

	UpdateElementsManager();

	CheckCollision();
}

void DrawKuroScene()
{
	DrawMap();

	DrawWarp();

	DrawPlayer();

	DrawAnimationEffect();

	DrawElementsManager();

	LifeData* life = g_LifeData;
	PlayerData player = GetPlayer();
	for (int i = 0; i < player.life; i++, life++)
	{
		DrawGraph(life->pos.x, life->pos.y, g_LifeHandle, TRUE);
	}

	DrawGraph(dieTextPos.x, dieTextPos.y, g_DieTextHandle, TRUE);

	DrawGraph(clearTextPos.x, clearTextPos.y, g_ClearTextHandle, TRUE);

	DrawUIImage();

	DrawCamera();
}

void FinKuroScene()
{
	FinMap();

	FinWarp();

	FinPlayer();

	FinAnimationEffect();

	FinElementsManager();

	DeleteGraph(g_KurosawaData.textHandle);

	DeleteGraph(g_LifeHandle);

	DeleteGraph(g_DieTextHandle);

	DeleteGraph(g_ClearTextHandle);

	ResetUIImage();

	StopBGM(BGM_PLAY);
}