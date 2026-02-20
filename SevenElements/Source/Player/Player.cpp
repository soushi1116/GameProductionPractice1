#include "DxLib.h"
#include "Player.h"
#include "../Input/Input.h"

#define PLAYER_MOVE_SPEED (5.0f)
#define PLAYER_DEFAULT_POS_X (800)
#define PLAYER_DEFAULT_POS_Y (450)
#define PLAYER_POS_Y_MIN (800)
#define GRAVITY (0.5f)
#define PLAYER_JUMP_POWER (10.0f)
#define PLAYER_DEFAULT_LEVEL (1)
#define ELEMENTS_TEXT_DIF (128.0f)
#define ELEMENTS_NUM_MAX (7)

PlayerData g_PlayerData = { 0 };

int elementsTextHandle[] = { 0 };

void InitPlayer()
{
	g_PlayerData.pos.x = 0.0f;
	g_PlayerData.pos.y = 0.0f;

	g_PlayerData.move.x = 0.0f;
	g_PlayerData.move.y = 0.0f;

	g_PlayerData.playerHandle = 0;
	g_PlayerData.fireTextHandle = 0;
	g_PlayerData.waterTextHandle = 0;
	g_PlayerData.thunderTextHandle = 0;
	g_PlayerData.windTextHandle = 0;
	g_PlayerData.groundTextHandle = 0;
	g_PlayerData.iceTextHandle = 0;
	g_PlayerData.ironTextHandle = 0;

	for (int i = 0; i < ELEMENTS_NUM_MAX; i ++)
	{
		elementsTextHandle[i] = { 0 };
	}

	g_PlayerData.level = 0;

	g_PlayerData.active = false;
	g_PlayerData.randing = false;
	g_PlayerData.selectElements = false;
}

void LoadPlayer()
{
	g_PlayerData.playerHandle = LoadGraph("Data/Player/Player(‰¼).png");
	/*g_PlayerData.fireTextHandle = LoadGraph("Data/Player/‰Î(‰¼).png");
	g_PlayerData.waterTextHandle = LoadGraph("Data/Player/…(‰¼).png");
	g_PlayerData.thunderTextHandle = LoadGraph("Data/Player/—‹(‰¼).png");
	g_PlayerData.windTextHandle = LoadGraph("Data/Player/•—(‰¼).png");
	g_PlayerData.groundTextHandle = LoadGraph("Data/Player/“y(‰¼).png");
	g_PlayerData.iceTextHandle = LoadGraph("Data/Player/•X(‰¼).png");
	g_PlayerData.ironTextHandle = LoadGraph("Data/Player/‹à‘®(‰¼).png");*/

	for (int i = 0; i < ELEMENTS_NUM_MAX; i++)
	{
		switch (i)
		{
		case 0:
			elementsTextHandle[i] = LoadGraph("Data/Player/‰Î(‰¼).png");
			break;
		case 1:
			elementsTextHandle[i] = LoadGraph("Data/Player/…(‰¼).png");
			break;
		case 2:
			elementsTextHandle[i] = LoadGraph("Data/Player/—‹(‰¼).png");
			break;
		case 3:
			elementsTextHandle[i] = LoadGraph("Data/Player/•—(‰¼).png");
			break;
		case 4:
			elementsTextHandle[i] = LoadGraph("Data/Player/“y(‰¼).png");
			break;
		case 5:
			elementsTextHandle[i] = LoadGraph("Data/Player/•X(‰¼).png");
			break;
		case 6:
			elementsTextHandle[i] = LoadGraph("Data/Player/‹à‘®(‰¼).png");
			break;
		default:
			break;
		}
	}
}

void StartPlayer()
{
	g_PlayerData.active = true;
	g_PlayerData.pos.x = PLAYER_DEFAULT_POS_X;
	g_PlayerData.pos.y = PLAYER_DEFAULT_POS_Y;
	g_PlayerData.level = PLAYER_DEFAULT_LEVEL;
}

void StepPlayer()
{
	if (!g_PlayerData.active) return;

	if (g_PlayerData.pos.y < PLAYER_POS_Y_MIN)
	{
		g_PlayerData.move.y += GRAVITY;
		g_PlayerData.randing = false;
	}
	else
	{
		g_PlayerData.randing = true;
		g_PlayerData.move.y = 0;
	}

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

	if (IsTriggerKey(KEY_UP))
	{
		if (g_PlayerData.randing = true)
		{
			g_PlayerData.move.y -= PLAYER_JUMP_POWER;
		}
	}
	if (IsTriggerKey(KEY_X))
	{
		if (!g_PlayerData.selectElements)
		{
			g_PlayerData.selectElements = true;
		}
		else
		{
			g_PlayerData.selectElements = false;
		}
	}
}

void UpdatePlayer()
{
	if (!g_PlayerData.active) return;

	g_PlayerData.pos.x += g_PlayerData.move.x;
	g_PlayerData.pos.y += g_PlayerData.move.y;
}

void DrawPlayer()
{
	if (!g_PlayerData.active) return;

	DrawGraph(g_PlayerData.pos.x, g_PlayerData.pos.y, g_PlayerData.playerHandle, TRUE);

	if (g_PlayerData.selectElements)
	{
		int playerCenterX = (int)g_PlayerData.pos.x + PLAYER_WIDTH / 2;
		int playerCenterY = (int)g_PlayerData.pos.y + PLAYER_HEIGHT / 2;

		DrawRotaGraph(playerCenterX, playerCenterY - ELEMENTS_TEXT_DIF, 1, 0, elementsTextHandle[0], TRUE);
		DrawRotaGraph(playerCenterX, playerCenterY + ELEMENTS_TEXT_DIF, 1, 0, elementsTextHandle[1], TRUE);
	}
}

void FinPlayer()
{
	DeleteGraph(g_PlayerData.playerHandle);
	DeleteGraph(g_PlayerData.fireTextHandle);
}


PlayerData GetPlayer()
{
	return g_PlayerData;
}

void PlayerHitMap()
{

}