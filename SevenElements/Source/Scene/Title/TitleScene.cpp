#include "DxLib.h"
#include "TitleScene.h"
#include "../SceneManager.h"
#include "../../Input/Input.h"

TitleScene::TitleScene()
{
	m_randomIndex = 0;
	m_select = 0;

	for (int i = 0; i < 6; i++)
	{
		m_backHandle[i] = 0;
		m_logoHandle[i] = 0;
	}
}

TitleScene::~TitleScene()
{
}

void TitleScene::LoadTitleScene()
{
	
}

void TitleScene::StartTitleScene()
{
	m_backHandle[0] = LoadGraph("");
	m_logoHandle[0] = LoadGraph("");

	m_backHandle[1] = LoadGraph("");
	m_logoHandle[1] = LoadGraph("");

	m_backHandle[2] = LoadGraph("");
	m_logoHandle[2] = LoadGraph("");
	
	m_backHandle[3] = LoadGraph("");
	m_logoHandle[3] = LoadGraph("");

	m_backHandle[4] = LoadGraph("");
	m_logoHandle[4] = LoadGraph("");

	m_backHandle[5] = LoadGraph("");
	m_logoHandle[5] = LoadGraph("");

	m_randomIndex = rand() % TITLE_PATTERN_MAX;

	m_select = 0;
}

void TitleScene::StepTitleScene()
{
	// Kキーで黒沢用のシーンへ
	if (IsInputKey(KEY_K))
	{
		ChangeScene(SCENE_KUROSAWA);
	}
}

void TitleScene::UpdateTitleScene()
{
	if (IsTriggerKey(KEY_DOWN))
	{
		m_select++;
		if (m_select < 0) m_select = 2;
	}

	if (IsTriggerKey(KEY_UP))
	{
		m_select--;
		if (m_select > 2) m_select = 0;
	}

	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		switch (m_select)
		{
		case 0:
			ChangeScene(SCENE_STAGE_1);
			break;
		case 1:
			ChangeScene(SCENE_OPTION);
			break;
		case 3:
			ChangeScene(SCENE_OPTION);
			break;
		}
	}
}

void TitleScene::DrawTitleScene()
{

	DrawGraph(0, 0, m_backHandle[m_randomIndex], TRUE);
	DrawGraph(300, 100, m_logoHandle[m_randomIndex], TRUE);

	DrawString(300, 400, "はじめから", GetColor(255, 255, 255));
	DrawString(300, 440, "つづきから", GetColor(255, 255, 255));
	DrawString(300, 480, "オプション", GetColor(255, 255, 255));

	DrawString(260, 400 + m_select * 40, ">", GetColor(255, 255, 0));
}