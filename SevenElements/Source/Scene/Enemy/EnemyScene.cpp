#include "EnemyScene.h"
#include "../../Enemy/EnemyFlyCircle.h"
#include "../../Enemy/EnemyFlyCircle2.h"


void InitEnemyManager()
{
    InitEnemyFlyCircle();
    InitEnemyFlyCircle2();
}

void LoadEnemyManager()
{
}

void StartEnemyManager()
{
}

void StepEnemyManager()
{
}

void UpdateEnemyManager()
{
    UpdateEnemyFlyCircle();
    UpdateEnemyFlyCircle2();
}

void DrawEnemyManager()
{
    DrawEnemyFlyCircle();
    DrawEnemyFlyCircle2();
}

void FinEnemyManager()
{
}