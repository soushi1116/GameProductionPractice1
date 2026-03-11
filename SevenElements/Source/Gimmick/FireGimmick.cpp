#include "FireGimmick.h"
#include "../Effect/AnimationEffect.h"
#include "../Map/Block.h"
#include "../Player/Player.h"
#include "../Camera/Camera.h"

const int fireGimmickAnimationInterval = 30;

FireGimmick::FireGimmick()
{
	pos.x = 0.0f;
	pos.y = 0.0f;
	move.x = 0.0f;
	move.y = 0.0f;

	animTimer = 0;

	fireGimmickAnim = FIREGIMMICK_ANIM_NONE;
}

FireGimmick::~FireGimmick()
{
	DeleteGraph(handle);
}

void FireGimmick::Load()
{
	animation[FIREGIMMICK_ANIM_1].handle = LoadGraph("Data/Gimmick/FireGimmick_1.png");
	animation[FIREGIMMICK_ANIM_2].handle = LoadGraph("Data/Gimmick/FireGimmick_2.png");
}

void FireGimmick::Start()
{
	StartFireGimmickAnimation(FIREGIMMICK_ANIM_1);
}

void FireGimmick::Step()
{
	if (active)
	{
		animTimer++;
	}
}

void FireGimmick::Update()
{
	if (active)
	{
		if (animTimer > fireGimmickAnimationInterval * 2)
		{
			animTimer = 0;
		}
	}

	UpdateFireGimmickAnimation();
}

void FireGimmick::Draw()
{
	if (active)
	{
		FireGimmickAnimationType animType = fireGimmickAnim;
		AnimationData* animData = &animation[animType];

		CameraData camera = GetCamera();

		DrawAnimation(animData, pos.x - camera.posX, pos.y - camera.posY);
	}
}

void FireGimmick::StartFireGimmickAnimation(FireGimmickAnimationType anim)
{
	if (anim == fireGimmickAnim) return;

	fireGimmickAnim = anim;

	AnimationData* animData = &animation[anim];

	StartAnimation(animData, pos.x, pos.y);
}

void FireGimmick::UpdateFireGimmickAnimation()
{
	if (!active) return;

	if (animTimer < fireGimmickAnimationInterval)
	{
		StartFireGimmickAnimation(FIREGIMMICK_ANIM_1);
	}
	else
	{
		StartFireGimmickAnimation(FIREGIMMICK_ANIM_2);
	}
}

void FireGimmick::Spawn(float posX, float posY)
{
	if (!active)
	{
		active = true;

		pos.x = posX;
		pos.y = posY;
	}

}

void  FireGimmick::Delete()
{
	if (active)
	{
		active = false;
	}
}
