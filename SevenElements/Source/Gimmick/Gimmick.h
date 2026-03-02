#pragma once
#include "GameDefine.h"
#include "DxLib.h"
enum Attribute
{
	ATTR_NONE = 0,
	ATTR_FIRE = 11,
	ATTR_WATER = 12,
	ATTR_THUNDER = 13,
	ATTR_WIND = 14,
	ATTR_GROUND = 15,
	ATTR_ICE = 16,
	ATTR_METAL = 17,
	ATTR_GRASS = 5,
	ATTR_SPAWN = 20,
	ATTR_WARP_IN_A = 21,
	ATTR_WARP_OUT_A = 22,
	ATTR_WARP_IN_B = 23,
	ATTR_WARP_OUT_B = 24,
	ATTR_GOAL = 25,
	ATTR_MAX
};

enum Reaction
{
	REACT_NONE = 0,
	REACT_EXTINGUISH,
	REACT_FREEZE,
	REACT_BURN_GRASS,
	REACT_CONDUCT
};

enum GimmickType
{
	GIMMICK_TYPE_NONE = -1,
	GIMMICK_TYPE_TREE,
	GIMMICK_TYPE_AIRBALLOON,
	GIMMICK_TYPE_WOODBLOCK,
	GIMMICK_TYPE_MAX,
};

void InitGimmick();
void LoadGimmick();
void StartGimmick(Attribute map[][MAP_W]);
void StepGimmick(int xA, int yA, int xB, int yB, Attribute map[][MAP_W]);
void DrawGimmick();
//void FinGimmick();
void FindSpawn(Attribute map[][MAP_W]);
//void CheckEvent(Attribute map[][MAP_W]);

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

