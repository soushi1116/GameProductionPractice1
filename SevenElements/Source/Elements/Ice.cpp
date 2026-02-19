#include "Ice.h"
#include "../Effect/AnimationEffect.h"

#define EFFECT_INTERVAL (1)
#define ICE_ACTIVE_AREA_MIN (0.0f)
#define ICE_ACTIVE_AREA_MAX (1600.0f)
#define ICE_LIFE_TIME (100)
#define ICE_SIZE_INCLEASE (0.05)

//Fire* fire[FIRE_MAX] = { 0 };

Ice::Ice()
{
	pos.x = 0.0f;
	pos.y = 0.0f;

	move.y = 0.0f;
	move.y = 0.0f;

	timer = 0;
	size = 0.0;

	m_IsTurn = false;
}

Ice::~Ice()
{
	DeleteGraph(handle);
}

void Ice::Load()
{
	handle = LoadGraph("Data/Elements/Element_Ice.png");
}

void Ice::Start()
{
	size = 0.0;
}

void Ice::Step()
{
	if (active)
	{
		timer++;

		if (size < 1.0)
		{
			size += ICE_SIZE_INCLEASE;
		}
	}
}

void Ice::Update()
{
	if (active)
	{
		pos.x += move.x;
		pos.y += move.y;

		if (timer > ICE_LIFE_TIME)
		{
			active = false;
			timer = 0;
		}
	}
}

void Ice::Draw()
{
	if (active)
	{
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 192);
		DrawRotaGraph(pos.x, pos.y, size, 0, handle, TRUE);
	}
}

void Ice::Spawn(float posX, float posY, bool isTurn)
{
	if (!active)
	{
		active = true;

		pos.x = posX;
		pos.y = posY;

		size = 0.0;
	}
	
}