#pragma once
#include "DxLib.h"
#include "Elements.h"

#define WATER_MAX 512
#define WATER_WIDTH (25)
#define WATER_HEIGHT (25)
#define WATER_SPAWN_NUM (5)
#define WATER_SPAWN_INTERVAL (60)
#define WATER_SPAWN_OFFSET (1.1f)

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

	bool IsActive() { return active; }

	bool IsFreeze() { return m_IsFreeze; }

	VECTOR GetPos() { return pos; }

	VECTOR GetMove() { return move; }

protected:
	bool m_IsAir;
	bool m_IsFreeze;
	bool m_Randing;
};
