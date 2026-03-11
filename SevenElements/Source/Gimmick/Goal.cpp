#include "Goal.h"
#include "DxLib.h"
#include "../Camera/Camera.h"

Goal::Goal()
{
	pos.x = 0.0f;
	pos.y = 0.0f;

	handle = 0;

	active = false;
}

Goal::~Goal()
{
	DeleteGraph(handle);
}

void Goal::Load()
{
	handle = LoadGraph("Data/Gimmick/Goal.png");
}

void Goal::Start()
{

}

void Goal::Step()
{

}

void Goal::Update()
{

}

void Goal::Draw()
{
	if (!active) return;

	CameraData camera = GetCamera();

	DrawGraph(pos.x - camera.posX, pos.y - camera.posY, handle, TRUE);
}

void Goal::Spawn(float posX, float posY)
{
	if (!active)
	{
		active = true;

		pos.x = posX;
		pos.y = posY;
	}
}
