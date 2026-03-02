#pragma once

struct BoxCollision
{
	float posX;
	float posY;
	float width;
	float height;
};

bool CheckSquareSquare(float squareA_PosX, float squareA_PosY, float squareA_Width, float squareA_Height,
	float squareB_PosX, float squareB_PosY, float squareB_Width, float squareB_Height);

void CheckCollision();