#include "DxLib.h"
#include "Player.h"
#include "../Input/Input.h"

#define PLAYER_MOVE_SPEED (5.0f)

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

}

void StartPlayer()
{
	g_PlayerData.active = true;
}

void StepPlayer()
{

}

void UpdatePlayer()
{

}

void DrawPlayer()
{
	if (!g_PlayerData.active) return;

	DrawGraph(g_PlayerData.pos.x, g_PlayerData.pos.y, g_PlayerData.handle, TRUE);
}

void FinPlayer()
{

}


PlayerData GetPlayer()
{
	return g_PlayerData;
}