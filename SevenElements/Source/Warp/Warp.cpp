#include "Warp.h"
#include "DxLib.h"
#include "../Camera/Camera.h"

WarpData g_WarpData[WARP_MAX] = { 0 };

int g_WarpHandle = 0;

void InitWarp()
{
	WarpData* warp = g_WarpData;
	for (int i = 0; i < WARP_MAX; i++, warp++)
	{
		warp->posX = 0.0f;
		warp->posY = 0.0f;

		warp->handle = 0;

		warp->active = false;
	}
}

void LoadWarp()
{
	g_WarpHandle = LoadGraph("Data/Gimmick/Warp.png");
}

void StartWarp()
{

}

void DrawWarp()
{
	CameraData camera = GetCamera();

	WarpData* warp = g_WarpData;
	for (int i = 0; i < WARP_MAX; i++, warp++)
	{
		if (!warp->active) continue;

		DrawGraph(warp->posX - camera.posX, warp->posY - camera.posY, g_WarpHandle, TRUE);
	}
}

void FinWarp()
{
	DeleteGraph(g_WarpHandle);
}

WarpData* CreateWarp(float posX, float posY)
{
	WarpData* warp = g_WarpData;
	for (int i = 0; i < WARP_MAX; i++, warp++)
	{
		if (!warp->active)
		{
			warp->active = true;

			warp->handle = g_WarpHandle;

			warp->posX = posX;
			warp->posY = posY;

			break;
		}
	}

	return nullptr;
}

WarpData* GetWarp()
{
	return g_WarpData;
}