#include "DxLib.h"
#include "PlayScene.h"
#include "../../Player/Player.h"
#include "../../Effect/AnimationEffect.h"
#include "../../Input/Input.h"
#include "../../Elements/ElementsManager.h"
#include "../../Map/MapManager.h"
#include "../../Collision/Collision.h"
#include "../../Map/MapChip.h"
#include "../../Map/Block.h"
#include "../../Gimmick/GimmickManager.h"
#include "../../Camera/Camera.h"
<<<<<<< HEAD
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
=======
>>>>>>> 8555fa8b2e3c531c8b1408490f7cec7976a22046

void InitPlayScene()
{
	InitCamera();

	InitMap();

	InitPlayer();

	InitEnemyManager();

	InitAnimationEffect();

	InitElementsManager();

	InitGimmickManager();
}

void LoadPlayScene()
{
	LoadMap();

	LoadMapChipData();

<<<<<<< HEAD
	LoadEnemyManager();

	LoadWarp();
=======
	LoadBlock();

	CreateMap();

	LoadPlayer();
>>>>>>> 8555fa8b2e3c531c8b1408490f7cec7976a22046

	LoadAnimationEffect();

	LoadElementsManager();

	LoadGimmickManager();
}

void StartPlayScene()
{
	StartMap();

	StartPlayer();

	StartEnemyManager();

	StartElementsManager();

	StartGimmickManager();
}

void StepPlayScene()
{
	StepCamera();

	StepPlayer();

	StepEnemyManager();

	StepAnimationEffect();

	StepElementsManager();

	StepGimmickManager();
}

void UpdatePlayScene()
{
	UpdatePlayer();

	UpdateEnemyManager();

	UpdateAnimationEffect();

	UpdateElementsManager();

	UpdateGimmickManager();

	CheckCollision();
}

void DrawPlayScene()
{
	DrawMap();

	DrawPlayer();

	DrawEnemyManager();

	DrawAnimationEffect();

	DrawElementsManager();

	DrawGimmickManager();
}

void FinPlayScene()
{
	FinMap();

	FinPlayer();

<<<<<<< HEAD
	FinEnemyManager();

	FinWarp();

=======
>>>>>>> 8555fa8b2e3c531c8b1408490f7cec7976a22046
	FinAnimationEffect();

	FinElementsManager();

	FinGimmickManager();
}