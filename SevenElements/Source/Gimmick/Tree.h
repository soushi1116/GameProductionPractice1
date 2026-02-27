#pragma once
#include "DxLib.h"
#include "Gimmick.h"
#include "../Animation/Animation.h"

#define TREE_MAX 32
#define TREE_WIDTH (101)
#define TREE_HEIGHT (300)

enum TreeAnimationType
{
	TREE_ANIM_NORMAL,
	TREE_ANIM_BURNING,
	TREE_ANIM_MAX,
	TREE_ANIM_NONE = -1
};

class Tree : public Gimmick
{
public:
	Tree();
	~Tree();

public:
	void Load() override;
	void Start() override;
	void Step() override;
	void Update() override;
	void Draw() override;

	void Spawn(float posX, float posY);

	void StartTreeAnimation(TreeAnimationType anim);
	void UpdateTreeAnimation();

	void TreeHitFire();

	const bool IsActive();

	VECTOR GetPos();

protected:
	bool m_Burning;

	int m_BurnTimer;

	AnimationData animation[TREE_ANIM_MAX];
	TreeAnimationType treeAnim;
};

