#pragma once
#include "DxLib.h"
#include "Gimmick.h"
#include "../Animation/Animation.h"

#define AIRBALLOON_MAX 32
#define AIRBALLOON_WIDTH (106)
#define AIRBALLOON_HEIGHT (200)

enum AirBalloonAnimationType
{
	AIRBALLOON_ANIM_NORMAL,
	AIRBALLOON_ANIM_BURNING,
	AIRBALLOON_ANIM_RIDING,
	AIRBALLOON_ANIM_MAX,
	AIRBALLOON_ANIM_NONE = -1
};

class AirBalloon : public Gimmick
{
public:
	AirBalloon();
	~AirBalloon();

public:
	void Load() override;
	void Start() override;
	void Step() override;
	void Update() override;
	void Draw() override;

	void Spawn(float posX, float posY);

	void StartAirBalloonAnimation(AirBalloonAnimationType anim);
	void UpdateAirBalloonAnimation();

	void AirBalloonHitFire();

	const bool IsActive();

	VECTOR GetPos();

protected:
	bool m_Burning;

	AnimationData animation[AIRBALLOON_ANIM_MAX];
	AirBalloonAnimationType airBalloonAnim;
};

