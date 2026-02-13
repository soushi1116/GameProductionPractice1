#include "SceneManager.h"
#include "Title/TitleScene.h"
#include "Option/OptionScene.h"
#include "Play/PlayScene.h"

TitleScene* title;
OptionScene* option;
PlayScene* play;

SceneManager::SceneManager()
{
	g_NowScene = SCENE_TITLE;

	g_NextScene = SCENE_TITLE;

	g_SceneState = SCENE_STATE_INIT;

	g_IsLoopEnd = false;
}

void SceneManager::SceneManagerUpdate()
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

void SceneManager::InitScene()
{
	switch (g_NowScene)
	{
	case SCENE_NONE:
		break;
	case SCENE_TITLE:
		title = new TitleScene;
		break;
	case SCENE_OPTION:
		option = new OptionScene;
		break;
	case SCENE_STAGE_1:
		play = new PlayScene;
		break;
	case SCENE_STAGE_CLEAR:
		break;
	default:
		break;
	}
}

void SceneManager::LoadScene()
{
	switch (g_NowScene)
	{
	case SCENE_NONE:
		break;
	case SCENE_TITLE:
		title->LoadTitleScene();
		break;
	case SCENE_OPTION:
		option->LoadOptionScene();
		break;
	case SCENE_STAGE_1:
		play->LoadPlayScene();
		break;
	case SCENE_STAGE_CLEAR:
		break;
	default:
		break;
	}
}

void SceneManager::StartScene()
{
	switch (g_NowScene)
	{
	case SCENE_NONE:
		break;
	case SCENE_TITLE:
		title->StartTitleScene();
		break;
	case SCENE_OPTION:
		option->StartOptionScene();
		break;
	case SCENE_STAGE_1:
		play->StartPlayScene();
		break;
	case SCENE_STAGE_CLEAR:
		break;
	default:
		break;
	}
}

void SceneManager::StepScene()
{
	switch (g_NowScene)
	{
	case SCENE_NONE:
		break;
	case SCENE_TITLE:
		title->StepTitleScene();
		break;
	case SCENE_OPTION:
		option->StepOptionScene();
		break;
	case SCENE_STAGE_1:
		play->StepPlayScene();
		break;
	case SCENE_STAGE_CLEAR:
		break;
	default:
		break;
	}
}

void SceneManager::UpdateScene()
{
	switch (g_NowScene)
	{
	case SCENE_NONE:
		break;
	case SCENE_TITLE:
		title->UpdateTitleScene();
		break;
	case SCENE_OPTION:
		option->UpdateOptionScene();
		break;
	case SCENE_STAGE_1:
		play->UpdatePlayScene();
		break;
	case SCENE_STAGE_CLEAR:
		break;
	default:
		break;
	}
}

void SceneManager::DrawScene()
{
	switch (g_NowScene)
	{
	case SCENE_NONE:
		break;
	case SCENE_TITLE:
		title->DrawTitleScene();
		break;
	case SCENE_OPTION:
		option->DrawOptionScene();
		break;
	case SCENE_STAGE_1:
		play->DrawPlayScene();
		break;
	case SCENE_STAGE_CLEAR:
		break;
	default:
		break;
	}
}

void SceneManager::FinScene()
{
	switch (g_NowScene)
	{
	case SCENE_NONE:
		break;
	case SCENE_TITLE:
		delete title;
		break;
	case SCENE_OPTION:
		delete option;
		break;
	case SCENE_STAGE_1:
		delete play;
		break;
	case SCENE_STAGE_CLEAR:
		break;
	default:
		break;
	}
}

void SceneManager::ChangeScene(Scene scene)
{
	g_NextScene = scene;
	g_IsLoopEnd = false;
}