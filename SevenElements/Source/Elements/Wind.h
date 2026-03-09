#pragma once
#include "DxLib.h"
#include "Elements.h"

#define WIND_MAX 512
#define WIND_WIDTH (217)
#define WIND_HEIGHT (128)

class Wind : public Element
{
public:
	Wind();
	~Wind();

public:
	void Load() override;
	void Start() override;
	void Step() override;
	void Update() override;
	void Draw() override;

	void Spawn(float posX, float posY, bool isTurn);

	void WindDelete() { active = false; }

	bool IsActive() { return active; }

	VECTOR GetPos() { return pos; }

protected:

};
