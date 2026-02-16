#include "DxLib.h"
#include "Player.h"
#include "../Input/Input.h"

#define PLAYER_MOVE_SPEED (5.0f)
#define PLAYER_DEFAULT_POS_X (800)
#define PLAYER_DEFAULT_POS_Y (450)

PlayerData g_PlayerData = { 0 };

void InitPlayer()
{
	g_PlayerData.pos.x = 0.0f;
	g_PlayerData.pos.y = 0.0f;

	g_PlayerData.move.x = 0.0f;
	g_PlayerData.move.y = 0.0f;

	g_PlayerData.handle = 0;

	g_PlayerData.active = false;
}

void LoadPlayer()
{
	g_PlayerData.handle = LoadGraph("Data/Player/Player(‰¼).png");
}

void StartPlayer()
{
	g_PlayerData.active = true;
	g_PlayerData.pos.x = PLAYER_DEFAULT_POS_X;
	g_PlayerData.pos.y = PLAYER_DEFAULT_POS_Y;
}

void StepPlayer()
{
	if (!g_PlayerData.active) return;

	if (IsInputKey(KEY_RIGHT))
	{
		g_PlayerData.move.x = PLAYER_MOVE_SPEED;

	}
	else if (IsInputKey(KEY_LEFT))
	{
		g_PlayerData.move.x = -PLAYER_MOVE_SPEED;

	}
	else
	{
		g_PlayerData.move.x = 0;
	}
}

void UpdatePlayer()
{
	if (!g_PlayerData.active) return;

	g_PlayerData.pos.x += g_PlayerData.move.x;
}

void DrawPlayer()
{
	if (!g_PlayerData.active) return;

	DrawGraph(g_PlayerData.pos.x, g_PlayerData.pos.y, g_PlayerData.handle, TRUE);
}

void FinPlayer()
{
	DeleteGraph(g_PlayerData.handle);
}


PlayerData GetPlayer()
{
	return g_PlayerData;
}