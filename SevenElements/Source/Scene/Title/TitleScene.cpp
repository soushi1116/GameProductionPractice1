#include "DxLib.h"
#include "TitleScene.h"
#include "../SceneManager.h"

extern SceneManager sceneManager;

TitleScene::TitleScene()
{

}

TitleScene::~TitleScene()
{
	DeleteGraph(m_logoHandle);
}

void TitleScene::LoadTitleScene()
{
	m_logoHandle = LoadGraph("");
}

void TitleScene::StartTitleScene()
{
	m_select = 0;
}

void TitleScene::StepTitleScene()
{

}

void TitleScene::UpdateTitleScene()
{
	if (CheckHitKey(KEY_INPUT_UP))
	{
		m_select--;
		if (m_select < 0) m_select = 2;
	}

	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		m_select--;
		if (m_select > 2) m_select = 0;
	}

	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		switch (m_select)
		{
		case 0:
			sceneManager.ChangeScene(SCENE_STAGE_1);
			break;
		case 1:
			sceneManager.ChangeScene(SCENE_OPTION);
		}
	}
}

void TitleScene::DrawTitleScene()
{
	DrawGraph(0, 0, m_logoHandle, TRUE);

	DrawString(300, 200, "‚Í‚¶‚ß‚©‚ç", GetColor(255, 255, 255));
	DrawString(300, 240, "‚Â‚Ã‚«‚©‚ç", GetColor(255, 255, 255));
	DrawString(300, 280, "ƒIƒvƒVƒ‡ƒ“", GetColor(255, 255, 255));

	DrawString(260, 200 + m_select * 40, ">", GetColor(255, 255, 0));
}