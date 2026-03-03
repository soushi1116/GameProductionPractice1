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

void InitPlayScene()
{
	InitMap();

	InitPlayer();

	InitAnimationEffect();

	InitElementsManager();

	InitCamera();

	InitWarp();
}

void LoadPlayScene()
{
	LoadMap();

	LoadPlayer();

	LoadWarp();

	LoadAnimationEffect();

	LoadElementsManager();
}

void StartPlayScene()
{
	StartMap();

	StartPlayer();

	StartElementsManager();

	CreateWarp(MAP_CHIP_WIDTH * 24, MAP_CHIP_HEIGHT * 17);
	CreateWarp(MAP_CHIP_WIDTH * 50, MAP_CHIP_HEIGHT * 17);
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

	UpdateAnimationEffect();

	UpdateElementsManager();

	CheckCollision();
}

void DrawPlayScene()
{
	DrawMap();

	DrawWarp();

	DrawPlayer();

	DrawAnimationEffect();

	DrawElementsManager();

	DrawCamera();
}

void FinPlayScene()
{
	FinMap();

	FinPlayer();

	FinWarp();

	FinAnimationEffect();

	FinElementsManager();
}