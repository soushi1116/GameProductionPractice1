#pragma once

enum Scene
{
	SCENE_NONE,
	SCENE_TITLE,
	SCENE_OPTION,
	SCENE_STAGE_1,
	SCENE_STAGE_CLEAR,
};

enum SceneState
{
	SCENE_STATE_INIT,
	SCENE_STATE_LOAD,
	SCENE_STATE_START,
	SCENE_STATE_LOOP,
	SCENE_STATE_FIN,
};

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

public:
	void SceneManagerUpdate();

	void InitScene();
	void LoadScene();
	void StartScene();
	void StepScene();
	void UpdateScene();
	void DrawScene();
	void FinScene();

	void ChangeScene(Scene scene);

private:
	Scene g_NowScene;

	Scene g_NextScene;

	SceneState g_SceneState;

	bool g_IsLoopEnd;
};