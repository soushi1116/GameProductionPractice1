#include "SceneManager.h"
#include "Title/TitleScene.h"

Scene g_NowScene = SCENE_TITLE;

Scene g_NextScene = SCENE_TITLE;

SceneState g_SceneState = SCENE_STATE_INIT;

bool g_IsLoopEnd = false;

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

		g_SceneState = SCENE_STATE_START;
		break;
	case SCENE_STATE_START:
		StartScene();

		g_IsLoopEnd = false;

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
	}
}

void InitScene()
{
	switch (g_NowScene)
	{
	case SCENE_TITLE:
		InitTitleScene();
		break;
	case SCENE_PLAY:
		break;
	case SCENE_OPTION:
		break;
	}
}

void LoadScene()
{
	switch (g_NowScene)
	{
	case SCENE_TITLE:
		LoadTitleScene();
		break;
	case SCENE_PLAY:
		break;
	case SCENE_OPTION:
		break;
	}
}

void StartScene()
{
	switch (g_NowScene)
	{
	case SCENE_TITLE:
		StartTitleScene();
		break;
	case SCENE_PLAY:
		break;
	case SCENE_OPTION:
		break;
	}
}

void StepScene()
{
	switch (g_NowScene)
	{
	case SCENE_TITLE:
		StepTitleScene();
		break;
	case SCENE_PLAY:
		break;
	case SCENE_OPTION:
		break;
	}
}

void UpdateScene()
{
	switch (g_NowScene)
	{
	case SCENE_TITLE:
		UpdateTitleScene();
		break;
	case SCENE_PLAY:
		break;
	case SCENE_OPTION:
		break;
	}
}

void DrawScene()
{
	switch (g_NowScene)
	{
	case SCENE_TITLE:
		DrawTitleScene();
		break;
	case SCENE_PLAY:
		break;
	case SCENE_OPTION:
		break;
	}
}

void FinScene()
{
	switch (g_NowScene)
	{
	case SCENE_TITLE:
		FinTitleScene();
		break;
	case SCENE_PLAY:
		break;
	case SCENE_OPTION:
		break;
	}
}

void ChangeScene(Scene scene)
{
	g_NextScene = scene;

	g_IsLoopEnd = true;
}