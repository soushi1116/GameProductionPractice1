#include "DxLib.h"
#include "S_Kurosawa.h"
#include "../../Player/Player.h"
#include "../../Effect/AnimationEffect.h"
#include "../../Input/Input.h"
#include"../../Scene/SceneManager.h"
#include "../../Elements/ElementsManager.h"
#include "../../Map/MapManager.h"
#include "../../Collision/Collision.h"

KurosawaData g_KurosawaData = { 0 };

#define TEXTPOS_X (200)
#define TEXTPOS_Y (0)

void InitKuroScene()
{
	InitPlayer();

	InitAnimationEffect();

	InitElementsManager();

	g_KurosawaData.textHandle = 0;

	InitMap();
}

void LoadKuroScene()
{
	LoadPlayer();

	LoadAnimationEffect();

	LoadElementsManager();

	g_KurosawaData.textHandle = LoadGraph("Data/Player/SceneForKurosawa.png");

	LoadMap();
}

void StartKuroScene()
{
	StartPlayer();

	StartElementsManager();

	StartMap();
}

void StepKuroScene()
{
	StepPlayer();

	StepAnimationEffect();

	StepElementsManager();

	if (IsTriggerKey(KEY_K))
	{
		ChangeScene(SCENE_TITLE);
	}
}

void UpdateKuroScene()
{
	UpdatePlayer();

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

	DrawGraph(TEXTPOS_X, TEXTPOS_Y, g_KurosawaData.textHandle, TRUE);
}

void FinKuroScene()
{
	FinMap();

	FinPlayer();

	FinAnimationEffect();

	FinElementsManager();

	DeleteGraph(g_KurosawaData.textHandle);
}