#include "DxLib.h"
#include "Die.h"
#include "EventManager.h"
#include "../Player/Player.h"
#include "../GameSetting/GameSetting.h"


DieData g_DieData = { 0 };

void InitDie()
{
	g_DieData.handle = 0;
	g_DieData.pos.x = 0.0f;
	g_DieData.pos.y = 0.0f;
}

void LoadDie()
{
	g_DieData.handle = LoadGraph("Data/UI/DiedText.png");
}

void StartDie()
{
	g_DieData.pos.x = SLIDE_TEXT_POS_X;
	g_DieData.pos.y = SLIDE_TEXT_POS_Y;
}

void UpdateDie()
{
	PlayerData player = GetPlayer();
	if (player.die && g_DieData.pos.y < (SCREEN_HEIGHT - DIED_TEXT_HEIGHT) / 2)
	{
		g_DieData.pos.y += SLIDE_TEXT_MOVE_Y;
	}

}

void DrawDie()
{
	DrawGraph((int)g_DieData.pos.x, (int)g_DieData.pos.y, g_DieData.handle, TRUE);
}

void FinDie()
{
	DeleteGraph(g_DieData.handle);
}