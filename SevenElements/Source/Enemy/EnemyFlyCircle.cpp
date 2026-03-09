#include "DxLib.h"
#include "EnemyFlyCircle.h"
#include "../Camera/Camera.h"
#include <math.h>

float circleAngle;

int circleX;
int circleY;

int centerX;
int centerY;

int circleHandle;

void InitEnemyFlyCircle()
{
    circleAngle = 0;

    centerX = 500;
    centerY = 300;

    circleHandle = LoadGraph("Data/Enemy/Death.png");
}

void UpdateEnemyFlyCircle()
{
    circleAngle += 0.05f;

    circleX = centerX + (int)(cos(circleAngle) * 100);
    circleY = centerY + (int)(sin(circleAngle) * 100);
}

void DrawEnemyFlyCircle()
{
    CameraData camera = GetCamera();

    DrawGraph(circleX - camera.posX, circleY - camera.posY, circleHandle, TRUE);
}