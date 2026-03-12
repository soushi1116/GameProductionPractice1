#pragma once
#include "DxLib.h"
#include "Gimmick.h"
#include "../Animation/Animation.h"

#define MOVEBLOCK_MAX 32
#define MOVEBLOCK_WIDTH (200)
#define MOVEBLOCK_HEIGHT (50)

class MoveBlock : public Gimmick
{
public:
	MoveBlock();
	~MoveBlock();

public:
	void Load() override;
	void Start() override;
	void Step() override;
	void Update() override;
	void Draw() override;

	void Spawn(float posX, float posY);

	const bool IsActive() { return active; }

	VECTOR GetPos() { return pos; }

	VECTOR GetMove() { return move; }

protected:
	float m_MinPosY;
	float m_MaxPosY;

	enum MoveState
	{
		MOVE_STOP,
		MOVE_UP,
		MOVE_DOWN,
	};

	MoveState moveState;
};

