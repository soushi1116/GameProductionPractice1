#include "Water.h"
#include "../Effect/AnimationEffect.h"
#include "../Map/Block.h"
#include "../Sound/SoundManager.h"
#include "../Camera/Camera.h"
#include "ElementsManager.h"
#include "Iron.h"

#define EFFECT_INTERVAL (1)
#define WATER_MOVE_SPEED (7.0f)
#define WATER_GRAVITY (0.5f)
#define WATER_FRICTION (0.1f)

float prevPosY = 0.0f;

Water::Water()
{
	pos.x = 0.0f;
	pos.y = 0.0f;

	move.y = 0.0f;
	move.y = 0.0f;

	m_IsTurn = false;
	m_IsAir = false;
	m_IsFreeze = false;
	m_Randing = false;

	waterAnim = WATER_ANIM_NONE;
}

Water::~Water()
{
	DeleteGraph(handle);
}

void Water::Load()
{
	animation[WATER_ANIM_NORMAL].handle
		= LoadGraph("Data/Elements/Element_Water.png");
	animation[WATER_ANIM_FREEZE].handle
		= LoadGraph("Data/Elements/Element_Water_Freeze.png");
}

void Water::Start()
{
	StartWaterAnimation(WATER_ANIM_NORMAL);
}

void Water::Step()
{
	if (active)
	{
		prevPosY = pos.y;

		if (m_Randing)
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

		if (m_IsAir)
		{
			move.y += WATER_GRAVITY;
		}
	}
}

void Water::Update()
{
	if (active)
	{
		pos.x += move.x;
		pos.y += move.y;

		m_IsAir = true;
	}

	UpdateWaterAnimation();
}

void Water::Draw()
{
	if (active)
	{
		CameraData camera = GetCamera();

		WaterAnimationType animType = waterAnim;
		AnimationData* animData = &animation[animType];

		DrawAnimation(animData, pos.x - camera.posX, pos.y - camera.posY);
	}
}

void Water::StartWaterAnimation(WaterAnimationType anim)
{
	if (anim == waterAnim) return;

	waterAnim = anim;

	AnimationData* animData = &animation[anim];

	StartAnimation(animData, pos.x, pos.y);
}

void Water::UpdateWaterAnimation()
{
	if (!active) return;

	if (m_IsFreeze)
	{
		StartWaterAnimation(WATER_ANIM_FREEZE);
	}
	else
	{
		StartWaterAnimation(WATER_ANIM_NORMAL);
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

		m_IsAir = true;

		m_Randing = false;

		PlaySE(SE_WATER);
	}
}

void Water::WaterHitBlock(int index)
{
	BlockData* block = GetBlocks();
	for (int i = 0; i < BLOCK_MAX; i++, block++)
	{
		if (i != index) continue;

		if (pos.y < block->pos.y)
		{
			if (pos.x < block->pos.x + MAP_CHIP_WIDTH && pos.x + WATER_WIDTH > block->pos.x)
			{
				move.y = 0.0f;

				pos.y = block->pos.y - WATER_HEIGHT;

				m_IsAir = false;
				m_Randing = true;
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
				pos.x = block->pos.x - WATER_WIDTH;
			}
			move.x = 0.0f;
		}
	}
}

void Water::WaterHitIron(int index)
{
	VECTOR ironPos = GetElementPos(index, ELEMENT_TYPE_IRON);
	for (int i = 0; i < BLOCK_MAX; i++)
	{
		if (i != index) continue;

		if (pos.y < ironPos.y)
		{
			if (pos.x < ironPos.x + IRON_WIDTH && pos.x + WATER_WIDTH > ironPos.x)
			{
				move.y = 0.0f;

				pos.y = ironPos.y - WATER_HEIGHT;

				m_IsAir = false;
				m_Randing = true;
			}
		}
		else
		{
			if (move.x < 0.0f)
			{
				pos.x = ironPos.x + IRON_WIDTH;
			}
			else if (move.x > 0.0f)
			{
				pos.x = ironPos.x - WATER_WIDTH;
			}
			move.x = 0.0f;
		}
	}
}

void Water::WaterHitWater(int indexA, int indexB, int posX, int posY)
{
	if (pos.y < posY)
	{
		if (pos.x < posX + WATER_WIDTH && pos.x + WATER_WIDTH > posX)
		{
			move.y = 0.0f;

			pos.y = posY - WATER_HEIGHT;

			m_IsAir = false;
		}
	}
	else
	{
		if (move.x < 0.0f)
		{
			pos.x = posX + WATER_WIDTH;
		}
		else if (move.x > 0.0f)
		{
			pos.x = posX - WATER_WIDTH;
		}
		move.x = 0.0f;
	}
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