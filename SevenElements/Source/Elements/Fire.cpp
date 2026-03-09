#include "Fire.h"
#include "../Effect/AnimationEffect.h"
#include "../Sound/SoundManager.h"
#include "../Camera/Camera.h"

#define EFFECT_INTERVAL (1)
#define FIREBALL_MOVE_SPEED (7.0f)

//Fire* fire[FIRE_MAX] = { 0 };

Fire::Fire()
{
	pos.x = 0.0f;
	pos.y = 0.0f;

	move.y = 0.0f;
	move.y = 0.0f;

	m_IsTurn = false;
}

Fire::~Fire()
{
	DeleteGraph(handle);
}

void Fire::Load()
{
	handle = LoadGraph("Data/Elements/Element_Fire.png");
}

void Fire::Start()
{
	move.x = FIREBALL_MOVE_SPEED;
}

void Fire::Step()
{
	if (active)
	{
		if (!m_IsTurn)
		{
			move.x = FIREBALL_MOVE_SPEED;
		}
		else
		{
			move.x = -FIREBALL_MOVE_SPEED;
		}
	}
}

void Fire::Update()
{
	if (active)
	{
		pos.x += move.x;
		pos.y += move.y;
	}
}

void Fire::Draw()
{
	if (active)
	{
		CameraData camera = GetCamera();

		DrawGraph(pos.x - camera.posX, pos.y - camera.posY, handle, TRUE);
	}
}

void Fire::Spawn(float posX, float posY, bool isTurn)
{
	if (!active)
	{
		active = true;

		pos.x = posX - FIRE_WIDTH / 2;
		pos.y = posY - FIRE_HEIGHT;

		m_IsTurn = isTurn;

		PlaySE(SE_FIRE);
	}

}