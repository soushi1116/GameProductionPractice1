#pragma	once
#include "Gimmick.h"
#include "DxLib.h"

#define GIMMICK_MAX 32

void InitGimmickManager();
void LoadGimmickManager();
void StartGimmickManager();
void StepGimmickManager();
void UpdateGimmickManager();
void DrawGimmickManager();
void FinGimmickManager();

void SpawnGimmick(int posX, int posY, GimmickType type);

void TreeHitFire(int index);

void AirBalloonHitFire(int index);

void AirBalloonHitBlock(int index);

void WoodBlockHitBlock(int indexA, int indexB);

void WoodBlockHitWind(int indexA, int indexB);

VECTOR GetGimmickPos(int index, GimmickType type);

bool IsGimmickActive(int index, GimmickType type);

bool AirBalloonBurning(int index);

