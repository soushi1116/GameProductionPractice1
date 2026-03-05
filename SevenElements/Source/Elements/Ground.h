#pragma once
#include "DxLib.h"
#include "Elements.h"

#define GROUND_MAX 512
#define GROUND_WIDTH (25)
#define GROUND_HEIGHT (25)
#define GROUND_SPAWN_NUM (5)
#define GROUND_SPAWN_INTERVAL (60)
#define GROUND_SPAWN_OFFSET (1.1f)

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

	void GroundHitBlock(int index);

	bool IsActive() { return active; }

	VECTOR GetPos() { return pos; }

	VECTOR GetMove() { return move; }

protected:
	bool m_IsAir;
};
