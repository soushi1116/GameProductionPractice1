#include "DxLib.h"
#include "EnemyFlyCircle2.h"
#include <math.h>

// 時間（波用）
float waveTime;

// X座標
int waveX;

// Y座標
int waveY;

// 基準Y座標
int baseY;

// 移動速度（＋右、－左）
int moveSpeed;

// 画像
int waveHandle;



void InitEnemyFlyCircle2()
{
    waveTime = 0;

    waveX = 600;
    baseY = 300;
    waveY = baseY;

    moveSpeed = -4;

    waveHandle = LoadGraph("C:/工野/チーム制作　自作/プログラム/Enemy test/Data/Enemy/Death.png");
}

void UpdateEnemyFlyCircle2()
{
    waveTime += 0.1f;

    waveX += moveSpeed;

    // sin波で上下
    waveY = baseY + (int)(sin(waveTime) * 40);

    // 左端で折り返し
    if (waveX <= 0)
    {
        moveSpeed = 4;    // 右へ
    }

    // 右端で折り返し
    if (waveX >= 600)
    {
        moveSpeed = -4;   // 左へ
    }
}
void DrawEnemyFlyCircle2()
{
    DrawGraph(waveX, waveY, waveHandle, TRUE);
}
