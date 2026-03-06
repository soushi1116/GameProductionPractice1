#pragma once
#include "GameDefine.h"
#include "DxLib.h"
enum Attribute
{
	ATTR_NONE = 0,
	ATTR_FLOOR = 1,
	ATTR_GRASS = 3,
	ATTR_WOOD_BOX = 4,
	ATTR_BALLOON = 5,
	ATTR_BALLOON_FIRE = 6,
	ATTR_FIRE = 11,
	ATTR_WATER = 12,
	ATTR_THUNDER = 13,
	ATTR_WIND = 14,
	ATTR_GROUND = 15,
	ATTR_ICE = 16,
	ATTR_METAL = 17,
	ATTR_SPAWN = 20,
	ATTR_WARP_IN_A = 21,
	ATTR_WARP_OUT_A = 22,
	ATTR_WARP_IN_B = 23,
	ATTR_WARP_OUT_B = 24,
	ATTR_GOAL = 25,
	/*
	ATTR_ENEMY_STRAIGHT = 31,
	ATTR_ENEMY_TURRET = 32,
	ATTR_ENEMY_WALK = 33,
	ATTR_ENEMY_ = 34,
	ATTR_ENEMY_ = 35,
	ATTR_ENEMY_FLYCIRCLE = 36,
	ATTR_ENEMY_FLYCIRCLE2 = 37,
	*/
	ATTR_MAX
};

enum Reaction
{
	REACT_NONE = 0,
	REACT_EXTINGUISH,
	REACT_FREEZE,
	REACT_BURN_GRASS,
	REACT_BALLOON_UP,
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
void DrawGimmick(Attribute map[][MAP_W]);
void FinGimmick();
void FindSpawn(Attribute map[][MAP_W]);
void CheckEvent(Attribute map[][MAP_W]);



class Gimmick
{
public:
	Gimmick(){}
	~Gimmick(){}
	virtual void Load() = 0;
	virtual void Start() = 0;
	virtual void Step() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	VECTOR pos;
	VECTOR move;
	int handle;
	bool active;
};

