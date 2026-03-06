#pragma once
#include "DxLib.h"

void InitKuroScene();
void LoadKuroScene();
void StartKuroScene();
void StepKuroScene();
void UpdateKuroScene();
void DrawKuroScene();
void FinKuroScene();

struct KurosawaData
{
	int textHandle;
};

struct LifeData
{
	VECTOR pos;
};