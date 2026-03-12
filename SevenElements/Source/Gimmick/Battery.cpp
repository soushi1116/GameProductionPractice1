#include "Battery.h"
#include "../Effect/AnimationEffect.h"
#include "../Map/Block.h"
#include "../Camera/Camera.h"

Battery::Battery()
{
	pos.x = 0.0f;
	pos.y = 0.0f;
	move.x = 0.0f;
	move.y = 0.0f;

	m_Charged = false;

	batteryAnim = BATTERY_ANIM_NONE;
}

Battery::~Battery()
{
	DeleteGraph(handle);
}

void Battery::Load()
{
	animation[BATTERY_ANIM_OFF].handle = LoadGraph("Data/Gimmick/Battery_Off.png");
	animation[BATTERY_ANIM_ON].handle = LoadGraph("Data/Gimmick/Battery_On.png");
}

void Battery::Start()
{
	StartBatteryAnimation(BATTERY_ANIM_OFF);
}

void Battery::Step()
{
	if (active)
	{

	}
}

void Battery::Update()
{
	if (active)
	{

	}

	UpdateBatteryAnimation();
}

void Battery::Draw()
{
	if (active)
	{
		BatteryAnimationType animType = batteryAnim;
		AnimationData* animData = &animation[animType];

		CameraData camera = GetCamera();
		DrawAnimation(animData, pos.x - camera.posX, pos.y - camera.posY);
	}
}

void Battery::StartBatteryAnimation(BatteryAnimationType anim)
{
	if (anim == batteryAnim) return;

	batteryAnim = anim;

	AnimationData* animData = &animation[anim];

	StartAnimation(animData, pos.x, pos.y);
}

void Battery::UpdateBatteryAnimation()
{
	if (!active) return;

	if (!m_Charged)
	{
		StartBatteryAnimation(BATTERY_ANIM_OFF);
	}
	else
	{
		StartBatteryAnimation(BATTERY_ANIM_ON);
	}
}

void Battery::Spawn(float posX, float posY)
{
	if (!active)
	{
		active = true;

		pos.x = posX;
		pos.y = posY;
	}

}

void Battery::BatteryHitThunder()
{
	m_Charged = true;
}

