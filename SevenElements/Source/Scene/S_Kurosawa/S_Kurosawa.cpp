#include "DxLib.h"
#include "S_Kurosawa.h"
#include "../../Player/Player.h"
#include "../../Effect/AnimationEffect.h"
#include "../../Input/Input.h"
#include"../../Scene/SceneManager.h"
#include "../../Elements/ElementsManager.h"
#include "../../Map/MapManager.h"
#include "../../Collision/Collision.h"
#include "../../Map/Block.h"
#include "../../Map/MapParameter.h"
#include "../../Gimmick/GimmickManager.h"

KurosawaData g_KurosawaData = { 0 };

#define TEXTPOS_X (200)
#define TEXTPOS_Y (0)
#define BLOCK_NUM_MAX (32)
#define MAP_POS_Y (800)
#define GIMMICK_TREE_POS_X (300)
#define GIMMICK_TREE_POS_Y (500)

void InitKuroScene()
{
	InitPlayer();

	InitAnimationEffect();

	InitElementsManager();

	InitGimmickManager();

	g_KurosawaData.textHandle = 0;

	InitMap();
}

void LoadKuroScene()
{
	LoadPlayer();

	LoadAnimationEffect();

	LoadElementsManager();

	LoadGimmickManager();

	g_KurosawaData.textHandle = LoadGraph("Data/Player/SceneForKurosawa.png");

	LoadMap();
}

void StartKuroScene()
{
	StartPlayer();

	StartElementsManager();

	StartGimmickManager();

	StartMap();

	for (int i = 0; i < BLOCK_NUM_MAX; i++)
	{
		VECTOR pos = VGet(MAP_CHIP_WIDTH * i, MAP_POS_Y, 0.0f);

		CreateBlock(NORMAL_BLOCK, pos);
	}

	CreateBlock(NORMAL_BLOCK, VGet(MAP_CHIP_WIDTH, MAP_POS_Y - MAP_CHIP_HEIGHT, 0.0f));

	SpawnGimmick(GIMMICK_TREE_POS_X, GIMMICK_TREE_POS_Y, GIMMICK_TYPE_TREE);
}

void StepKuroScene()
{
	StepPlayer();

	StepAnimationEffect();

	StepElementsManager();

	StepGimmickManager();

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

	UpdateGimmickManager();

	CheckCollision();
}

void DrawKuroScene()
{
	DrawMap();

	DrawAnimationEffect();

	DrawElementsManager();

	DrawGimmickManager();

	DrawGraph(TEXTPOS_X, TEXTPOS_Y, g_KurosawaData.textHandle, TRUE);

	DrawPlayer();
}

void FinKuroScene()
{
	FinMap();

	FinPlayer();

	FinAnimationEffect();

	FinElementsManager();

	FinGimmickManager();

	DeleteGraph(g_KurosawaData.textHandle);
}