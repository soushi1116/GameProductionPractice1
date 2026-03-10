#include "EventManager.h"
#include "Die.h"
#include "Clear.h"

void InitEventManager()
{
	InitDie();
	InitClear();
}

void LoadEventManager()
{
	LoadDie();
	LoadClear();
}

void StartEventManager()
{
	StartDie();
	StartClear();
}

void UpdateEventManager()
{
	UpdateDie();
	UpdateClear();
}

void DrawEventManager()
{
	DrawDie();
	DrawClear();
}

void FinEventManager()
{
	FinDie();
	FinClear();
}