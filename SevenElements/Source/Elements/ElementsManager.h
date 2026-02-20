#pragma	once
#include "Elements.h"

#define ELEMENTS_MAX 32

void InitElementsManager();
void LoadElementsManager();
void StartElementsManager();
void StepElementsManager();
void UpdateElementsManager();
void DrawElementsManager();
void FinElementsManager();

void Action(int posX, int posY, ElementType type, bool isTurn);