#include "Water.h"
#include "../Effect/AnimationEffect.h"
#include "../Map/Block.h"

#define EFFECT_INTERVAL (1)
#define WATER_MOVE_SPEED (7.0f)
#define WATER_ACTIVE_AREA_X_MIN (0.0f)
#define WATER_ACTIVE_AREA_X_MAX (1600.0f)
#define WATER_POS_Y_MIN (800.0f)
#define WATER_GRAVITY (0.5f)
#define WATER_FRICTION (0.1f)

//Fire* fire[FIRE_MAX] = { 0 };

Water::Water()
{
	pos.x = 0.0f;
	pos.y = 0.0f;

	move.y = 0.0f;
	move.y = 0.0f;

	m_IsTurn = false;
	m_IsAir = false;
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
	
}

void Water::Step()
{
	if (active)
	{
		if (!m_IsAir)
		{
			if (!m_IsTurn)
			{
				if (move.x > 0)
				{
					move.x -= WATER_FRICTION;
				}
				else
				{
					move.x = 0;
				}
			}
			else
			{
				if (move.x < 0)
				{
					move.x += WATER_FRICTION;
				}
				else
				{
					move.x = 0;
				}
			}
		}

		if (pos.x < WATER_ACTIVE_AREA_X_MIN - WATER_WIDTH || pos.x > WATER_ACTIVE_AREA_X_MAX)
		{
			active = false;
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

		pos.y = posY - WATER_HEIGHT;

		if (!isTurn)
		{
			move.x = WATER_MOVE_SPEED;
		}
		else
		{
			move.x = -WATER_MOVE_SPEED;
		}

		m_IsTurn = isTurn;

		m_IsAir = false;
	}
}

void Water::WaterHitBlock(int index)
{
	BlockData* block = GetBlocks();
	for (int i = 0; i < BLOCK_MAX; i++, block++)
	{
		if (i != index) continue;

		pos.y = block->pos.y - MAP_CHIP_HEIGHT;

		m_IsAir = false;
	}
}

void Water::WaterHitWater(int indexA, int indexB, int posY)
{
	pos.y = posY - WATER_HEIGHT;
	m_IsAir = false;
}

void Water::WaterHitFire()
{
	if (m_IsFreeze)
	{
		m_IsFreeze = false;
	}
}

void Water::WaterHitIce()
{
	if (!m_IsFreeze)
	{
		m_IsFreeze = true;
	}
}