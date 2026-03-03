#include "Water.h"
#include "../Effect/AnimationEffect.h"
#include "../Map/Block.h"
#include "../Sound/SoundManager.h"
#include "../Camera/Camera.h"

#define EFFECT_INTERVAL (1)
#define WATER_MOVE_SPEED (7.0f)
#define WATER_GRAVITY (0.5f)
#define WATER_FRICTION (0.1f)

Water::Water()
{
	pos.x = 0.0f;
	pos.y = 0.0f;

	move.y = 0.0f;
	move.y = 0.0f;

	m_IsTurn = false;
	m_IsAir = false;
	m_IsFreeze = false;
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
		CameraData camera = GetCamera();

		if (!m_IsTurn)
		{
			DrawGraph(pos.x - camera.posX, pos.y - camera.posY, handle, TRUE);
		}
		else
		{
			DrawTurnGraph(pos.x - camera.posX, pos.y - camera.posY, handle, TRUE);
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

		PlaySE(SE_WATER);
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