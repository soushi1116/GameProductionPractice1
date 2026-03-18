#include "DxLib.h"
#include "Stage1.h"
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
#include "../../Gimmick/FireGimmick.h"

#define TEXTPOS_X (200)
#define TEXTPOS_Y (0)
#define BLOCK_NUM_MAX (32)
#define MAP_POS_Y (700)
#define GIMMICK_TREE_POS_X (600)
#define GIMMICK_TREE_POS_Y (650)
#define GIMMICK_FIRE_POS_X (1550)
#define GIMMICK_FIRE_POS_Y (925)
#define GIMMICK_AIRBALLOON_POS_X (3400)
#define GIMMICK_AIRBALLOON_POS_Y (700)
#define PLAYER_SPAWN_POS_X (200.0f)
#define PLAYER_SPAWN_POS_Y (600.0f)

void InitStage1()
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

void LoadStage1()
{
	LoadPlayer();

	LoadAnimationEffect();

	LoadElementsManager();

	LoadGimmickManager();

	LoadEventManager();

	LoadMap(1);

	LoadLife();

	LoadUIImage();
}

void StartStage1()
{
	//StartPlayer();
	SpawnPlayer(PLAYER_SPAWN_POS_X, PLAYER_SPAWN_POS_Y, 1);

	StartElementsManager();

	StartGimmickManager();

	SpawnGimmick(GIMMICK_TREE_POS_X, GIMMICK_TREE_POS_Y, GIMMICK_TYPE_TREE);

	for (int i = 0; i < 15; i++)
	{
		if (i > 2 && i < 6)
		{
			SpawnGimmick(GIMMICK_FIRE_POS_X + FIREGIMMICK_WIDTH * i, GIMMICK_FIRE_POS_Y - 100, GIMMICK_TYPE_FIRE);
		}
		else
		{
			SpawnGimmick(GIMMICK_FIRE_POS_X + FIREGIMMICK_WIDTH * i, GIMMICK_FIRE_POS_Y, GIMMICK_TYPE_FIRE);
		}
	}

	SpawnGimmick(GIMMICK_AIRBALLOON_POS_X, GIMMICK_AIRBALLOON_POS_Y, GIMMICK_TYPE_AIRBALLOON);

	SpawnGimmick(MAP_CHIP_WIDTH * 24, MAP_CHIP_HEIGHT * 17, GIMMICK_TYPE_WARP);

	SpawnGimmick(MAP_CHIP_WIDTH * 50, MAP_CHIP_HEIGHT * 17, GIMMICK_TYPE_WARP);

	SpawnGimmick(MAP_CHIP_WIDTH * 76, MAP_CHIP_HEIGHT * 4, GIMMICK_TYPE_GOAL);

	StartMap();

	StartLife();

	//CreateUIImage(UI_IMAGE_LIFETEXT, 30.0f, 50.0f);

	StartEventManager();

	PlayBGM(BGM_PLAY);
}

void StepStage1()
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

void UpdateStage1()
{
	UpdatePlayer();

	UpdateEventManager();

	UpdateGimmickManager();

	UpdateAnimationEffect();

	UpdateElementsManager();

	CheckCollision();
}

void DrawStage1()
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

void FinStage1()
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