#include "DxLib.h"
#include "Animation.h"

void InitAnimation(AnimationData* animData)
{
	animData->active = false;
	animData->posX = 0.0f;
	animData->posY = 0.0f;
	animData->handle = 0;
}

void UpdateAnimation(AnimationData* animData)
{
	if (!animData->active) return;
}

void DrawAnimation(AnimationData* animData, float posX, float posY)
{
	if (!animData->active) return;

	DrawGraph((int)posX, (int)posY, animData->handle, TRUE);
}

void DrawTurnAnimation(AnimationData* animData, float posX, float posY)
{
	if (!animData->active) return;
	DrawTurnGraph((int)posX, (int)posY, animData->handle, TRUE);
}

void StartAnimation(AnimationData* animData, float posX, float posY)
{
	animData->active = true;

	animData->posX = posX;
	animData->posY = posY;
}
