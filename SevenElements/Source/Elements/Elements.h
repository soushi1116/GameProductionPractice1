#pragma once
#include "DxLib.h"

#define ELEMENT_MAX 512

enum ElementType
{
	ELEMENT_TYPE_NONE = -1,
	ELEMENT_TYPE_FIRE,
	ELEMENT_TYPE_WATER,
	ELEMENT_TYPE_THUNDER,
	ELEMENT_TYPE_WIND,
	ELEMENT_TYPE_GROUND,
	ELEMENT_TYPE_ICE,
	ELEMENT_TYPE_IRON,
	ELEMENT_TYPE_MAX,
};


class Element
{
public:
	Element();
	~Element();

public:
	virtual void Load();
	virtual void Start();
	virtual void Step();
	virtual void Update();
	virtual void Draw();
	
	//void Action(int posX, int posY, ElementType type);

protected:
	VECTOR pos;
	VECTOR move;

	bool active;
	bool m_IsTurn;

	int handle;
};


