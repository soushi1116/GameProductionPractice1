#include "Thunder.h"
#include "../Effect/AnimationEffect.h"
#include "../Sound/SoundManager.h"
#include "../Camera/Camera.h"

#define EFFECT_INTERVAL (1)
#define THUNDER_MOVE_SPEED (20.0f)
#define THUNDER_ACTIVE_AREA_Y_MIN (0.0f)
#define THUNDER_ACTIVE_AREA_Y_MAX (900.0f)
#define THUNDER_REACH (300.0f)

Thunder::Thunder()
{
	pos.x = 0.0f;
	pos.y = 0.0f;

	move.y = 0.0f;
	move.y = 0.0f;

	m_IsTurn = false;
}

Thunder::~Thunder()
{
	DeleteGraph(handle);
}

void Thunder::Load()
{
	handle = LoadGraph("Data/Elements/Element_Thunder.png");
}

void Thunder::Start()
{
	move.y = THUNDER_MOVE_SPEED;
}

void Thunder::Step()
{
	if (active)
	{
		move.y = THUNDER_MOVE_SPEED;

		if (pos.y < -THUNDER_HEIGHT || pos.y > THUNDER_ACTIVE_AREA_Y_MAX)
		{
			active = false;
		}
	}
}

void Thunder::Update()
{
	if (active)
	{
		pos.x += move.x;
		pos.y += move.y;
	}
}

void Thunder::Draw()
{
	if (active)
	{
		CameraData camera = GetCamera();

		DrawGraph(pos.x - camera.posX, pos.y - camera.posY, handle, TRUE);
	}
}

void Thunder::Spawn(float posX, float posY, bool isTurn)
{
	if (!active)
	{
		active = true;

		if (!isTurn)
		{
			pos.x = posX - THUNDER_WIDTH / 2 + THUNDER_REACH;
		}
		else
		{
			pos.x = posX - THUNDER_WIDTH / 2 - THUNDER_REACH;
		}
		pos.y = -THUNDER_HEIGHT;

		m_IsTurn = isTurn;

		PlaySE(SE_THUNDER);
	}
	
}