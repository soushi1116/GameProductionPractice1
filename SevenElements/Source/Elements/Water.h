#pragma once
#include "DxLib.h"
#include "Elements.h"
#include "../Animation/Animation.h"

#define WATER_MAX 512
#define WATER_WIDTH (25)
#define WATER_HEIGHT (25)
#define WATER_SPAWN_NUM (5)
#define WATER_SPAWN_INTERVAL (60)
#define WATER_SPAWN_OFFSET (1.1f)

enum WaterAnimationType
{
	WATER_ANIM_NORMAL,
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

	void WaterHitBlock(int index);

	void WaterHitWater(int indexA, int indexB, int posX, int posY);

	void WaterHitFire();

	void WaterHitIce();

	void WaterHitIron(int index);

	bool IsActive() { return active; }

	bool IsFreeze() { return m_IsFreeze; }

	VECTOR GetPos() { return pos; }

	VECTOR GetMove() { return move; }

	void StartWaterAnimation(WaterAnimationType anim);
	void UpdateWaterAnimation();

protected:
	bool m_IsAir;
	bool m_IsFreeze;
	bool m_Randing;

	AnimationData animation[WATER_ANIM_MAX];
	WaterAnimationType waterAnim;
};
