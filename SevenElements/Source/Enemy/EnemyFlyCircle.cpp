#include "DxLib.h"
#include "EnemyFlyCircle.h"
#include "../Camera/Camera.h"
#include <math.h>

#define ENEMY_CIRCLE_MAX 2

float circleAngle[ENEMY_CIRCLE_MAX];

int circleX[ENEMY_CIRCLE_MAX];
int circleY[ENEMY_CIRCLE_MAX];

int centerX[ENEMY_CIRCLE_MAX];
int centerY[ENEMY_CIRCLE_MAX];

// サイズ
int circleWidth[ENEMY_CIRCLE_MAX];
int circleHeight[ENEMY_CIRCLE_MAX];

int circleHandle;



// 初期化
void InitEnemyFlyCircle()
{
    circleHandle = LoadGraph("Data/Enemy/Gargoyle.png");

    // ----- 円の中心位置 -----
    centerX[0] = 1000;
    centerY[0] = 500;

    // ----- 初期化 -----
    for (int i = 0; i < ENEMY_CIRCLE_MAX; i++)
    {
        circleAngle[i] = 0;

        circleX[i] = centerX[i];
        circleY[i] = centerY[i];

        // サイズ（ここでまとめる）
        circleWidth[i] = 63;
        circleHeight[i] = 34;
    }
}



// 更新
void UpdateEnemyFlyCircle()
{
    for (int i = 0; i < ENEMY_CIRCLE_MAX; i++)
    {
        circleAngle[i] += 0.05f;

        circleX[i] = centerX[i] + (int)(cos(circleAngle[i]) * 100);
        circleY[i] = centerY[i] + (int)(sin(circleAngle[i]) * 100);
    }
}



// 描画
void DrawEnemyFlyCircle()
{
    CameraData camera = GetCamera();

    for (int i = 0; i < ENEMY_CIRCLE_MAX; i++)
    {
        DrawGraph(
            circleX[i] - camera.posX,
            circleY[i] - camera.posY,
            circleHandle,
            TRUE
        );
    }
}


// 外部取得用（超重要）

// X座標
float GetEnemyFlyCircleX(int index)
{
    if (index < 0 || index >= ENEMY_CIRCLE_MAX) return 0.0f;

    return (float)circleX[index];
}


// Y座標
float GetEnemyFlyCircleY(int index)
{
    if (index < 0 || index >= ENEMY_CIRCLE_MAX) return 0.0f;

    return (float)circleY[index];
}


// 幅
int GetEnemyFlyCircleWidth(int index)
{
    if (index < 0 || index >= ENEMY_CIRCLE_MAX) return 0;

    return circleWidth[index];
}


// 高さ
int GetEnemyFlyCircleHeight(int index)
{
    if (index < 0 || index >= ENEMY_CIRCLE_MAX) return 0;

    return circleHeight[index];
}