#include "Water.h"
#include "../Effect/AnimationEffect.h"
#include "../Map/Block.h"

#define EFFECT_INTERVAL (1)
#define WATER_MOVE_SPEED (7.0f)
#define WATER_ACTIVE_AREA_X_MIN (0.0f)
#define WATER_ACTIVE_AREA_X_MAX (1600.0f)
#define WATER_POS_Y_MIN (700.0f)
#define WATER_GRAVITY (0.5f)
#define WATER_FRICTION (0.1f)
#define WATER_ANIM_INTERVAL (20)

//Fire* fire[FIRE_MAX] = { 0 };

Water::Water()
{
	pos.x = 0.0f;
	pos.y = 0.0f;

	move.y = 0.0f;
	move.y = 0.0f;

	m_IsTurn = false;
	m_IsAir = false;
	m_Freeze = false;
	m_IsTop = false;

	m_AnimTimer = 0;

	waterAnim = WATER_ANIM_NONE;
}

Water::~Water()
{
	DeleteGraph(handle);
}

void Water::Load()
{
	animation[WATER_ANIM_1].handle = LoadGraph("Data/Elements/Element_Water_1.png");
	animation[WATER_ANIM_2].handle = LoadGraph("Data/Elements/Element_Water_2.png");
	animation[WATER_ANIM_3].handle = LoadGraph("Data/Elements/Element_Water_3.png");
	animation[WATER_ANIM_FREEZE].handle = LoadGraph("Data/Elements/Element_Water_Freeze.png");
}

void Water::Start()
{
	StartWaterAnimation(WATER_ANIM_1);
}

void Water::Step()
{
	if (active)
	{
		move.y += WATER_GRAVITY;

		if (!m_IsAir)
		{
			m_AnimTimer++;

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

		if (m_AnimTimer >= WATER_ANIM_INTERVAL * 6)
		{
			m_AnimTimer = 0;
		}

		UpdateWaterAnimation();
	}
}

void Water::Draw()
{
	if (active)
	{
		WaterAnimationType animType = waterAnim;
		AnimationData* animData = &animation[animType];
		if (!m_IsTurn)
		{
			DrawAnimation(animData, pos.x, pos.y);
		}
		else
		{
			DrawTurnAnimation(animData, pos.x, pos.y);
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
		m_IsTop = true;
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

	if (m_Freeze)
	{
		StartWaterAnimation(WATER_ANIM_FREEZE);
	}
	else
	{
		if (m_AnimTimer >= 0 && m_AnimTimer < WATER_ANIM_INTERVAL)
		{
			StartWaterAnimation(WATER_ANIM_1);
		}
		else if (m_AnimTimer >= WATER_ANIM_INTERVAL && m_AnimTimer < WATER_ANIM_INTERVAL * 5)
		{
			StartWaterAnimation(WATER_ANIM_2);
		}
		else if (m_AnimTimer >= WATER_ANIM_INTERVAL * 5)
		{
			StartWaterAnimation(WATER_ANIM_3);
		}
	}
}

void Water::WaterHitWater(int indexA, int indexB, float posY)
{
	move.y = 0.0f;
	pos.y = posY - WATER_HEIGHT;
}


void Water::WaterHitIce()
{
	m_Freeze = true;
}

void Water::WaterHitFire()
{
	m_Freeze = false;
}

void Water::WaterHitBlock(int index)
{
	BlockData* block = GetBlocks();

	move.y = 0.0f;

	m_IsAir = false;

	for (int i = 0; i < BLOCK_MAX; i++, block++)
	{
		if (i != index) continue;

		if (pos.y > block->pos.y)
		{
			move.x = 0.0f;
			pos.x = block->pos.x + MAP_CHIP_WIDTH;
		}
		else
		{
			pos.y = block->pos.y - WATER_HEIGHT;
		}
	}
}

VECTOR Water::GetPos()
{
	return VGet(pos.x, pos.y, 0.0f);
}

const bool Water::IsActive()
{
	return active;
}

const bool Water::IsFreeze()
{
	return m_Freeze;
}