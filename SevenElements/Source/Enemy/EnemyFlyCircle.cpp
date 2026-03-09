#include "DxLib.h"
#include "EnemyFlyCircle.h"
#include <math.h>

// 角度
float circleAngle;

// X座標
int circleX;

// Y座標
int circleY;

// 画像
int circleHandle;



// 初期化
void InitEnemyFlyCircle()
{
    circleAngle = 0;

    circleHandle = LoadGraph("C:/工野/チーム制作　自作/プログラム/Enemy test/Data/Enemy/Death.png");
}



// 更新
void UpdateEnemyFlyCircle()
{
    circleAngle += 0.05f;

    circleX = 500 + (int)(cos(circleAngle) * 100);

    circleY = 300 + (int)(sin(circleAngle) * 100);
}



// 描画
void DrawEnemyFlyCircle()
{
    DrawGraph(circleX, circleY, circleHandle, TRUE);
}