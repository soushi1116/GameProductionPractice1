#pragma once
#include "../Elements/Elements.h"

#define ENEMY_WALK_MAX 10

// タイプ
enum EnemyType
{
    TYPE_NORMAL,     // 踏めない
    TYPE_STOMPABLE   // 踏める
};

// 基本
void InitEnemyWalk();
void UpdateEnemyWalk();
void DrawEnemyWalk();

// 個別生成
void SetEnemyWalk(
    int index,
    int x, int y,
    int left, int right,
    int width, int height,
    int type,
    ElementType attr,
    const char* file
);

// 使用フラグ
int GetEnemyWalkUse(int index);

// 取得
float GetEnemyWalkX(int index);
float GetEnemyWalkY(int index);
int GetEnemyWalkWidth(int index);
int GetEnemyWalkHeight(int index);

// 特性
ElementType GetEnemyWalkAttr(int index);
int GetEnemyWalkType(int index);

// 倒す
void KillEnemyWalk(int index);