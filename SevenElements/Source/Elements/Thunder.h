#pragma once
#include "DxLib.h"
#include "Elements.h"

#define THUNDER_MAX 512
#define THUNDER_WIDTH (64)
#define THUNDER_HEIGHT (161)

class Thunder : public Element
{
public:
	Thunder();
	~Thunder();

public:
	void Load() override;
	void Start() override;
	void Step() override;
	void Update() override;
	void Draw() override;

	void Spawn(float posX, float posY, bool isTurn);

	bool IsActive() { return active; }

	VECTOR GetPos() { return pos; }

protected:

};
