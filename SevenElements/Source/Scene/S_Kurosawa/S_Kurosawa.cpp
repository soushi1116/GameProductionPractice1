#include "DxLib.h"
#include "S_Kurosawa.h"
#include "../Play/PlayScene.h"
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
#include "../../Life/Life.h"
#include "../../Event/EventManager.h"
#include "../../Goal/Goal.h"

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
#define PLAYER_SPAWN_POS_X (2000.0f)
#define PLAYER_SPAWN_POS_Y (600.0f)

void InitKuroScene()
{
	InitPlayer();

	InitAnimationEffect();

	InitElementsManager();

	g_KurosawaData.textHandle = 0;

	InitMap();

	InitUIImage();

	InitWarp();

	InitGoal();

	InitLife();

	InitEventManager();

	InitCamera();
}

void LoadKuroScene()
{
	LoadPlayer();

	LoadAnimationEffect();

	LoadElementsManager();

	g_KurosawaData.textHandle = LoadGraph("Data/Player/SceneForKurosawa.png");

	LoadEventManager();

	LoadMap();

	LoadWarp();

	LoadGoal();

	LoadLife();

	LoadUIImage();
}

void StartKuroScene()
{
	//StartPlayer();
	SpawnPlayer(PLAYER_SPAWN_POS_X, PLAYER_SPAWN_POS_Y);

	StartElementsManager();

	CreateWarp(MAP_CHIP_WIDTH * 24, MAP_CHIP_HEIGHT * 17);
	CreateWarp(MAP_CHIP_WIDTH * 50, MAP_CHIP_HEIGHT * 17);

	CreateGoal(MAP_CHIP_WIDTH * 76, MAP_CHIP_HEIGHT * 15);

	StartMap();

	StartLife();

	CreateUIImage(UI_IMAGE_LIFETEXT, 30.0f, 50.0f);

	StartEventManager();

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

	UpdateEventManager();

	UpdateAnimationEffect();

	UpdateElementsManager();

	CheckCollision();
}

void DrawKuroScene()
{
	DrawMap();

	DrawWarp();

	DrawGoal();

	DrawPlayer();

	DrawAnimationEffect();

	DrawElementsManager();

	DrawEventManager();

	DrawUIImage();

	DrawLife();

	DrawCamera();
}

void FinKuroScene()
{
	FinMap();

	FinWarp();

	FinGoal();

	FinPlayer();

	FinAnimationEffect();

	FinElementsManager();

	DeleteGraph(g_KurosawaData.textHandle);

	FinLife();

	FinEventManager();

	ResetUIImage();

	StopBGM(BGM_PLAY);
}