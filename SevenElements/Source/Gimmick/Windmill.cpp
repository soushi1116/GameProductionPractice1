#include "Windmill.h"
#include "GimmickManager.h"
#include "../Effect/AnimationEffect.h"
#include "../Map/Block.h"
#include "../Camera/Camera.h"

const int WINDMILL_ANIM_INTERVAL(10);

Windmill::Windmill()
{
	pos.x = 0.0f;
	pos.y = 0.0f;
	move.x = 0.0f;
	move.y = 0.0f;

	m_Timer = 0;

	m_Rotate = false;

	windmillAnim = WINDMILL_ANIM_NONE;
}

Windmill::~Windmill()
{
	DeleteGraph(handle);
}

void Windmill::Load()
{
	animation[WINDMILL_ANIM_1].handle = LoadGraph("Data/Gimmick/Windmill_1.png");
	animation[WINDMILL_ANIM_2].handle = LoadGraph("Data/Gimmick/Windmill_2.png");
}

void Windmill::Start()
{
	StartWindmillAnimation(WINDMILL_ANIM_1);
}

void Windmill::Step()
{
	if (active)
	{
		if (m_Rotate)
		{
			m_Timer++;
		}
	}
}

void Windmill::Update()
{
	if (active)
	{
		if (m_Timer > WINDMILL_ANIM_INTERVAL * 12)
		{
			m_Timer = 0;
			m_Rotate = false;
			WindmillStop();
		}
	}

	UpdateWindmillAnimation();
}

void Windmill::Draw()
{
	if (active)
	{
		WindmillAnimationType animType = windmillAnim;
		AnimationData* animData = &animation[animType];

		CameraData camera = GetCamera();
		DrawAnimation(animData, pos.x - camera.posX, pos.y - camera.posY);
	}
}

void Windmill::StartWindmillAnimation(WindmillAnimationType anim)
{
	if (anim == windmillAnim) return;

	windmillAnim = anim;

	AnimationData* animData = &animation[anim];

	StartAnimation(animData, pos.x, pos.y);
}

void Windmill::UpdateWindmillAnimation()
{
	if (!active) return;

	if ((m_Timer / WINDMILL_ANIM_INTERVAL) % 2 == 0)
	{
		StartWindmillAnimation(WINDMILL_ANIM_1);
	}
	else
	{
		StartWindmillAnimation(WINDMILL_ANIM_2);
	}
}

void Windmill::Spawn(float posX, float posY)
{
	if (!active)
	{
		active = true;

		pos.x = posX;
		pos.y = posY;
	}

}

void Windmill::WindmillHitWind()
{
	m_Rotate = true;
	m_Timer = 0;
}

