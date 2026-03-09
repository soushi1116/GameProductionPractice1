#pragma once
#include "DxLib.h"

#define DIED_TEXT_WIDTH (500)
#define DIED_TEXT_HEIGHT (74)

struct DieData
{
	VECTOR pos;
	int handle;
};

void InitDie();
void LoadDie();
void StartDie();
void UpdateDie();
void DrawDie();
void FinDie();