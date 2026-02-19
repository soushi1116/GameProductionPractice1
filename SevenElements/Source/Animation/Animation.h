#pragma once
#include "DxLib.h"

struct AnimationData
{
	bool active;
	float posX;
	float posY;
	int handle;
};

void InitAnimation(AnimationData* animData);
void UpdateAnimation(AnimationData* animData);
void DrawAnimation(AnimationData* animData, float posX, float posY);
void StartAnimation(AnimationData* animData, float posX, float posY);
