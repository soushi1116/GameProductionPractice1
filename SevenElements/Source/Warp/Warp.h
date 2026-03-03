#pragma once

#define WARP_MAX (2)

struct WarpData
{
	float posX;
	float posY;

	int handle;

	bool active;
};

void InitWarp();
void LoadWarp();
void StartWarp();
void DrawWarp();
void FinWarp();

WarpData* CreateWarp(float posX, float posY);

WarpData* GetWarp();