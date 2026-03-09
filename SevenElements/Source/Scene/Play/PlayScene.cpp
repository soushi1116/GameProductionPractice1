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
#include "../Enemy/EnemyScene.h"

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
#define SLIDE_TEXT_MOVE_Y (10.0f)

void InitPlayScene()
{
	InitMap();

	InitPlayer();

	InitEnemyManager();

	InitAnimationEffect();

	InitElementsManager();

	InitCamera();

	InitWarp();
}

void LoadPlayScene()
{
	LoadMap();

	LoadPlayer();

	LoadEnemyManager();

	LoadWarp();

	LoadAnimationEffect();

	LoadElementsManager();
}

void StartPlayScene()
{
	StartMap();

	StartPlayer();

	StartEnemyManager();

	StartElementsManager();

	CreateWarp(MAP_CHIP_WIDTH * 24, MAP_CHIP_HEIGHT * 17);
	CreateWarp(MAP_CHIP_WIDTH * 50, MAP_CHIP_HEIGHT * 17);

	PlayBGM(BGM_PLAY);
}

void StepPlayScene()
{
	StepPlayer();

	StepEnemyManager();

	StepAnimationEffect();

	StepElementsManager();

	StepCamera();
}

void UpdatePlayScene()
{
	UpdatePlayer();

	UpdateEnemyManager();

	UpdateAnimationEffect();

	UpdateElementsManager();

	CheckCollision();
}

void DrawPlayScene()
{
	DrawMap();

	DrawWarp();

	DrawPlayer();

	DrawEnemyManager();

	DrawAnimationEffect();

	DrawElementsManager();

	DrawCamera();
}

void FinPlayScene()
{
	FinMap();

	FinPlayer();

	FinEnemyManager();

	FinWarp();

	FinAnimationEffect();

	FinElementsManager();
}