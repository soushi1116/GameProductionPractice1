#include "SceneManager.h"
#include "Title/TitleScene.h"
#include "Option/OptionScene.h"
#include "Play/PlayScene.h"
#include "Stage1/Stage1.h"
#include "Stage2/Stage2.h"
#include "Stage3/Stage3.h"

int g_NowScene = SCENE_TITLE;

int g_NextScene = SCENE_TITLE;

int g_SceneState = SCENE_STATE_INIT;

bool g_IsLoopEnd = false;

TitleScene* title = nullptr;

void SceneManagerUpdate()
{
	switch (g_SceneState)
	{
	case SCENE_STATE_INIT:

		InitScene();
		g_SceneState = SCENE_STATE_LOAD;

		break;

	case SCENE_STATE_LOAD:

		LoadScene();
		g_IsLoopEnd = false;
		g_SceneState = SCENE_STATE_START;

		break;

	case SCENE_STATE_START:

		StartScene();
		g_SceneState = SCENE_STATE_LOOP;

		break;
	case SCENE_STATE_LOOP:

		StepScene();
		UpdateScene();
		DrawScene();
		if (g_IsLoopEnd)
		{
			g_SceneState = SCENE_STATE_FIN;
		}

		break;
	case SCENE_STATE_FIN:

		FinScene();
		g_NowScene = g_NextScene;
		g_SceneState = SCENE_STATE_INIT;

		break;

	default:
		break;
	}
}

void InitScene()
{
	switch (g_NowScene)
	{
	case SCENE_NONE:
		break;
	case SCENE_TITLE:
		title = new TitleScene;
		break;
	case SCENE_OPTION:
		InitOptionScene();
		break;
	case SCENE_STAGE_1:
		InitStage1();
		break;
	case SCENE_STAGE_2:
		InitStage2();
		break;
	case SCENE_STAGE_3:
		InitStage3();
		break;
	case SCENE_STAGE_CLEAR:
		break;
	default:
		break;
	}
}

void LoadScene()
{
	switch (g_NowScene)
	{
	case SCENE_NONE:
		break;
	case SCENE_TITLE:
		title->LoadTitleScene();
		break;
	case SCENE_OPTION:
		LoadOptionScene();
		break;
	case SCENE_STAGE_1:
		LoadStage1();
		break;
	case SCENE_STAGE_2:
		LoadStage2();
		break;
	case SCENE_STAGE_3:
		LoadStage3();
		break;
	case SCENE_STAGE_CLEAR:
		break;
	default:
		break;
	}
}

void StartScene()
{
	switch (g_NowScene)
	{
	case SCENE_NONE:
		break;
	case SCENE_TITLE:
		title->StartTitleScene();
		break;
	case SCENE_OPTION:
		StartOptionScene();
		break;
	case SCENE_STAGE_1:
		StartStage1();
		break;
	case SCENE_STAGE_2:
		StartStage2();
		break;
	case SCENE_STAGE_3:
		StartStage3();
		break;
	case SCENE_STAGE_CLEAR:
		break;
	default:
		break;
	}
}

void StepScene()
{
	switch (g_NowScene)
	{
	case SCENE_NONE:
		break;
	case SCENE_TITLE:
		title->StepTitleScene();
		break;
	case SCENE_OPTION:
		StepOptionScene();
		break;
	case SCENE_STAGE_1:
		StepStage1();
		break;
	case SCENE_STAGE_2:
		StepStage2();
		break;
	case SCENE_STAGE_3:
		StepStage3();
		break;
	case SCENE_STAGE_CLEAR:
		break;
	default:
		break;
	}
}

void UpdateScene()
{
	switch (g_NowScene)
	{
	case SCENE_NONE:
		break;
	case SCENE_TITLE:
		title->UpdateTitleScene();
		break;
	case SCENE_OPTION:
		UpdateOptionScene();
		break;
	case SCENE_STAGE_1:
		UpdateStage1();
		break;
	case SCENE_STAGE_2:
		UpdateStage2();
		break;
	case SCENE_STAGE_3:
		UpdateStage3();
		break;
	case SCENE_STAGE_CLEAR:
		break;
	default:
		break;
	}
}

void DrawScene()
{
	switch (g_NowScene)
	{
	case SCENE_NONE:
		break;
	case SCENE_TITLE:
		title->DrawTitleScene();
		break;
	case SCENE_OPTION:
		DrawOptionScene();
		break;
	case SCENE_STAGE_1:
		DrawStage1();
		break;
	case SCENE_STAGE_2:
		DrawStage2();
		break;
	case SCENE_STAGE_3:
		DrawStage3();
		break;
	case SCENE_STAGE_CLEAR:
		break;
	default:
		break;
	}
}

void FinScene()
{
	switch (g_NowScene)
	{
	case SCENE_NONE:
		break;
	case SCENE_TITLE:
		//delete title;
		break;
	case SCENE_OPTION:
		FinOptionScene();
		break;
	case SCENE_STAGE_1:
		FinStage1();
		break;
	case SCENE_STAGE_2:
		FinStage2();
		break;
	case SCENE_STAGE_3:
		FinStage3();
		break;
	case SCENE_STAGE_CLEAR:
		break;
	default:
		break;
	}
}

void ChangeScene(Scene scene)
{
	g_NextScene = scene;
	g_IsLoopEnd = true;
}