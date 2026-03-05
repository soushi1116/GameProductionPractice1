#pragma once
#include "DxLib.h"
#include "Elements.h"

#define ICE_MAX 64
#define ICE_WIDTH (256)
#define ICE_HEIGHT (256)

class Ice : public Element
{
public:
	Ice();
	~Ice();

public:
	void Load() override;
	void Start() override;
	void Step() override;
	void Update() override;
	void Draw() override;

	void Spawn(float posX, float posY, bool isTurn);

	bool IsActive() { return active;  }

	VECTOR GetPos() { return pos; }

protected:
	int timer;
	double size;
};
