#pragma once
#include "DxLib.h"

#define PLAYER_WIDTH (64)
#define PLAYER_HEIGHT (126)

struct PlayerData
{
	VECTOR pos;
	VECTOR move;

	int playerHandle;
	int level;
	int selectState;

	bool active;
	bool randing;
	bool selectElements;
};

void InitPlayer();
void LoadPlayer();
void StartPlayer();
void StepPlayer();
void UpdatePlayer();
void DrawPlayer();
void FinPlayer();

PlayerData GetPlayer();

void PlayerHitMap();