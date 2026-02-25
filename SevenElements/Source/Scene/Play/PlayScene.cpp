#include "DxLib.h"
#include "PlayScene.h"
#include "../../Player/Player.h"
#include "../../Effect/AnimationEffect.h"
#include "../../Input/Input.h"
#include "../../Elements/ElementsManager.h"
#include "../../Map/MapManager.h"
#include "../../Collision/Collision.h"


void InitPlayScene()
{
	InitMap();

	InitPlayer();

	InitAnimationEffect();

	InitElementsManager();
}

void LoadPlayScene()
{
	LoadMap();

	LoadPlayer();

	LoadAnimationEffect();

	LoadElementsManager();
}

void StartPlayScene()
{
	StartMap();

	StartPlayer();

	StartElementsManager();
}

void StepPlayScene()
{
	StepPlayer();

	StepAnimationEffect();

	StepElementsManager();
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

	DrawPlayer();

	DrawAnimationEffect();

	DrawElementsManager();
}

void FinPlayScene()
{
	FinMap();

	FinPlayer();

	FinAnimationEffect();

	FinElementsManager();
}