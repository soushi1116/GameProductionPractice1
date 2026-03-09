#include "DxLib.h"
#include "PlayScene.h"
#include "../../Player/Player.h"
#include "../../Effect/AnimationEffect.h"
#include "../../Input/Input.h"
#include "../../Elements/ElementsManager.h"
#include "../../Map/MapManager.h"
#include "../../Collision/Collision.h"
#include "../../Camera/Camera.h"
#include "../../Warp/Warp.h"
#include "../../Sound/SoundManager.h"
#include "../../UI/UIImage.h"
#include "../../Goal/Goal.h"
#include "../../Life/Life.h"
#include "../../Event/EventManager.h"

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
#define PLAYER_SPAWN_POS_X (100.0f)
#define PLAYER_SPAWN_POS_Y (600.0f)

void InitPlayScene()
{
	InitPlayer();

	InitAnimationEffect();

	InitElementsManager();

	InitMap();

	InitUIImage();

	InitWarp();

	InitGoal();

	InitLife();

	InitEventManager();

	InitCamera();
}

void LoadPlayScene()
{
	LoadPlayer();

	LoadAnimationEffect();

	LoadElementsManager();

	LoadEventManager();

	LoadMap();

	LoadWarp();

	LoadGoal();

	LoadLife();

	LoadUIImage();
}

void StartPlayScene()
{
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

void StepPlayScene()
{
	StepPlayer();

	StepAnimationEffect();

	StepElementsManager();

	StepCamera();
}

void UpdatePlayScene()
{
	UpdatePlayer();

	UpdateEventManager();

	UpdateAnimationEffect();

	UpdateElementsManager();

	CheckCollision();
}

void DrawPlayScene()
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

void FinPlayScene()
{
	FinMap();

	FinWarp();

	FinGoal();

	FinPlayer();

	FinAnimationEffect();

	FinElementsManager();

	FinLife();

	FinEventManager();

	ResetUIImage();

	StopBGM(BGM_PLAY);
}