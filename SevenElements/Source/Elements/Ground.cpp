#include "Ground.h"
#include "../Effect/AnimationEffect.h"

#define EFFECT_INTERVAL (1)
#define GROUND_MOVE_SPEED (7.0f)
#define GROUND_THROW_POW (5.0f)
#define GROUND_ACTIVE_AREA_X_MIN (0.0f)
#define GROUND_ACTIVE_AREA_X_MAX (1600.0f)
#define GROUND_POS_Y_MIN (800.0f)
#define GROUND_GRAVITY (0.5f)

//Fire* fire[FIRE_MAX] = { 0 };

Ground::Ground()
{
	pos.x = 0.0f;
	pos.y = 0.0f;

	move.y = 0.0f;
	move.y = 0.0f;

	m_IsTurn = false;
}

Ground::~Ground()
{
	DeleteGraph(handle);
}

void Ground::Load()
{
	handle = LoadGraph("Data/Elements/Element_Ground.png");
}

void Ground::Start()
{
	move.x = GROUND_MOVE_SPEED;
}

void Ground::Step()
{
	if (active)
	{
		if (pos.x < GROUND_ACTIVE_AREA_X_MIN - GROUND_WIDTH || pos.x > GROUND_ACTIVE_AREA_X_MAX)
		{
			active = false;
		}

		if (pos.y >= GROUND_POS_Y_MIN)
		{
			move.x = 0;
			move.y = 0;
		}
		else
		{
			if (!m_IsTurn)
			{
				move.x = GROUND_MOVE_SPEED;
			}
			else
			{
				move.x = -GROUND_MOVE_SPEED;
			}
			move.y += GROUND_GRAVITY;
		}

	}
}

void Ground::Update()
{
	if (active)
	{
		pos.x += move.x;
		pos.y += move.y;
	}
}

void Ground::Draw()
{
	if (active)
	{
		DrawGraph(pos.x, pos.y, handle, TRUE);
	}
}

void Ground::Spawn(float posX, float posY, bool isTurn)
{
	if (!active)
	{
		active = true;

		if (!isTurn)
		{
			pos.x = posX;
		}
		else
		{
			pos.x = posX - GROUND_WIDTH;
		}

		pos.y = posY;

		move.y = -GROUND_THROW_POW;

		m_IsTurn = isTurn;
	}
	
}

VECTOR Ground::GetPos()
{
	return VGet(pos.x, pos.y, 0.0f);
}

const bool Ground::IsActive()
{
	return active;
}