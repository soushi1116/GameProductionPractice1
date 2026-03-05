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

KurosawaData g_KurosawaData = { 0 };

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

	LoadMap();

	LoadWarp();

	LoadUIImage();
}

void StartKuroScene()
{
	StartPlayer();

	StartElementsManager();

	CreateWarp(MAP_CHIP_WIDTH * 24, MAP_CHIP_HEIGHT * 17);
	CreateWarp(MAP_CHIP_WIDTH * 50, MAP_CHIP_HEIGHT * 17);

	StartMap();

	CreateUIImage(UI_IMAGE_LIFETEXT, 30.0f, 50.0f);

	PlayerData player = GetPlayer();
	for (int i = 0; i < player.life; i++)
	{
		CreateUIImage(UI_IMAGE_LIFE, (float)(200 + i * 60), 50.0f);
	}

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

	ResetUIImage();

	StopBGM(BGM_PLAY);
}