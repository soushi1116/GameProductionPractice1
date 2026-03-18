#pragma once
#include "DxLib.h"
#include "Gimmick.h"

#define NEEDLE_MAX 32
#define NEEDLE_WIDTH (50)
#define NEEDLE_HEIGHT (43)

class Needle : public Gimmick
{
public:
	Needle();
	~Needle();
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