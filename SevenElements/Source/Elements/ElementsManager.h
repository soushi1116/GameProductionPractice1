#pragma	once
#include "Elements.h"
#include "DxLib.h"

#define ELEMENTS_MAX 32

void InitElementsManager();
void LoadElementsManager();
void StartElementsManager();
void StepElementsManager();
void UpdateElementsManager();
void DrawElementsManager();
void FinElementsManager();

void Action(int posX, int posY, ElementType type, bool isTurn);

VECTOR GetElementPos(int index, ElementType type);

bool IsElementActive(int index, ElementType type);

void IronHitIron(int indexA, int indexB);

void IronHitBlock(int indexA, int indexB);

void WaterHitBlock(int indexA, int indexB);

void FireHitIron(int index);

void WaterHitIce(int index);