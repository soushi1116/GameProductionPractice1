#pragma once
#include "DxLib.h"
#include "Elements.h"
#include "../Animation/Animation.h"

#define WATER_MAX 32
#define WATER_WIDTH (479)
#define WATER_HEIGHT (32)

enum WaterAnimationType
{
	WATER_ANIM_1,
	WATER_ANIM_2,
	WATER_ANIM_3,
	WATER_ANIM_FREEZE,
	WATER_ANIM_MAX,
	WATER_ANIM_NONE = -1
};

class Water : public Element
{
public:
	Water();
	~Water();

public:
	void Load() override;
	void Start() override;
	void Step() override;
	void Update() override;
	void Draw() override;

	void Spawn(float posX, float posY, bool isTurn);

	void StartWaterAnimation(WaterAnimationType anim);
	void UpdateWaterAnimation();

	void WaterHitIce();

	const bool IsActive();

	VECTOR GetPos();

protected:
	bool m_IsAir;
	bool m_Freeze;
	int m_AnimTimer;
	AnimationData animation[WATER_ANIM_MAX];
	WaterAnimationType waterAnim;
};
