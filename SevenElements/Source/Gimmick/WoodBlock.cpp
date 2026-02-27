#include "WoodBlock.h"
#include "../Effect/AnimationEffect.h"
#include "../Map/Block.h"
#include "../Elements/ElementsManager.h"
#include <math.h>

#define WIND_HIT_MOVE_SPEED (7.0f)
#define WOODBLOCK_FRICTION (0.3f)

WoodBlock::WoodBlock()
{
	pos.x = 0.0f;
	pos.y = 0.0f;
	move.x = 0.0f;
	move.y = 0.0f;

}

WoodBlock::~WoodBlock()
{
	DeleteGraph(handle);
}

void WoodBlock::Load()
{
	handle = LoadGraph("Data/Gimmick/WoodBlock(pre).png");
}

void WoodBlock::Start()
{
	
}

void WoodBlock::Step()
{
	if (active)
	{
		if (fabs(move.x) > WOODBLOCK_FRICTION)
		{
			if (move.x > 0.0f)
			{
				move.x -= WOODBLOCK_FRICTION;
			}
			else if (move.x < 0.0f)
			{
				move.x += WOODBLOCK_FRICTION;
			}
		}
		else
		{
			move.x = 0.0f;
		}
	}
}

void WoodBlock::Update()
{
	if (active)
	{
		pos.x += move.x;
	}

}

void WoodBlock::Draw()
{
	if (active)
	{
		DrawGraph(pos.x, pos.y, handle, TRUE);
	}
}

void WoodBlock::Spawn(float posX, float posY)
{
	if (!active)
	{
		active = true;

		pos.x = posX;
		pos.y = posY;
	}
}

void WoodBlock::WoodBlockHitBlock(int index)
{
	BlockData* block = GetBlocks();

	for (int i = 0; i < BLOCK_MAX; i++, block++)
	{
		if (i != index) continue;

		if (pos.y != block->pos.y) continue;

		if (move.x > 0.0f)
		{
			pos.x = block->pos.x - WOODBLOCK_WIDTH;
		}
		else if (move.x < 0.0f)
		{
			pos.x = block->pos.x + MAP_CHIP_WIDTH;
		}
	}
}

void WoodBlock::WoodBlockHitWind(int index)
{
	VECTOR windPos = GetElementPos(index, ELEMENT_TYPE_WIND);
	if (pos.x > windPos.x)
	{
		move.x = WIND_HIT_MOVE_SPEED;
	}
	else
	{
		move.x = -WIND_HIT_MOVE_SPEED;
	}
}

VECTOR WoodBlock::GetPos()
{
	return VGet(pos.x, pos.y, 0.0f);
}

const bool WoodBlock::IsActive()
{
	return active;
}

