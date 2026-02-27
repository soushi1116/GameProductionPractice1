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
}

void LoadKuroScene()
{
	LoadPlayer();

	LoadAnimationEffect();

	LoadElementsManager();

	g_KurosawaData.textHandle = LoadGraph("Data/Player/SceneForKurosawa.png");

	LoadMap();
}

void StartKuroScene()
{
	StartPlayer();

	StartElementsManager();

	StartMap();

	for (int i = 0; i < BLOCK_NUM_MAX; i++)
	{
		VECTOR pos = VGet(0.0f, 0.0f, 0.0f);

		if (i > 18 && i < 25)
		{
			pos = VGet(MAP_CHIP_WIDTH * i, MAP_POS_Y + MAP_CHIP_HEIGHT * 3, 0.0f);
		}
		else
		{
			pos = VGet(MAP_CHIP_WIDTH * i, MAP_POS_Y, 0.0f);
		}

		CreateBlock(NORMAL_BLOCK, pos);
	}

	for (int i = 0; i < 3; i++)
	{
		VECTOR pos1 = VGet(MAP_CHIP_WIDTH * 18, MAP_POS_Y + MAP_CHIP_HEIGHT * (i + 1), 0.0f);
		VECTOR pos2 = VGet(MAP_CHIP_WIDTH * 25, MAP_POS_Y + MAP_CHIP_HEIGHT * (i + 1), 0.0f);

		CreateBlock(NORMAL_BLOCK, pos1);
		CreateBlock(NORMAL_BLOCK, pos2);
	}

	CreateBlock(NORMAL_BLOCK, VGet(MAP_CHIP_WIDTH, MAP_POS_Y - MAP_CHIP_HEIGHT, 0.0f));

	SpawnGimmick(GIMMICK_TREE_POS_X, GIMMICK_TREE_POS_Y, GIMMICK_TYPE_TREE);

	//SpawnGimmick(GIMMICK_AIRBALLOON_POS_X, GIMMICK_AIRBALLOON_POS_Y, GIMMICK_TYPE_AIRBALLOON);

	//SpawnGimmick(GIMMICK_WOODBLOCK_POS_X, GIMMICK_WOODBLOCK_POS_Y, GIMMICK_TYPE_WOODBLOCK);
	SpawnGimmick(GIMMICK_AIRBALLOON_POS_X, GIMMICK_AIRBALLOON_POS_Y, GIMMICK_TYPE_AIRBALLOON);
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

	DrawPlayer();

	DrawAnimationEffect();

	DrawElementsManager();

	DrawGraph(TEXTPOS_X, TEXTPOS_Y, g_KurosawaData.textHandle, TRUE);
}

void FinKuroScene()
{
	FinMap();

	FinPlayer();

	FinAnimationEffect();

	FinElementsManager();

	DeleteGraph(g_KurosawaData.textHandle);
}