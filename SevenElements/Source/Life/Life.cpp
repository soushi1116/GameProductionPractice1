#include "DxLib.h"
#include "Life.h"
#include "../Player/Player.h"

#define LIFE_DEFAULT_POS_X (200)
#define LIFE_DEFAULT_POS_Y (50)
#define LIFE_POS_X_DIF (60)

LifeData g_LifeData[PLAYER_LIFE_MAX] = { 0 };
int g_LifeHandle = 0;

void InitLife()
{
	LifeData* life = g_LifeData;
	for (int i = 0; i < PLAYER_LIFE_MAX; i++, life++)
	{
		life->pos.x = 0.0f;
		life->pos.y = 0.0f;
		life->active = false;
	}
}

void LoadLife()
{
	g_LifeHandle = LoadGraph("Data/UI/Heart.png");
}

void StartLife()
{
	LifeData* life = g_LifeData;
	for (int i = 0; i < PLAYER_LIFE_MAX; i++, life++)
	{
		life->pos.x = LIFE_DEFAULT_POS_X + LIFE_POS_X_DIF * i;
		life->pos.y = LIFE_DEFAULT_POS_Y;
	}
}

void DrawLife()
{
	/*PlayerData player = GetPlayer();
	LifeData* life = g_LifeData;
	for (int i = 0; i < player.life; i++, life++)
	{
		DrawGraph(life->pos.x, life->pos.y, g_LifeHandle, TRUE);
	}*/
}

void FinLife()
{
	DeleteGraph(g_LifeHandle);
}