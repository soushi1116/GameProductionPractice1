#include "DxLib.h"
#include "TitleScene.h"
#include "../SceneManager.h"
#include "../../Input/Input.h"

void InitTitleScene()
{

}

void LoadTitleScene()
{

}

void StartTitleScene()
{

}

void StepTitleScene()
{
	// Kキーで黒沢用のシーンへ
	if (IsInputKey(KEY_K))
	{
		ChangeScene(SCENE_KUROSAWA);
	}
}

void UpdateTitleScene()
{

}

void DrawTitleScene()
{

}

void FinTitleScene()
{

}