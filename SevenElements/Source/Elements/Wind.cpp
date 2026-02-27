#include "Wind.h"
#include "../Effect/AnimationEffect.h"

#define EFFECT_INTERVAL (1)
#define WIND_MOVE_SPEED (10.0f)
#define WIND_ACTIVE_AREA_MIN (0.0f)
#define WIND_ACTIVE_AREA_MAX (1600.0f)

//Fire* fire[FIRE_MAX] = { 0 };

Wind::Wind()
{
	pos.x = 0.0f;
	pos.y = 0.0f;

	move.y = 0.0f;
	move.y = 0.0f;

	m_IsTurn = false;
}

Wind::~Wind()
{
	DeleteGraph(handle);
}

void Wind::Load()
{
	handle = LoadGraph("Data/Elements/Element_Wind.png");
}

void Wind::Start()
{
	move.x = WIND_MOVE_SPEED;
}

void Wind::Step()
{
	if (active)
	{
		if (!m_IsTurn)
		{
			move.x = WIND_MOVE_SPEED;
		}
		else
		{
			move.x = -WIND_MOVE_SPEED;
		}

		if (pos.x < WIND_ACTIVE_AREA_MIN - WIND_WIDTH || pos.x > WIND_ACTIVE_AREA_MAX)
		{
			active = false;
		}
	}
}

void Wind::Update()
{
	if (active)
	{
		pos.x += move.x;
		pos.y += move.y;
	}
}

void Wind::Draw()
{
	if (active)
	{
		if (!m_IsTurn)
		{
			DrawGraph(pos.x, pos.y, handle, TRUE);
		}
		else
		{
			DrawTurnGraph(pos.x, pos.y, handle, TRUE);
		}
	}
}

void Wind::Spawn(float posX, float posY, bool isTurn)
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
			pos.x = posX - WIND_WIDTH;
		}

		pos.y = posY;

		m_IsTurn = isTurn;
	}
}