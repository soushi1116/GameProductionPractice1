#pragma once
#include "DxLib.h"
#include "Elements.h"
#include "../Animation/Animation.h"

#define WATER_MAX 32
#define WATER_WIDTH (448)
#define WATER_HEIGHT (41)

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

	void WaterHitWater(int indexA, int indexB, float posY);
	void WaterHitIce();
	void WaterHitFire();
	void WaterHitBlock(int index);

	const bool IsActive();
	const bool IsFreeze();

	VECTOR GetPos();

protected:
	bool m_IsAir;
	bool m_Freeze;
	bool m_IsTop;
	int m_AnimTimer;
	AnimationData animation[WATER_ANIM_MAX];
	WaterAnimationType waterAnim;
};
