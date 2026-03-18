#include "DxLib.h"
#include "EnemyFlyCircle2.h"
#include "../Camera/Camera.h"
#include <math.h>

#define ENEMY_WAVE_MAX 3


// 時間
float waveTime[ENEMY_WAVE_MAX];

// 座標
int waveX[ENEMY_WAVE_MAX];
int waveY[ENEMY_WAVE_MAX];

// 初期位置
int startX[ENEMY_WAVE_MAX];
int startY[ENEMY_WAVE_MAX];

// 基準Y
int baseY[ENEMY_WAVE_MAX];

// 横移動
int moveSpeed[ENEMY_WAVE_MAX];
int moveRange[ENEMY_WAVE_MAX];

// 波
int waveHeight[ENEMY_WAVE_MAX];
float waveSpeed[ENEMY_WAVE_MAX];

// サイズ（追加）
int waveWidth[ENEMY_WAVE_MAX];
int waveHeightSize[ENEMY_WAVE_MAX];

// 画像
int waveHandle;



// 初期化
void InitEnemyFlyCircle2()
{
    waveHandle = LoadGraph("Data/Enemy/Death.png");

    // ----- 敵ごとの設定 -----

    startX[0] = 600;
    startY[0] = 300;
    moveRange[0] = 300;
    waveHeight[0] = 40;
    waveSpeed[0] = 0.1f;

    // ----- 初期化 -----
    for (int i = 0; i < ENEMY_WAVE_MAX; i++)
    {
        waveTime[i] = 0;

        waveX[i] = startX[i];
        baseY[i] = startY[i];
        waveY[i] = baseY[i];

        moveSpeed[i] = -4;

        // サイズ
        waveWidth[i] = 41;
        waveHeightSize[i] = 50;
    }
}



// 更新
void UpdateEnemyFlyCircle2()
{
    for (int i = 0; i < ENEMY_WAVE_MAX; i++)
    {
        waveTime[i] += waveSpeed[i];

        waveX[i] += moveSpeed[i];

        waveY[i] = baseY[i] + (int)(sin(waveTime[i]) * waveHeight[i]);

        if (waveX[i] <= startX[i] - moveRange[i])
        {
            moveSpeed[i] = 4;
        }

        if (waveX[i] >= startX[i] + moveRange[i])
        {
            moveSpeed[i] = -4;
        }
    }
}



// 描画
void DrawEnemyFlyCircle2()
{
    CameraData camera = GetCamera();

    for (int i = 0; i < ENEMY_WAVE_MAX; i++)
    {
        DrawGraph(
            waveX[i] - camera.posX,
            waveY[i] - camera.posY,
            waveHandle,
            TRUE
        );
    }
}



//
// ===== 外部取得用 =====
//

// X
float GetEnemyFlyCircle2X(int index)
{
    if (index < 0 || index >= ENEMY_WAVE_MAX) return 0.0f;
    return (float)waveX[index];
}

// Y
float GetEnemyFlyCircle2Y(int index)
{
    if (index < 0 || index >= ENEMY_WAVE_MAX) return 0.0f;
    return (float)waveY[index];
}

// 幅
int GetEnemyFlyCircle2Width(int index)
{
    if (index < 0 || index >= ENEMY_WAVE_MAX) return 0;
    return waveWidth[index];
}

// 高さ
int GetEnemyFlyCircle2Height(int index)
{
    if (index < 0 || index >= ENEMY_WAVE_MAX) return 0;
    return waveHeightSize[index];
}