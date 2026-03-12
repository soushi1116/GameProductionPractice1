#pragma once
#include "DxLib.h"
#include "Gimmick.h"
#include "../Animation/Animation.h"

#define BATTERY_MAX 32
#define BATTERY_WIDTH (101)
#define BATTERY_HEIGHT (300)

enum BatteryAnimationType
{
	BATTERY_ANIM_OFF,
	BATTERY_ANIM_ON,
	BATTERY_ANIM_MAX,
	BATTERY_ANIM_NONE = -1
};

class Battery : public Gimmick
{
public:
	Battery();
	~Battery();

public:
	void Load() override;
	void Start() override;
	void Step() override;
	void Update() override;
	void Draw() override;

	void Spawn(float posX, float posY);

	void StartBatteryAnimation(BatteryAnimationType anim);
	void UpdateBatteryAnimation();

	void BatteryHitThunder();

	const bool IsActive() { return active; }

	VECTOR GetPos() { return pos; }

protected:
	bool m_Charged;

	AnimationData animation[BATTERY_ANIM_MAX];
	BatteryAnimationType batteryAnim;
};

