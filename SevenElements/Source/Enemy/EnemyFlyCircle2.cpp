#include "DxLib.h"
#include "EnemyFlyCircle2.h"
#include "../Camera/Camera.h"
#include <math.h>

// 時間（波用）
float waveTime;

// X座標
int waveX;

// Y座標
int waveY;

// 初期位置
int startX;
int startY;

// 基準Y座標
int baseY;

// 移動速度（＋右、－左）
int moveSpeed;

// 画像
int waveHandle;


void InitEnemyFlyCircle2()
{
    waveTime = 0;

    // 初期位置（ここを変更すれば配置を変えられる）
    startX = 600;
    startY = 300;

    waveX = startX;
    baseY = startY;
    waveY = baseY;

    moveSpeed = -4;

    waveHandle = LoadGraph("Data/Enemy/Death.png");
}

void UpdateEnemyFlyCircle2()
{
    waveTime += 0.1f;

    waveX += moveSpeed;

    // sin波で上下
    waveY = baseY + (int)(sin(waveTime) * 40);

    // 左端で折り返し
    if (waveX <= startX - 300)
    {
        moveSpeed = 4;
    }

    // 右端で折り返し
    if (waveX >= startX + 300)
    {
        moveSpeed = -4;
    }
}

void DrawEnemyFlyCircle2()
{
    CameraData camera = GetCamera();

    DrawGraph(waveX - camera.posX, waveY - camera.posY, waveHandle, TRUE);
}