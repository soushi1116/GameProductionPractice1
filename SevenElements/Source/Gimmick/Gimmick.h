#pragma once
#include "DxLib.h"

#define GIMMICK_MAX 1024

enum GimmickType
{
	GIMMICK_TYPE_NONE = -1,
	GIMMICK_TYPE_TREE,
	GIMMICK_TYPE_AIRBALLOON,
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

	bool active;

	int handle;
};


