#pragma once

#define ENEMY_STRAIGHT_MAX 2

void InitEnemyFlyStraight();
void UpdateEnemyFlyStraight();
void DrawEnemyFlyStraight();

float GetEnemyFlyStraightX(int index);
float GetEnemyFlyStraightY(int index);

int GetEnemyFlyStraightWidth(int index);
int GetEnemyFlyStraightHeight(int index);