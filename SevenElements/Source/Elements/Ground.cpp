#include "Ground.h"
#include "../Effect/AnimationEffect.h"
#include "../Map/Block.h"
#include "../Sound/SoundManager.h"
#include "../Camera/Camera.h"

#define EFFECT_INTERVAL (1)
#define GROUND_MOVE_SPEED (7.0f)
#define GROUND_THROW_POW (5.0f)
#define GROUND_GRAVITY (0.5f)

//Fire* fire[FIRE_MAX] = { 0 };

Ground::Ground()
{
	pos.x = 0.0f;
	pos.y = 0.0f;

	move.y = 0.0f;
	move.y = 0.0f;

	m_IsTurn = false;
	m_IsAir = false;
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
		if (m_IsAir)
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
		CameraData camera = GetCamera();

		DrawGraph(pos.x - camera.posX, pos.y - camera.posY, handle, TRUE);
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

		m_IsAir = true;

		PlaySE(SE_GROUND);
	}
}

void Ground::GroundHitBlock(int index)
{
	BlockData* block = GetBlocks();
	for (int i = 0; i < BLOCK_MAX; i++, block++)
	{
		if (i != index) continue;

		move.x = 0.0f;

		if (pos.y < block->pos.y)
		{
			if (pos.x < block->pos.x + MAP_CHIP_WIDTH && pos.x + GROUND_WIDTH > block->pos.x)
			{
				move.y = 0.0f;

				pos.y = block->pos.y - GROUND_HEIGHT;

				m_IsAir = false;
				//m_Randing = true;
			}
		}
		else
		{
			if (move.x < 0.0f)
			{
				pos.x = block->pos.x + MAP_CHIP_WIDTH;
			}
			else if (move.x > 0.0f)
			{
				pos.x = block->pos.x - GROUND_WIDTH;
			}
		}

	}
	
}