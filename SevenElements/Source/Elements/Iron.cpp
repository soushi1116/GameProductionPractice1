#include "Iron.h"
#include "../Effect/AnimationEffect.h"
#include "../Map/Block.h"
#include "../Sound/SoundManager.h"
#include "../Camera/Camera.h"

#define EFFECT_INTERVAL (1)
#define IRON_MOVE_SPEED (5.0f)
#define IRON_REACH_X (200.0f)
#define IRON_REACH_Y (200.0f)
#define IRON_GRAVITY (0.5f)
#define IRON_SPAWN_POS_Y_MIN (100.0f)

Iron::Iron()
{
	pos.x = 0.0f;
	pos.y = 0.0f;

	move.y = 0.0f;
	move.y = 0.0f;

	m_IsTurn = false;
	m_Randing = false;
}

Iron::~Iron()
{
	DeleteGraph(handle);
}

void Iron::Load()
{
	handle = LoadGraph("Data/Elements/Element_Iron.png");
}

void Iron::Start()
{
	
}

void Iron::Step()
{
	if (active)
	{
		move.y += IRON_GRAVITY;
	}
}

void Iron::Update()
{
	if (active)
	{
		pos.x += move.x;
		pos.y += move.y;
	}
}

void Iron::Draw()
{
	if (active)
	{
		CameraData camera = GetCamera();

		DrawGraph(pos.x - camera.posX, pos.y - camera.posY, handle, TRUE);
	}
}

void Iron::Spawn(float posX, float posY, bool isTurn)
{
	if (!active)
	{
		active = true;

		if (!isTurn)
		{
			pos.x = posX - IRON_WIDTH / 2 + IRON_REACH_X;
		}
		else
		{
			pos.x = posX - IRON_WIDTH / 2 - IRON_REACH_X;
		}

		float spawnPosY = posY - IRON_REACH_Y;

		if (spawnPosY > IRON_SPAWN_POS_Y_MIN)
		{
			pos.y = spawnPosY;
		}
		else
		{
			pos.y = IRON_SPAWN_POS_Y_MIN;
		}

		m_IsTurn = isTurn;

		PlaySE(SE_IRON);
	}
	
}

void Iron::IronHitBlock(int index)
{
	BlockData* block = GetBlocks();
	for (int i = 0; i < BLOCK_MAX; i++, block++)
	{
		if (i != index) continue;

		move.y = 0.0f;
		pos.y = block->pos.y - IRON_HEIGHT;
	}
}

void Iron::IronHitIron(int indexA, int indexB, float posY)
{
	move.y = 0.0f;
	pos.y = posY - IRON_HEIGHT;
}


