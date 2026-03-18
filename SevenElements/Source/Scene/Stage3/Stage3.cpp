#include "DxLib.h"
#include "Stage3.h"
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
#define GIMMICK_FIRE_POS_X (350)
#define GIMMICK_FIRE_POS_Y (1075)
#define GIMMICK_WINDMILL_POS_X (1600)
#define GIMMICK_WINDMILL_POS_Y (750)
#define GIMMICK_MOVEBLOCK_POS_X (2000)
#define GIMMICK_MOVEBLOCK_POS_Y (750)
#define PLAYER_SPAWN_POS_X (200.0f)
#define PLAYER_SPAWN_POS_Y (600.0f)

void InitStage3()
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

void LoadStage3()
{
	LoadPlayer();

	LoadAnimationEffect();

	LoadElementsManager();

	LoadGimmickManager();

	LoadEventManager();

	LoadMap(3);

	LoadLife();

	LoadUIImage();
}

void StartStage3()
{
	//StartPlayer();
	SpawnPlayer(PLAYER_SPAWN_POS_X, PLAYER_SPAWN_POS_Y, 3);

	StartElementsManager();

	StartGimmickManager();

	for (int i = 0; i < 12; i++)
	{
		SpawnGimmick(GIMMICK_FIRE_POS_X + i * 50, GIMMICK_FIRE_POS_Y, GIMMICK_TYPE_FIRE);
	}

	SpawnGimmick(GIMMICK_MOVEBLOCK_POS_X, GIMMICK_MOVEBLOCK_POS_Y, GIMMICK_TYPE_MOVEBLOCK);

	SpawnGimmick(GIMMICK_WINDMILL_POS_X, GIMMICK_WINDMILL_POS_Y, GIMMICK_TYPE_WINDMILL);

	SpawnGimmick(MAP_CHIP_WIDTH * 24, MAP_CHIP_HEIGHT * 17, GIMMICK_TYPE_WARP);

	SpawnGimmick(MAP_CHIP_WIDTH * 50, MAP_CHIP_HEIGHT * 8, GIMMICK_TYPE_WARP);

	SpawnGimmick(MAP_CHIP_WIDTH * 76, MAP_CHIP_HEIGHT * 15, GIMMICK_TYPE_GOAL);

	//SpawnGimmick(200, 860, GIMMICK_TYPE_BATTERY);

	StartMap();

	StartLife();

	//CreateUIImage(UI_IMAGE_LIFETEXT, 30.0f, 50.0f);

	StartEventManager();

	PlayBGM(BGM_PLAY);
}

void StepStage3()
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

void UpdateStage3()
{
	UpdatePlayer();

	UpdateEventManager();

	UpdateGimmickManager();

	UpdateAnimationEffect();

	UpdateElementsManager();

	CheckCollision();
}

void DrawStage3()
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

void FinStage3()
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