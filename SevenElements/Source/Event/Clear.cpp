#include "DxLib.h"
#include "Clear.h"
#include "EventManager.h"
#include "../Player/Player.h"
#include "../GameSetting/GameSetting.h"

ClearData g_ClearData = { 0 };

void InitClear()
{
	g_ClearData.handle = 0;
	g_ClearData.pos.x = 0.0f;
	g_ClearData.pos.y = 0.0f;
}

void LoadClear()
{
	g_ClearData.handle = LoadGraph("Data/UI/ClearText.png");
}

void StartClear()
{
	g_ClearData.pos.x = SLIDE_TEXT_POS_X;
	g_ClearData.pos.y = SLIDE_TEXT_POS_Y;
}

void UpdateClear()
{
	PlayerData player = GetPlayer();
	if (player.clear && g_ClearData.pos.y < (SCREEN_HEIGHT - CLEAR_TEXT_HEIGHT) / 2)
	{
		g_ClearData.pos.y += SLIDE_TEXT_MOVE_Y;
	}

}

void DrawClear()
{
	DrawGraph((int)g_ClearData.pos.x, (int)g_ClearData.pos.y, g_ClearData.handle, TRUE);
}

void FinClear()
{
	DeleteGraph(g_ClearData.handle);
}