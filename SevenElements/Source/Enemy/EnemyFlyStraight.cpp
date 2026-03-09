#include "DxLib.h"
#include "EnemyFlyStraight.h"

// X座標
int straightX;

// Y座標
int straightY;

// 方向
int straightDir;

// 画像
int straightHandle;



// 初期化
void InitEnemyFlyStraight()
{
    straightX = 0;

    straightY = 200;

    straightDir = 1;

    straightHandle = LoadGraph("Data/Enemy/Death.png");
}

// 更新
void UpdateEnemyFlyStraight()
{
    // 移動
    straightX += 4 * straightDir;


    // 右端で折り返し
    if (straightX > 600)
    {
        straightDir = -1;
    }


    // 左端で折り返し
    if (straightX < 0)
    {
        straightDir = 1;
    }
}



// 描画
void DrawEnemyFlyStraight()
{
    DrawGraph(straightX, straightY, straightHandle, TRUE);
}