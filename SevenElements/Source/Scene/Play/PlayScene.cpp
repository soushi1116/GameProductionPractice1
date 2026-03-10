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

	LoadMapChipData();

	LoadBlock();

	CreateMap();

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

	DrawBlock();

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