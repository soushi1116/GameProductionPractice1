#pragma once
#include "DxLib.h"
#include "Elements.h"

#define THONDER_MAX 1240

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
	void Spawn(float posX, float posY);

	bool IsActive() { return active;  }

protected:
	VECTOR pos;
	VECTOR move;

};
