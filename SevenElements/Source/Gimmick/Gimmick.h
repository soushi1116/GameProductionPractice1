#pragma once
#include "GameDefine.h"
#include "DxLib.h"

enum GimmickType
{
	GIMMICK_TYPE_NONE = -1,
	GIMMICK_TYPE_TREE,
	GIMMICK_TYPE_AIRBALLOON,
	GIMMICK_TYPE_WOODBLOCK,
	GIMMICK_TYPE_FIRE,
	GIMMICK_TYPE_WARP,
	GIMMICK_TYPE_GOAL,
	GIMMICK_TYPE_MAX,
};

class Gimmick
{
public:
	Gimmick();
	~Gimmick();
public:
	virtual void Load();
	virtual void Start();
	virtual void Step();
	virtual void Update();
	virtual void Draw();

protected:
	VECTOR pos;
	VECTOR move;
	int handle;
	bool active;
};

