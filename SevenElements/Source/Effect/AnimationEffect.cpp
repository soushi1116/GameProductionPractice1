#include "DxLib.h"
#include "AnimationEffect.h"
#include "AnimationEffectParameter.h"

#define ANIMATION_EFFECT_MAX (255)

struct AnimationEffectData
{
	bool active;
	int handle;
	int nowFrame;
	int frameNum;
	int frameWidth;
	int frameHeight;
	int timer;
	int interval;
	VECTOR pos;
};

AnimationEffectData g_AnimationEffectData[ANIMATION_EFFECT_MAX] = { 0 };

int g_AnimationEffectHandle[ANIMATION_EFFECT_TYPE_MAX];

void InitAnimationEffect()
{
	AnimationEffectData* effect = g_AnimationEffectData;
	for (int i = 0; i < ANIMATION_EFFECT_MAX; i++, effect++)
	{
		effect->active = false;
		effect->handle = 0;
		effect->nowFrame = 0;
		effect->frameNum = 0;
		effect->frameWidth = 0;
		effect->frameHeight = 0;
		effect->timer = 0;
		effect->interval = 0;
		effect->pos.x = 0.0f;
		effect->pos.y = 0.0f;
	}
}

void LoadAnimationEffect()
{
	g_AnimationEffectHandle[ELEMENT_FIRE] = LoadGraph("Data/Effect/FireAnimation(pre).png");
}

void StepAnimationEffect()
{
	AnimationEffectData* effect = g_AnimationEffectData;
	for (int i = 0; i < ANIMATION_EFFECT_MAX; i++, effect++)
	{
		if (!effect->active) continue;

		if (effect->timer <= 0)
		{
			effect->nowFrame++;
			effect->timer = effect->interval;

			if (effect->nowFrame >= effect->frameNum)
			{
				effect->active = false;

				continue;
			}
		}
		effect->timer--;
	}
}
void UpdateAnimationEffect()
{

}

void DrawAnimationEffect()
{
	AnimationEffectData* effect = g_AnimationEffectData;
	for (int i = 0; i < ANIMATION_EFFECT_MAX; i++, effect++)
	{
		if (!effect->active) continue;

		int frameX = effect->frameWidth * effect->nowFrame;

		DrawRectGraph((int)effect->pos.x, (int)effect->pos.y, frameX, 0,
			effect->frameWidth, effect->frameHeight, effect->handle, TRUE);
	}
}

void FinAnimationEffect()
{
	for (int i = 0; i < ANIMATION_EFFECT_TYPE_MAX; i++)
	{
		DeleteGraph(g_AnimationEffectHandle[i]);
	}
}

void StartAnimationEffect(AnimationEffectType type, float posX, float posY, int interval)
{
	AnimationEffectMasterParameter param = ANIM_EFFECT_MASTER_PARAM[type];

	AnimationEffectData* effect = g_AnimationEffectData;
	for (int i = 0; i < ANIMATION_EFFECT_MAX; i++, effect++)
	{
		if (!effect->active)
		{
			effect->active = true;

			effect->pos.x = posX;
			effect->pos.y = posY;

			effect->interval = interval;

			effect->timer = effect->interval;

			effect->handle = g_AnimationEffectHandle[type];

			effect->nowFrame = 0;

			effect->frameNum = param.frameNum;

			effect->frameWidth = param.frameWidth;
			effect->frameHeight = param.frameHeight;

			break;
		}
	}
}