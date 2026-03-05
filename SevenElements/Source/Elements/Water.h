#pragma once
#include "DxLib.h"
#include "Elements.h"

#define WATER_MAX 64
#define WATER_WIDTH (10)
#define WATER_HEIGHT (10)
#define WATER_SPAWN_NUM (20)

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

	void WaterHitWater(int indexA, int indexB, int posY);

	void WaterHitFire();

	void WaterHitIce();

	bool IsActive() { return active; }

	bool IsFreeze() { return m_IsFreeze; }

	VECTOR GetPos() { return pos; }

protected:
	bool m_IsAir;
	bool m_IsFreeze;
};
