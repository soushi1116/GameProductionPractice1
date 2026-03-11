#include "Warp.h"
#include "DxLib.h"
#include "../Camera/Camera.h"

Warp::Warp()
{
	pos.x = 0.0f;
	pos.y = 0.0f;

	handle = 0;

	active = false;
}

Warp::~Warp()
{
	DeleteGraph(handle);
}

void Warp::Load()
{
	handle = LoadGraph("Data/Gimmick/Warp.png");
}

void Warp::Start()
{

}

void Warp::Step()
{

}

void Warp::Update()
{

}

void Warp::Draw()
{
	if (!active) return;

	CameraData camera = GetCamera();

	DrawGraph(pos.x - camera.posX, pos.y - camera.posY, handle, TRUE);
}

void Warp:: Spawn(float posX, float posY)
{
	if (!active)
	{
		active = true;

		pos.x = posX;
		pos.y = posY;
	}
}
