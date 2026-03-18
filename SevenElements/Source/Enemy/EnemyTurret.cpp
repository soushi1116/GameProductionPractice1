#include "DxLib.h"
#include "EnemyTurret.h"
#include "../Camera/Camera.h"


// 砲台

// 位置
int turretX[TURRET_MAX];
int turretY[TURRET_MAX];

// 向き
int turretDir[TURRET_MAX];

// タイマー
int shootTimer[TURRET_MAX];

// サイズ（追加）
int turretWidth[TURRET_MAX];
int turretHeight[TURRET_MAX];

// 画像
int turretHandle;



// 弾

float bulletX[BULLET_MAX];
float bulletY[BULLET_MAX];

float bulletSpeedX[BULLET_MAX];
float bulletSpeedY[BULLET_MAX];

int bulletUse[BULLET_MAX];

// サイズ
int bulletSize[BULLET_MAX];


// 初期化

void InitEnemyTurret()
{
    turretHandle = LoadGraph("Data/Enemy/Magic.png");

    // 配置
    turretX[0] = 250;
    turretY[0] = 900;
    turretDir[0] = 1;

    turretX[1] = 1000;
    turretY[1] = 900;
    turretDir[1] = -1;


    for (int i = 0; i < TURRET_MAX; i++)
    {
        shootTimer[i] = 0;

        turretWidth[i] = 43;
        turretHeight[i] = 48;
    }

    for (int i = 0; i < BULLET_MAX; i++)
    {
        bulletUse[i] = FALSE;
        bulletSize[i] = 10;
    }
}



// 弾発射
void ShootBullet(int turretIndex)
{
    for (int i = 0; i < BULLET_MAX; i++)
    {
        if (bulletUse[i] == FALSE)
        {
            bulletUse[i] = TRUE;

            bulletX[i] = turretX[turretIndex];
            bulletY[i] = turretY[turretIndex];

            bulletSpeedX[i] = 5 * turretDir[turretIndex];
            bulletSpeedY[i] = -8;

            break;
        }
    }
}



// 更新
void UpdateEnemyTurret()
{
    // 砲台
    for (int t = 0; t < TURRET_MAX; t++)
    {
        shootTimer[t]++;

        if (shootTimer[t] > 60)
        {
            ShootBullet(t);
            shootTimer[t] = 0;
        }
    }

    // 弾
    for (int i = 0; i < BULLET_MAX; i++)
    {
        if (bulletUse[i] == TRUE)
        {
            bulletX[i] += bulletSpeedX[i];
            bulletY[i] += bulletSpeedY[i];

            bulletSpeedY[i] += 0.3f;

            if (bulletY[i] > 950 || bulletX[i] < -200 || bulletX[i] > 2000)
            {
                bulletUse[i] = FALSE;
            }
        }
    }
}



// 描画
void DrawEnemyTurret()
{
    CameraData camera = GetCamera();

    // 砲台
    for (int i = 0; i < TURRET_MAX; i++)
    {
        if (turretDir[i] == 1)
        {
            DrawTurnGraph(
                turretX[i] - camera.posX,
                turretY[i] - camera.posY,
                turretHandle,
                TRUE
            );
        }
        else
        {
            DrawGraph(
                turretX[i] - camera.posX,
                turretY[i] - camera.posY,
                turretHandle,
                TRUE
            );
        }
    }

    // 弾
    for (int i = 0; i < BULLET_MAX; i++)
    {
        if (bulletUse[i] == TRUE)
        {
            DrawCircle(
                (int)bulletX[i] - camera.posX,
                (int)bulletY[i] - camera.posY,
                bulletSize[i],
                GetColor(255, 0, 0),
                TRUE
            );
        }
    }
}



// 取得関数（当たり判定用）

// --- 砲台 ---
float GetEnemyTurretX(int index)
{
    if (index < 0 || index >= TURRET_MAX) return 0;
    return (float)turretX[index];
}

float GetEnemyTurretY(int index)
{
    if (index < 0 || index >= TURRET_MAX) return 0;
    return (float)turretY[index];
}

int GetEnemyTurretWidth(int index)
{
    if (index < 0 || index >= TURRET_MAX) return 0;
    return turretWidth[index];
}

int GetEnemyTurretHeight(int index)
{
    if (index < 0 || index >= TURRET_MAX) return 0;
    return turretHeight[index];
}


// --- 弾 ---
int GetEnemyTurretBulletNum()
{
    return BULLET_MAX;
}

int GetEnemyTurretBulletUse(int index)
{
    if (index < 0 || index >= BULLET_MAX) return FALSE;
    return bulletUse[index];
}

float GetEnemyTurretBulletX(int index)
{
    if (index < 0 || index >= BULLET_MAX) return 0;
    return bulletX[index];
}

float GetEnemyTurretBulletY(int index)
{
    if (index < 0 || index >= BULLET_MAX) return 0;
    return bulletY[index];
}

int GetEnemyTurretBulletSize(int index)
{
    if (index < 0 || index >= BULLET_MAX) return 0;
    return bulletSize[index];
}