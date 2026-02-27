#pragma once
#include "DxLib.h"
#include "Gimmick.h"
#include "../Animation/Animation.h"

#define WATER_GIMMICK_MAX 32
#define WATER_GIMMICK_WIDTH (101)
#define WATER_GIMMICK_HEIGHT (300)

class WaterGimmick : public Gimmick
{
public:
	WaterGimmick();
	~WaterGimmick();

public:
	void Load() override;
	void Start() override;
	void Step() override;
	void Update() override;
	void Draw() override;

	void Spawn(float posX, float posY);

	const bool IsActive();

	VECTOR GetPos();

protected:

};

