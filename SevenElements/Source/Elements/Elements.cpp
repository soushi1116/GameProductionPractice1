#include "DxLib.h"
#include "Elements.h"
#include "Fire.h"
#include  "../Effect/AnimationEffect.h"

#define ELEMENT_TYPE_NUM_MAX (7)
#define EFFECT_INTERVAL (5)


Element::Element()
{
	pos.x = 0.0f;
	pos.y = 0.0f;

	move.x = 0.0f;
	move.y = 0.0f;

	active = false;
	m_IsTurn = false;

    handle = 0;
}

Element::~Element()
{

}

void Element::Load()
{
    
}

void Element::Start()
{

}

void Element::Step()
{

}

void Element::Update()
{

}

void Element::Draw()
{
	
}