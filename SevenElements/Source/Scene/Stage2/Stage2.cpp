#include "DxLib.h"
#include "Stage2.h"
#include "../Play/PlayScene.h"
#include "../../Player/Player.h"
#include "../../Effect/AnimationEffect.h"
#include "../../Input/Input.h"
#include"../../Scene/SceneManager.h"
#include "../../Elements/ElementsManager.h"
#include "../../Map/MapManager.h"
#include "../../Collision/Collision.h"
#include "../../Gimmick/Gimmick.h"
#include "../../Gimmick/GimmickManager.h"
#include "../../Map/Block.h"
#include "../../UI/UIImage.h"
#include "../../Sound/SoundManager.h"
#include "../../Camera/Camera.h"
#include "../../Gimmick/Warp.h"
#include "../../GameSetting/GameSetting.h"
#include "../../Life/Life.h"
#include "../../Event/EventManager.h"
#include "../../Gimmick/Goal.h"
#include "../../Enemy/EnemyWalk.h"

#define TEXTPOS_X (200)
#define TEXTPOS_Y (0)
#define BLOCK_NUM_MAX (32)
#define MAP_POS_Y (700)
#define GIMMICK_BATTERY_POS_X (1000)
#define GIMMICK_BATTERY_POS_Y (850)
#define GIMMICK_MOVEBLOCK_POS_X (700)
#define GIMMICK_MOVEBLOCK_POS_Y (450)
#define GIMMICK_WOODBLOCK_POS_X (1800)
#define GIMMICK_WOODBLOCK_POS_Y (900)
#define GIMMICK_NEEDLE_POS_X (3050)
#define GIMMICK_NEEDLE_POS_Y (1000)
#define PLAYER_SPAWN_POS_X (200.0f)
#define PLAYER_SPAWN_POS_Y (600.0f)

void InitStage2()
{
	InitPlayer();

	InitAnimationEffect();

	InitElementsManager();

	InitGimmickManager();

	InitMap();

	InitUIImage();

	InitLife();

	InitEventManager();

	InitCamera();
}

void LoadStage2()
{
	LoadPlayer();

	LoadAnimationEffect();

	LoadElementsManager();

	LoadGimmickManager();

	LoadEventManager();

	LoadMap(2);

	LoadLife();

	LoadUIImage();
}

void StartStage2()
{
	//StartPlayer();
	SpawnPlayer(PLAYER_SPAWN_POS_X, PLAYER_SPAWN_POS_Y, 2);

	StartElementsManager();

	StartGimmickManager();

	SpawnGimmick(GIMMICK_BATTERY_POS_X, GIMMICK_BATTERY_POS_Y, GIMMICK_TYPE_BATTERY);

	SpawnGimmick(GIMMICK_MOVEBLOCK_POS_X, GIMMICK_MOVEBLOCK_POS_Y, GIMMICK_TYPE_MOVEBLOCK);

	SpawnGimmick(GIMMICK_WOODBLOCK_POS_X, GIMMICK_WOODBLOCK_POS_Y, GIMMICK_TYPE_WOODBLOCK);

	for (int i = 0; i < 10; i++)
	{
		SpawnGimmick(GIMMICK_NEEDLE_POS_X + 50 * i, GIMMICK_NEEDLE_POS_Y, GIMMICK_TYPE_NEEDLE);
	}

	SpawnGimmick(MAP_CHIP_WIDTH * 24, MAP_CHIP_HEIGHT * 8, GIMMICK_TYPE_WARP);

	SpawnGimmick(MAP_CHIP_WIDTH * 50, MAP_CHIP_HEIGHT * 17, GIMMICK_TYPE_WARP);

	SpawnGimmick(MAP_CHIP_WIDTH * 76, MAP_CHIP_HEIGHT * 17, GIMMICK_TYPE_GOAL);

	StartMap();

	StartLife();

	//CreateUIImage(UI_IMAGE_LIFETEXT, 30.0f, 50.0f);

	StartEventManager();

	PlayBGM(BGM_PLAY);
}

void StepStage2()
{
	StepPlayer();

	StepAnimationEffect();

	StepElementsManager();

	StepGimmickManager();

	if (IsTriggerKey(KEY_K))
	{
		ChangeScene(SCENE_TITLE);
	}

	StepCamera();
}

void UpdateStage2()
{
	UpdatePlayer();

	UpdateEventManager();

	UpdateGimmickManager();

	UpdateAnimationEffect();

	UpdateElementsManager();

	CheckCollision();
}

void DrawStage2()
{
	DrawMap();

	DrawPlayer();

	DrawAnimationEffect();

	DrawElementsManager();

	DrawGimmickManager();

	DrawEventManager();

	DrawUIImage();

	DrawLife();

	DrawCamera();
}

void FinStage2()
{
	FinMap();

	FinPlayer();

	FinAnimationEffect();

	FinElementsManager();

	FinGimmickManager();

	FinLife();

	FinEventManager();

	ResetUIImage();

	StopBGM(BGM_PLAY);
}