#include "DxLib.h"
#include "Gimmick.h"

Gimmick::Gimmick()
{
	pos.x = 0.0f;
	pos.y = 0.0f;
	move.x = 0.0f;
	move.x = 0.0f;

	handle = 0;

	active = false;
}

Gimmick::~Gimmick()
{
	DeleteGraph(handle);
}

void Gimmick::Load()
{

}

void Gimmick::Start()
{

}

void Gimmick::Step()
{

}

void Gimmick::Update()
{

}

void Gimmick::Draw()
{

}



