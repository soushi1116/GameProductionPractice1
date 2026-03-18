#include "DxLib.h"
#include "EnemyFlyStraight.h"
#include "../Camera/Camera.h"

// X座標
int straightX[ENEMY_STRAIGHT_MAX];

// Y座標
int straightY[ENEMY_STRAIGHT_MAX];

// 方向
int straightDir[ENEMY_STRAIGHT_MAX];

// 移動範囲
static int leftLimit[ENEMY_STRAIGHT_MAX];
static int rightLimit[ENEMY_STRAIGHT_MAX];

// サイズ（追加）
int straightWidth[ENEMY_STRAIGHT_MAX];
int straightHeight[ENEMY_STRAIGHT_MAX];

// 画像
int straightHandle;



// 初期化
void InitEnemyFlyStraight()
{
    straightHandle = LoadGraph("Data/Enemy/Ghost.png");

    // 位置と範囲
    straightX[0] = 0;
    straightY[0] = 200;
    leftLimit[0] = 0;
    rightLimit[0] = 200;

    straightX[1] = 150;
    straightY[1] = 120;
    leftLimit[1] = 150;
    rightLimit[1] = 350;

    for (int i = 0; i < ENEMY_STRAIGHT_MAX; i++)
    {
        straightDir[i] = 1;

        // サイズ設定
        straightWidth[i] = 43;
        straightHeight[i] = 41;
    }
}



// 更新
void UpdateEnemyFlyStraight()
{
    for (int i = 0; i < ENEMY_STRAIGHT_MAX; i++)
    {
        straightX[i] += 4 * straightDir[i];

        if (straightX[i] > rightLimit[i])
        {
            straightDir[i] = -1;
        }

        if (straightX[i] < leftLimit[i])
        {
            straightDir[i] = 1;
        }
    }
}



// 描画
void DrawEnemyFlyStraight()
{
    CameraData camera = GetCamera();

    for (int i = 0; i < ENEMY_STRAIGHT_MAX; i++)
    {
        DrawGraph(
            straightX[i] - camera.posX,
            straightY[i] - camera.posY,
            straightHandle,
            TRUE
        );
    }
}



// 取得関数

// X
float GetEnemyFlyStraightX(int index)
{
    if (index < 0 || index >= ENEMY_STRAIGHT_MAX) return 0;
    return (float)straightX[index];
}

// Y
float GetEnemyFlyStraightY(int index)
{
    if (index < 0 || index >= ENEMY_STRAIGHT_MAX) return 0;
    return (float)straightY[index];
}

// 幅
int GetEnemyFlyStraightWidth(int index)
{
    if (index < 0 || index >= ENEMY_STRAIGHT_MAX) return 0;
    return straightWidth[index];
}

// 高さ
int GetEnemyFlyStraightHeight(int index)
{
    if (index < 0 || index >= ENEMY_STRAIGHT_MAX) return 0;
    return straightHeight[index];
}