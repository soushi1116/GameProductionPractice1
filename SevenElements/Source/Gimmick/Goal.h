#pragma once
#include "DxLib.h"
#include "Gimmick.h"

#define GOAL_MAX 32
#define GOAL_WIDTH (50)
#define GOAL_HEIGHT (100)

class Goal : public Gimmick
{
public:
	Goal();
	~Goal();
public:
	void Load();
	void Start();
	void Step();
	void Update();
	void Draw();

	void Spawn(float posX, float posY);

	VECTOR GetPos() { return pos; }

	bool IsActive() { return active; }

protected:

};