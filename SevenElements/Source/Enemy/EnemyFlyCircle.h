#pragma once

#define ENEMY_CIRCLE_MAX 2

void InitEnemyFlyCircle();
void UpdateEnemyFlyCircle();
void DrawEnemyFlyCircle();

float GetEnemyFlyCircleX(int index);
float GetEnemyFlyCircleY(int index);

int GetEnemyFlyCircleWidth(int index);
int GetEnemyFlyCircleHeight(int index);