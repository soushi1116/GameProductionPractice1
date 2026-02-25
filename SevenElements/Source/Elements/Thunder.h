#pragma once
#include "DxLib.h"
#include "Elements.h"

#define THUNDER_MAX 32
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

	const bool IsActive();

	VECTOR GetPos();

protected:

};
