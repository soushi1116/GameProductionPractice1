#include "Iron.h"
#include "../Effect/AnimationEffect.h"

#define EFFECT_INTERVAL (1)
#define IRON_MOVE_SPEED (5.0f)
#define IRON_ACTIVE_AREA_X_MIN (0.0f)
#define IRON_ACTIVE_AREA_X_MAX (1600.0f)
#define IRON_POS_Y_MIN (750.0f)
#define IRON_REACH (200.0f)
#define IRON_GRAVITY (0.5f)

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
		if (pos.x < IRON_ACTIVE_AREA_X_MIN - IRON_WIDTH || pos.x > IRON_ACTIVE_AREA_X_MAX)
		{
			active = false;
		}

		if (pos.y >= IRON_POS_Y_MIN - IRON_HEIGHT)
		{
			IronHitFloor();
		}
		
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
		DrawGraph(pos.x, pos.y, handle, TRUE);
	}
}

void Iron::Spawn(float posX, float posY, bool isTurn)
{
	if (!active)
	{
		active = true;

		if (!isTurn)
		{
			pos.x = posX - IRON_WIDTH / 2 + IRON_REACH;
		}
		else
		{
			pos.x = posX - IRON_WIDTH / 2 - IRON_REACH;
		}
		pos.y = 0.0f;

		m_IsTurn = isTurn;
	}
	
}

VECTOR Iron::GetPos()
{
	return VGet(pos.x, pos.y, 0.0f);
}

const bool Iron::IsActive()
{ 
	return active;
}

void Iron::IronHitFloor()
{
	pos.y = IRON_POS_Y_MIN - IRON_HEIGHT;
	m_Randing = true;
	move.y = 0.0f;
}

void Iron::IronHitIron(int indexA, int indexB, float posY)
{
	move.y = 0.0f;
	pos.y = posY - IRON_HEIGHT;
}

