#include "DxLib.h"
#include "EnemyWalk.h"
#include "../Camera/Camera.h"

// 敵データ
int walkX[ENEMY_WALK_MAX];
int walkY[ENEMY_WALK_MAX];
int walkDir[ENEMY_WALK_MAX];
static int leftLimit[ENEMY_WALK_MAX];
static int rightLimit[ENEMY_WALK_MAX];
ElementType enemyAttr[ENEMY_WALK_MAX];
int enemyType[ENEMY_WALK_MAX];
int walkWidth[ENEMY_WALK_MAX];
int walkHeight[ENEMY_WALK_MAX];
int enemyUse[ENEMY_WALK_MAX];
int walkHandle[ENEMY_WALK_MAX];

static int currentIndex = 0; // 敵追加用インデックス

// 汎用設定関数（座標・行動範囲・サイズ・タイプ・属性・画像を設定）
void SetEnemyWalk(
    int x, int y,
    int left, int right,
    int width, int height,
    int type,
    ElementType attr,
    const char* file
)
{
    if (currentIndex >= ENEMY_WALK_MAX) return;

    walkX[currentIndex] = x;
    walkY[currentIndex] = y;
    leftLimit[currentIndex] = left;
    rightLimit[currentIndex] = right;
    walkWidth[currentIndex] = width;
    walkHeight[currentIndex] = height;
    enemyType[currentIndex] = type;
    enemyAttr[currentIndex] = attr;
    walkHandle[currentIndex] = LoadGraph(file);
    walkDir[currentIndex] = 1;
    enemyUse[currentIndex] = TRUE;

    currentIndex++;
}

// 敵種類ごとの追加関数（出現位置と行動範囲だけ指定すればOK）
void AddMedusa(int x, int y, int left, int right)
{
    SetEnemyWalk(x, y, left, right, 45, 54, TYPE_NORMAL, ELEMENT_TYPE_NONE, "Data/Enemy/Medusa.png");
}

void AddTroll(int x, int y, int left, int right)
{
    SetEnemyWalk(x, y, left, right, 43, 42, TYPE_STOMPABLE, ELEMENT_TYPE_NONE, "Data/Enemy/Troll.png");
}

void AddFireSlime(int x, int y, int left, int right)
{
    SetEnemyWalk(x, y, left, right, 45, 42, TYPE_NORMAL, ELEMENT_TYPE_FIRE, "Data/Enemy/SlimeFire.png");
}

void AddThunderSlime(int x, int y, int left, int right)
{
    SetEnemyWalk(x, y, left, right, 45, 42, TYPE_NORMAL, ELEMENT_TYPE_THUNDER, "Data/Enemy/SlimeThunder.png");
}

void AddIceSlime(int x, int y, int left, int right)
{
    SetEnemyWalk(x, y, left, right, 45, 42, TYPE_NORMAL, ELEMENT_TYPE_ICE, "Data/Enemy/SlimeIce.png");
}

// 初期化（敵を直感的に配置）
void InitEnemyWalk()
{
    currentIndex = 0;

    // 初期位置X, 初期位置Y, 行動範囲限界左, 行動範囲限界右

    // メデューサ
    AddMedusa(100, 900, 100, 200);

    // トロール
    AddTroll(300, 900, 300, 500);

    // 火スライム
    AddFireSlime(600, 900, 600, 700);

    // 雷スライム
    AddThunderSlime(900, 900, 900, 1000);
    // 氷スライム
    AddIceSlime(1200, 900, 1200, 1300);
}

// 更新
void UpdateEnemyWalk()
{
    for (int i = 0; i < ENEMY_WALK_MAX; i++)
    {
        if (!enemyUse[i]) continue;

        walkX[i] += 2 * walkDir[i];

        if (walkX[i] < leftLimit[i]) walkDir[i] = 1;
        if (walkX[i] > rightLimit[i]) walkDir[i] = -1;
    }
}

// 描画
void DrawEnemyWalk()
{
    CameraData camera = GetCamera();

    for (int i = 0; i < ENEMY_WALK_MAX; i++)
    {
        if (!enemyUse[i]) continue;

        DrawGraph(walkX[i] - camera.posX, walkY[i] - camera.posY, walkHandle[i], TRUE);
    }
}

// 倒す
void KillEnemyWalk(int index)
{
    if (index < 0 || index >= ENEMY_WALK_MAX) return;
    enemyUse[index] = FALSE;
}

// 使用フラグ
int GetEnemyWalkUse(int index)
{
    if (index < 0 || index >= ENEMY_WALK_MAX) return FALSE;
    return enemyUse[index];
}

// 取得
float GetEnemyWalkX(int index)
{
    if (index < 0 || index >= ENEMY_WALK_MAX) return 0;
    return (float)walkX[index];
}

float GetEnemyWalkY(int index)
{
    if (index < 0 || index >= ENEMY_WALK_MAX) return 0;
    return (float)walkY[index];
}

int GetEnemyWalkWidth(int index)
{
    if (index < 0 || index >= ENEMY_WALK_MAX) return 0;
    return walkWidth[index];
}

int GetEnemyWalkHeight(int index)
{
    if (index < 0 || index >= ENEMY_WALK_MAX) return 0;
    return walkHeight[index];
}

ElementType GetEnemyWalkAttr(int index)
{
    if (index < 0 || index >= ENEMY_WALK_MAX) return ELEMENT_TYPE_NONE;
    return enemyAttr[index];
}

int GetEnemyWalkType(int index)
{
    if (index < 0 || index >= ENEMY_WALK_MAX) return TYPE_NORMAL;
    return enemyType[index];
}