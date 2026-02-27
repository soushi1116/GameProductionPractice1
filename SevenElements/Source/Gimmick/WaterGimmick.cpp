#include "WaterGimmick.h"
#include "../Effect/AnimationEffect.h"
#include "../Map/Block.h"

WaterGimmick::WaterGimmick()
{
	pos.x = 0.0f;
	pos.y = 0.0f;
	move.x = 0.0f;
	move.y = 0.0f;
}

WaterGimmick::~WaterGimmick()
{
	DeleteGraph(handle);
}

void WaterGimmick::Load()
{
	handle = LoadGraph("Data/Gimmick/WaterGimmick.png");
}

void WaterGimmick::Start()
{
	
}

void WaterGimmick::Step()
{
	if (active)
	{
	}
}

void WaterGimmick::Update()
{
	if (active)
	{
	}

}

void WaterGimmick::Draw()
{
	if (active)
	{
		DrawGraph(pos.x, pos.y, handle, TRUE);
	}
}


void WaterGimmick::Spawn(float posX, float posY)
{
	if (!active)
	{
		active = true;

		pos.x = posX;
		pos.y = posY;
	}

}

VECTOR WaterGimmick::GetPos()
{
	return VGet(pos.x, pos.y, 0.0f);
}

const bool WaterGimmick::IsActive()
{
	return active;
}

