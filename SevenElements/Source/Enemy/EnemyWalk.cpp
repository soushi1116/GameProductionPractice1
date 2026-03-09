#include "DxLib.h"
#include "EnemyWalk.h"

// 歩く敵のX座標
int walkX;

// 歩く敵のY座標
int walkY;

// 方向（1=右、-1=左）
int walkDir;

// 画像ハンドル
int walkHandle;



// 初期化
void InitEnemyWalk()
{
    walkX = 100;

    walkY = 400;

    walkDir = 1;

    walkHandle = LoadGraph("Data/Enemy/Death.png");
}



// 更新
void UpdateEnemyWalk()
{
    // 移動
    walkX += 2 * walkDir;


    // 端で折り返し
    if (walkX < 0)
    {
        walkDir = 1;
    }

    if (walkX > 300)
    {
        walkDir = -1;
    }
}



// 描画
void DrawEnemyWalk()
{
    DrawGraph(walkX, walkY, walkHandle, TRUE);
}