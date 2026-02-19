#include "Water.h"
#include "../Effect/AnimationEffect.h"

#define EFFECT_INTERVAL (1)
#define WATER_MOVE_SPEED (7.0f)
#define WATER_ACTIVE_AREA_X_MIN (0.0f)
#define WATER_ACTIVE_AREA_X_MAX (1600.0f)
#define WATER_POS_Y_MIN (800.0f)
#define WATER_GRAVITY (0.5f)

//Fire* fire[FIRE_MAX] = { 0 };

Water::Water()
{
	pos.x = 0.0f;
	pos.y = 0.0f;

	move.y = 0.0f;
	move.y = 0.0f;

	m_IsTurn = false;
}

Water::~Water()
{
	DeleteGraph(handle);
}

void Water::Load()
{
	handle = LoadGraph("Data/Elements/Element_Water.png");
}

void Water::Start()
{
	move.x = WATER_MOVE_SPEED;
}

void Water::Step()
{
	if (active)
	{
		if (!m_IsTurn)
		{
			move.x = WATER_MOVE_SPEED;
		}
		else
		{
			move.x = -WATER_MOVE_SPEED;
		}

		if (pos.x < WATER_ACTIVE_AREA_X_MIN || pos.x > WATER_ACTIVE_AREA_X_MAX)
		{
			active = false;
		}

		if (pos.y < WATER_POS_Y_MIN)
		{
			move.y += WATER_GRAVITY;
		}
		else
		{
			move.y = 0;
		}
	}
}

void Water::Update()
{
	if (active)
	{
		pos.x += move.x;
		pos.y += move.y;
	}
}

void Water::Draw()
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

void Water::Spawn(float posX, float posY, bool isTurn)
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
			pos.x = posX - WATER_WIDTH;
		}

		pos.y = posY;

		m_IsTurn = isTurn;
	}
	
}