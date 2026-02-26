#include "Fire.h"
#include "../Effect/AnimationEffect.h"

#define EFFECT_INTERVAL (1)
#define FIREBALL_MOVE_SPEED (7.0f)
#define FIREBALL_ACTIVE_AREA_MIN (0.0f)
#define FIREBALL_ACTIVE_AREA_MAX (1600.0f)

//Fire* fire[FIRE_MAX] = { 0 };

Fire::Fire()
{
	pos.x = 0.0f;
	pos.y = 0.0f;

	move.y = 0.0f;
	move.y = 0.0f;

	m_IsTurn = false;
}

Fire::~Fire()
{
	active = false;
	DeleteGraph(handle);
}

void Fire::Load()
{
	handle = LoadGraph("Data/Elements/Element_Fire.png");
}

void Fire::Start()
{
	move.x = FIREBALL_MOVE_SPEED;
}

void Fire::Step()
{
	if (active)
	{
		if (!m_IsTurn)
		{
			move.x = FIREBALL_MOVE_SPEED;
		}
		else
		{
			move.x = -FIREBALL_MOVE_SPEED;
		}

		if (pos.x < FIREBALL_ACTIVE_AREA_MIN - FIRE_WIDTH || pos.x > FIREBALL_ACTIVE_AREA_MAX)
		{
			active = false;
		}
	}
}

void Fire::Update()
{
	if (active)
	{
		pos.x += move.x;
		pos.y += move.y;
	}
}

void Fire::Draw()
{
	if (active)
	{
		DrawGraph(pos.x, pos.y, handle, TRUE);
	}
}

void Fire::Spawn(float posX, float posY, bool isTurn)
{
	if (!active)
	{
		active = true;

		pos.x = posX - FIRE_WIDTH / 2;
		pos.y = posY - FIRE_HEIGHT;

		m_IsTurn = isTurn;
	}
}

void Fire::FireHitIron()
{
	active = false;
}

void Fire::FireHitWater()
{
	active = false;
}

VECTOR Fire::GetPos()
{
	return VGet(pos.x, pos.y, 0.0f);
}

const bool Fire::IsActive()
{
	return active;
}