#include "AirBalloon.h"
#include "../Effect/AnimationEffect.h"
#include "../Map/Block.h"
#include "../Player/Player.h"
#include "../Camera/Camera.h"

#define AIRBALLOON_MOVE_SPEED (2.0f)

AirBalloon::AirBalloon()
{
	pos.x = 0.0f;
	pos.y = 0.0f;
	move.x = 0.0f;
	move.y = 0.0f;

	m_Burning = false;
	m_Randing = false;

	airBalloonAnim = AIRBALLOON_ANIM_NONE;
}

AirBalloon::~AirBalloon()
{
	DeleteGraph(handle);
}

void AirBalloon::Load()
{
	animation[AIRBALLOON_ANIM_NORMAL].handle = LoadGraph("Data/Gimmick/AirBalloon.png");
	animation[AIRBALLOON_ANIM_BURNING].handle = LoadGraph("Data/Gimmick/AirBalloon_Burning.png");
	animation[AIRBALLOON_ANIM_RIDING].handle = LoadGraph("Data/Gimmick/AirBalloon_Riding.png");
}

void AirBalloon::Start()
{
	StartAirBalloonAnimation(AIRBALLOON_ANIM_NORMAL);
}

void AirBalloon::Step()
{
	if (active)
	{
		if (m_Randing)
		{
			move.y = 0.0f;
		}
		else if (m_Burning)
		{
			move.y = -AIRBALLOON_MOVE_SPEED;
		}
		else
		{
			move.y = AIRBALLOON_MOVE_SPEED;
		}
	}
}

void AirBalloon::Update()
{
	if (active)
	{
		pos.y += move.y;
	}

	UpdateAirBalloonAnimation();
}

void AirBalloon::Draw()
{
	if (active)
	{
		AirBalloonAnimationType animType = airBalloonAnim;
		AnimationData* animData = &animation[animType];

		CameraData camera = GetCamera();

		DrawAnimation(animData, pos.x - camera.posX, pos.y - camera.posY);
	}
}

void AirBalloon::StartAirBalloonAnimation(AirBalloonAnimationType anim)
{
	if (anim == airBalloonAnim) return;

	airBalloonAnim = anim;

	AnimationData* animData = &animation[anim];

	StartAnimation(animData, pos.x, pos.y);
}

void AirBalloon::UpdateAirBalloonAnimation()
{
	if (!active) return;

	PlayerData player = GetPlayer();

	if (player.ridingAirBalloon)
	{
		StartAirBalloonAnimation(AIRBALLOON_ANIM_RIDING);
	}
	else if (!m_Burning)
	{
		StartAirBalloonAnimation(AIRBALLOON_ANIM_NORMAL);
	}
	else
	{
		StartAirBalloonAnimation(AIRBALLOON_ANIM_BURNING);
	}
}

void AirBalloon::Spawn(float posX, float posY)
{
	if (!active)
	{
		active = true;

		pos.x = posX;
		pos.y = posY;
	}

}

void AirBalloon::AirBalloonHitFire()
{
	m_Burning = true;
	m_Randing = false;
}

void AirBalloon::AirBalloonHitBlock()
{
	m_Randing = true;
}

VECTOR AirBalloon::GetPos()
{
	return VGet(pos.x, pos.y, 0.0f);
}

const bool AirBalloon::IsActive()
{
	return active;
}

const bool AirBalloon::Burning()
{
	return m_Burning;
}

