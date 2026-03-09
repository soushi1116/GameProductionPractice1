#pragma once
#include "DxLib.h"

#define CLEAR_TEXT_WIDTH (500)
#define CLEAR_TEXT_HEIGHT (64)

struct ClearData
{
	VECTOR pos;
	int handle;
};

void InitClear();
void LoadClear();
void StartClear();
void UpdateClear();
void DrawClear();
void FinClear();