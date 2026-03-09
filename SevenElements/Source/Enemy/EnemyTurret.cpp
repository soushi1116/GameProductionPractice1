#include "DxLib.h"
#include "EnemyTurret.h"

#define BULLET_MAX 50


// 砲台の位置

// X座標
int turretX;

// Y座標
int turretY;

// 画像
int turretHandle;


// 弾の情報

// 弾のX座標
float bulletX[BULLET_MAX];

// 弾のY座標
float bulletY[BULLET_MAX];

// 弾のX速度
float bulletSpeedX[BULLET_MAX];

// 弾のY速度
float bulletSpeedY[BULLET_MAX];

// 弾が存在するか
int bulletUse[BULLET_MAX];



// 発射用タイマー
int shootTimer;


// 初期化

void InitEnemyTurret()
{
    turretX = 600;

    turretY = 400;

    turretHandle = LoadGraph("Data/Enemy/Death.png");


    shootTimer = 0;


    // 弾を全部未使用にする
    for (int i = 0; i < BULLET_MAX; i++)
    {
        bulletUse[i] = FALSE;
    }
}


// 弾を撃つ

void ShootBullet()
{
    for (int i = 0; i < BULLET_MAX; i++)
    {
        if (bulletUse[i] == FALSE)
        {
            bulletUse[i] = TRUE;

            bulletX[i] = turretX;

            bulletY[i] = turretY;

            bulletSpeedX[i] = -5;

            bulletSpeedY[i] = -8;

            break;
        }
    }
}


// 更新

void UpdateEnemyTurret()
{

    // 発射タイマー
    shootTimer++;

    if (shootTimer > 60)
    {
        ShootBullet();

        shootTimer = 0;
    }



    // 弾の移動
    for (int i = 0; i < BULLET_MAX; i++)
    {
        if (bulletUse[i] == TRUE)
        {

            bulletX[i] += bulletSpeedX[i];

            bulletY[i] += bulletSpeedY[i];


            // 重力（下に落ちる）
            bulletSpeedY[i] += 0.3f;



            // 画面外で消す
            if (bulletY[i] > 600)
            {
                bulletUse[i] = FALSE;
            }

        }
    }

}


// 描画

void DrawEnemyTurret()
{

    // 砲台
    DrawGraph(turretX, turretY, turretHandle, TRUE);



    // 弾
    for (int i = 0; i < BULLET_MAX; i++)
    {
        if (bulletUse[i] == TRUE)
        {
            DrawCircle(

                (int)bulletX[i],

                (int)bulletY[i],

                5,

                GetColor(255, 0, 0),

                TRUE

            );
        }
    }

}