#pragma once
#include "DxLib.h"
#include "Elements.h"

#define WATER_MAX 32
#define WATER_WIDTH (479)
#define WATER_HEIGHT (32)

class Water : public Element
{
public:
	Water();
	~Water();

public:
	void Load() override;
	void Start() override;
	void Step() override;
	void Update() override;
	void Draw() override;

	void Spawn(float posX, float posY, bool isTurn);

	bool IsActive() { return active;  }

protected:

};
