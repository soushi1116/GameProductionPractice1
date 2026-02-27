#include "Tree.h"
#include "../Effect/AnimationEffect.h"
#include "../Map/Block.h"

#define BURN_EFFECT_INTERVAL (180)

Tree::Tree()
{
	pos.x = 0.0f;
	pos.y = 0.0f;
	move.x = 0.0f;
	move.y = 0.0f;

	m_BurnTimer = 0;

	m_Burning = false;

	treeAnim = TREE_ANIM_NONE;
}

Tree::~Tree()
{
	DeleteGraph(handle);
}

void Tree::Load()
{
	animation[TREE_ANIM_NORMAL].handle = LoadGraph("Data/Gimmick/Tree.png");
	animation[TREE_ANIM_BURNING].handle = LoadGraph("Data/Gimmick/Tree_Burning.png");
}

void Tree::Start()
{
	StartTreeAnimation(TREE_ANIM_NORMAL);
}

void Tree::Step()
{
	if (active)
	{
		if (m_Burning)
		{
			m_BurnTimer++;
		}
	}
}

void Tree::Update()
{
	if (active)
	{
		if (m_BurnTimer > BURN_EFFECT_INTERVAL)
		{
			active = false;
		}
	}

	UpdateTreeAnimation();
}

void Tree::Draw()
{
	if (active)
	{
		TreeAnimationType animType = treeAnim;
		AnimationData* animData = &animation[animType];

		DrawAnimation(animData, pos.x, pos.y);
	}
}

void Tree::StartTreeAnimation(TreeAnimationType anim)
{
	if (anim == treeAnim) return;

	treeAnim = anim;

	AnimationData* animData = &animation[anim];

	StartAnimation(animData, pos.x, pos.y);
}

void Tree::UpdateTreeAnimation()
{
	if (!active) return;

	if (!m_Burning)
	{
		StartTreeAnimation(TREE_ANIM_NORMAL);
	}
	else
	{
		if (m_BurnTimer < BURN_EFFECT_INTERVAL)
		{
			StartTreeAnimation(TREE_ANIM_BURNING);
		}
	}
}

void Tree::Spawn(float posX, float posY)
{
	if (!active)
	{
		active = true;

		pos.x = posX;
		pos.y = posY;
	}

}

void Tree::TreeHitFire()
{
	m_Burning = true;
}

VECTOR Tree::GetPos()
{
	return VGet(pos.x, pos.y, 0.0f);
}

const bool Tree::IsActive()
{
	return active;
}

