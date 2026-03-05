#pragma once
#include "DxLib.h"
#include "Elements.h"

#define FIRE_MAX 64
#define FIRE_WIDTH (64)
#define FIRE_HEIGHT (64)

class Fire : public Element
{
public:
	Fire();
	~Fire();

public:
	void Load() override;
	void Start() override;
	void Step() override;
	void Update() override;
	void Draw() override;

	void Spawn(float posX, float posY, bool isTurn);

	void FireDelete() { active = false; }

	bool IsActive() { return active;  }

	VECTOR GetPos() { return pos;  }

protected:

};
