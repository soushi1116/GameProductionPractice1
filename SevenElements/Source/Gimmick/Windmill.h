#pragma once
#include "DxLib.h"
#include "Gimmick.h"
#include "../Animation/Animation.h"

#define WINDMILL_MAX 32
#define WINDMILL_WIDTH (184)
#define WINDMILL_HEIGHT (200)

enum WindmillAnimationType
{
	WINDMILL_ANIM_1,
	WINDMILL_ANIM_2,
	WINDMILL_ANIM_MAX,
	WINDMILL_ANIM_NONE = -1
};

class Windmill : public Gimmick
{
public:
	Windmill();
	~Windmill();

public:
	void Load() override;
	void Start() override;
	void Step() override;
	void Update() override;
	void Draw() override;

	void Spawn(float posX, float posY);

	void StartWindmillAnimation(WindmillAnimationType anim);
	void UpdateWindmillAnimation();

	void WindmillHitWind();

	const bool IsActive() { return active; }

	const bool Rotating() { return m_Rotate; }

	VECTOR GetPos() { return pos; }

protected:
	bool m_Rotate;
	int m_Timer;

	AnimationData animation[WINDMILL_ANIM_MAX];
	WindmillAnimationType windmillAnim;
};

