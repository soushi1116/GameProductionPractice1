#include "EnemyScene.h"
#include "../../Enemy/EnemyFlyCircle.h"
#include "../../Enemy/EnemyFlyCircle2.h"
#include "../../Enemy/EnemyFlyStraight.h"
#include "../../Enemy/EnemyTurret.h"
#include "../../Enemy/EnemyWalk.h"


void InitEnemyManager()
{
    InitEnemyFlyCircle();
    InitEnemyFlyCircle2();
    InitEnemyFlyStraight();
    InitEnemyTurret();
    InitEnemyWalk();
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
    UpdateEnemyFlyStraight();
    UpdateEnemyTurret();
    UpdateEnemyWalk();
}

void DrawEnemyManager()
{
    DrawEnemyFlyCircle();
    DrawEnemyFlyCircle2();
    DrawEnemyFlyStraight();
    DrawEnemyTurret();
    DrawEnemyWalk();
}

void FinEnemyManager()
{
}