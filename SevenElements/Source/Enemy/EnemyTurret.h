#pragma once

#define BULLET_MAX 50
#define TURRET_MAX 2

// Šî–{
void InitEnemyTurret();
void UpdateEnemyTurret();
void DrawEnemyTurret();

// –C‘ä
float GetEnemyTurretX(int index);
float GetEnemyTurretY(int index);
int GetEnemyTurretWidth(int index);
int GetEnemyTurretHeight(int index);

// ’e
int GetEnemyTurretBulletNum();
int GetEnemyTurretBulletUse(int index);
float GetEnemyTurretBulletX(int index);
float GetEnemyTurretBulletY(int index);
int GetEnemyTurretBulletSize(int index);