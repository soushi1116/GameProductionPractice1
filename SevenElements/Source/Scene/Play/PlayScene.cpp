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

void InitPlayScene()
{
	InitCamera();

	InitMap();

	InitPlayer();

	InitAnimationEffect();

	InitElementsManager();

	InitGimmickManager();
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

	LoadGimmickManager();
}

void StartPlayScene()
{
	StartMap();

	StartPlayer();

	StartElementsManager();

	StartGimmickManager();
}

void StepPlayScene()
{
	StepCamera();

	StepPlayer();

	StepAnimationEffect();

	StepElementsManager();

	StepGimmickManager();
}

void UpdatePlayScene()
{
	UpdatePlayer();

	UpdateAnimationEffect();

	UpdateElementsManager();

	UpdateGimmickManager();

	CheckCollision();
}

void DrawPlayScene()
{
	DrawMap();

	DrawPlayer();

	DrawAnimationEffect();

	DrawElementsManager();

	DrawGimmickManager();
}

void FinPlayScene()
{
	FinMap();

	FinPlayer();

	FinAnimationEffect();

	FinElementsManager();

	FinGimmickManager();
}