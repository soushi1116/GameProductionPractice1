#include "Needle.h"
#include "DxLib.h"
#include "../Camera/Camera.h"

Needle::Needle()
{
	pos.x = 0.0f;
	pos.y = 0.0f;

	handle = 0;

	active = false;
}

Needle::~Needle()
{
	DeleteGraph(handle);
}

void Needle::Load()
{
	handle = LoadGraph("Data/Gimmick/Needle.png");
}

void Needle::Start()
{

}

void Needle::Step()
{

}

void Needle::Update()
{

}

void Needle::Draw()
{
	if (!active) return;

	CameraData camera = GetCamera();

	DrawGraph(pos.x - camera.posX, pos.y - camera.posY, handle, TRUE);
}

void Needle::Spawn(float posX, float posY)
{
	if (!active)
	{
		active = true;

		pos.x = posX;
		pos.y = posY;
	}
}
