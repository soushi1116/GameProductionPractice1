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
#define GIMMICK_TREE_POS_X (300)
#define GIMMICK_TREE_POS_Y (500)
#define GIMMICK_AIRBALLOON_POS_X (1000)
#define GIMMICK_AIRBALLOON_POS_Y (600)
#define GIMMICK_WOODBLOCK_POS_X (300)
#define GIMMICK_WOODBLOCK_POS_Y (750)
#define PLAYER_SPAWN_POS_X (200.0f)
#define PLAYER_SPAWN_POS_Y (600.0f)

void InitKuroScene()
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

void LoadKuroScene()
{
	LoadPlayer();

	LoadAnimationEffect();

	LoadElementsManager();

	LoadGimmickManager();

	LoadEventManager();

	LoadMap();

	LoadLife();

	LoadUIImage();
}

void StartKuroScene()
{
	//StartPlayer();
	SpawnPlayer(PLAYER_SPAWN_POS_X, PLAYER_SPAWN_POS_Y);

	StartElementsManager();

	StartGimmickManager();

	SpawnGimmick(100, 100, GIMMICK_TYPE_AIRBALLOON);

	//SpawnGimmick(600, 900, GIMMICK_TYPE_WOODBLOCK);

	SpawnGimmick(MAP_CHIP_WIDTH * 24, MAP_CHIP_HEIGHT * 17, GIMMICK_TYPE_WARP);

	SpawnGimmick(MAP_CHIP_WIDTH * 50, MAP_CHIP_HEIGHT * 17, GIMMICK_TYPE_WARP);

	SpawnGimmick(MAP_CHIP_WIDTH * 76, MAP_CHIP_HEIGHT * 15, GIMMICK_TYPE_GOAL);

	SpawnGimmick(1000, 750, GIMMICK_TYPE_WINDMILL);

	//SpawnGimmick(1000, 860, GIMMICK_TYPE_BATTERY);

	/*for (int i = 0; i < 10; i++)
	{
		SpawnGimmick(300 + i * 50, 925, GIMMICK_TYPE_FIRE);
	}*/

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

	StepGimmickManager();

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

	UpdateGimmickManager();

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

	DrawGimmickManager();

	DrawEventManager();

	DrawUIImage();

	DrawLife();

	DrawCamera();
}

void FinKuroScene()
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