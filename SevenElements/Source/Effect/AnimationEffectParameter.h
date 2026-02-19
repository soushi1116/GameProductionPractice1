#pragma once

enum AnimationEffectType
{
	ELEMENT_FIRE,
	/*ELEMENT_WATER,
	ELEMENT_THONDER,
	ELEMENT_WIND,
	ELEMENT_GROUND,
	ELEMENT_ICE,
	ELEMENT_IRON,*/
	ANIMATION_EFFECT_TYPE_MAX,
};

struct AnimationEffectMasterParameter
{
	int frameNum;
	int frameWidth;
	int frameHeight;
};

const AnimationEffectMasterParameter
ANIM_EFFECT_MASTER_PARAM[ANIMATION_EFFECT_TYPE_MAX] =
{
	5, 200, 40,
};