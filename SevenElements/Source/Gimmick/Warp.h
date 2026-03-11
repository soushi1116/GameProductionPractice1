#pragma once
#include "DxLib.h"
#include "Gimmick.h"

#define WARP_MAX 32
#define WARP_WIDTH (50)
#define WARP_HEIGHT (100)

class Warp : public Gimmick
{
public:
	Warp();
	~Warp();
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