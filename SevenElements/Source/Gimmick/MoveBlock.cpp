#include "MoveBlock.h"
#include "../Effect/AnimationEffect.h"
#include "../Map/Block.h"
#include "../Elements/ElementsManager.h"
#include "../Camera/Camera.h"

#define MOVEBLOCK_MOVE_SPEED (2.0f)
#define MOVEBLOCK_MIN_POS_Y (400)
#define MOVEBLOCK_MAX_POS_Y (800)

MoveBlock::MoveBlock()
{
	pos.x = 0.0f;
	pos.y = 0.0f;
	move.x = 0.0f;
	move.y = 0.0f;

	m_MinPosY = 0.0f;
	m_MaxPosY = 0.0f;

	moveState = MOVE_STOP;
}

MoveBlock::~MoveBlock()
{
	DeleteGraph(handle);
}

void MoveBlock::Load()
{
	handle = LoadGraph("Data/Gimmick/MoveBlock.png");
}

void MoveBlock::Start()
{
	m_MinPosY = MOVEBLOCK_MIN_POS_Y;
	m_MaxPosY = MOVEBLOCK_MAX_POS_Y;
}

void MoveBlock::Step()
{
	if (active)
	{
		switch (moveState)
		{
		case MoveBlock::MOVE_STOP:
			move.y = 0.0f;
			break;
		case MoveBlock::MOVE_UP:
			move.y = -MOVEBLOCK_MOVE_SPEED;
			break;
		case MoveBlock::MOVE_DOWN:
			move.y = MOVEBLOCK_MOVE_SPEED;
			break;
		default:
			break;
		}
	}

}

void MoveBlock::Update()
{
	if (active)
	{
		pos.x += move.x;
		pos.y += move.y;

		if (pos.y < m_MinPosY)
		{
			moveState = MOVE_DOWN;
		}
		if (pos.y > m_MaxPosY)
		{
			moveState = MOVE_UP;
		}
	}

}

void MoveBlock::Draw()
{
	if (active)
	{
		CameraData camera = GetCamera();
		DrawGraph(pos.x - camera.posX, pos.y - camera.posY, handle, TRUE);
	}
}

void MoveBlock::Spawn(float posX, float posY)
{
	if (!active)
	{
		active = true;

		pos.x = posX;
		pos.y = posY;
	}
}

void MoveBlock::SwitchOn()
{
	if (moveState == MOVE_STOP)
	{
		moveState = MOVE_UP;
	}
}

void MoveBlock::SwitchOff()
{
	if (!moveState == MOVE_STOP)
	{
		moveState = MOVE_STOP;
	}
}

const bool MoveBlock::Moving()
{
	if (moveState == MOVE_STOP)
	{
		return false;
	}
	else
	{
		return true;
	}
}
