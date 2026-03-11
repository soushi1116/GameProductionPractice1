#pragma once
#include "DxLib.h"
#include "Gimmick.h"
#include "../Animation/Animation.h"

#define WOODBLOCK_MAX 32
#define WOODBLOCK_WIDTH (50)
#define WOODBLOCK_HEIGHT (50)

class WoodBlock : public Gimmick
{
public:
	WoodBlock();
	~WoodBlock();

public:
	void Load() override;
	void Start() override;
	void Step() override;
	void Update() override;
	void Draw() override;

	void Spawn(float posX, float posY);

	void WoodBlockHitBlock(int index);

	void WoodBlockHitWind(int index);

	const bool IsActive() { return active; }

	VECTOR GetPos() { return pos; }

protected:

};

