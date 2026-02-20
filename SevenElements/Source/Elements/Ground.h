#pragma once
#include "DxLib.h"
#include "Elements.h"

#define GROUND_MAX 32
#define GROUND_WIDTH (330)
#define GROUND_HEIGHT (64)

class Ground : public Element
{
public:
	Ground();
	~Ground();

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
