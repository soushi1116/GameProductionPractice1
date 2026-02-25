#pragma once
#include "DxLib.h"
#include "Elements.h"

#define IRON_MAX 32
#define IRON_WIDTH (64)
#define IRON_HEIGHT (64)

class Iron : public Element
{
public:
	Iron();
	~Iron();

public:
	void Load() override;
	void Start() override;
	void Step() override;
	void Update() override;
	void Draw() override;

	void Spawn(float posX, float posY, bool isTurn);

	void IronHitBlock(int index);
	void IronHitIron(int indexA, int indexB, float posY);

	const bool IsActive();

	VECTOR GetPos();

protected:
	bool m_Randing;
};

