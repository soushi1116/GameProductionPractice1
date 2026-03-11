#pragma once
#include "DxLib.h"
#include "Gimmick.h"
#include "../Animation/Animation.h"

#define FIREGIMMICK_MAX 32
#define FIREGIMMICK_WIDTH (50)
#define FIREGIMMICK_HEIGHT (25)

enum FireGimmickAnimationType
{
	FIREGIMMICK_ANIM_1,
	FIREGIMMICK_ANIM_2,
	FIREGIMMICK_ANIM_MAX,
	FIREGIMMICK_ANIM_NONE = -1
};

class FireGimmick : public Gimmick
{
public:
	FireGimmick();
	~FireGimmick();

public:
	void Load() override;
	void Start() override;
	void Step() override;
	void Update() override;
	void Draw() override;

	void Spawn(float posX, float posY);

	void StartFireGimmickAnimation(FireGimmickAnimationType anim);
	void UpdateFireGimmickAnimation();

	void Delete();

	const bool IsActive() { return active; }

	VECTOR GetPos() { return pos; }

protected:
	int animTimer;

	AnimationData animation[FIREGIMMICK_ANIM_MAX];
	FireGimmickAnimationType fireGimmickAnim;
};

