#pragma once
#include "DxLib.h"

struct PlayerData
{
	VECTOR pos;
	VECTOR move;

	int handle;

	bool active;
};

void InitPlayer();
void LoadPlayer();
void StartPlayer();
void StepPlayer();
void UpdatePlayer();
void DrawPlayer();
void FinPlayer();

PlayerData GetPlayer();

