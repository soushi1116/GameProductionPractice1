#pragma once
#include "DxLib.h"

struct LifeData
{
	VECTOR pos;
	bool active;
};

void InitLife();
void LoadLife();
void StartLife();
void DrawLife();
void FinLife();