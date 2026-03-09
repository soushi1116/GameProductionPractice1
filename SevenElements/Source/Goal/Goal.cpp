#include "Goal.h"
#include "DxLib.h"
#include "../Camera/Camera.h"

GoalData g_GoalData[GOAL_MAX] = { 0 };

int g_GoalHandle = 0;

void InitGoal()
{
	GoalData* goal = g_GoalData;
	for (int i = 0; i < GOAL_MAX; i++, goal++)
	{
		goal->posX = 0.0f;
		goal->posY = 0.0f;

		goal->handle = 0;

		goal->active = false;
	}
}

void LoadGoal()
{
	g_GoalHandle = LoadGraph("Data/Gimmick/Goal.png");
}

void StartGoal()
{

}

void DrawGoal()
{
	CameraData camera = GetCamera();

	GoalData* goal = g_GoalData;
	for (int i = 0; i < GOAL_MAX; i++, goal++)
	{
		if (!goal->active) continue;

		DrawGraph(goal->posX - camera.posX, goal->posY - camera.posY, g_GoalHandle, TRUE);
	}
}

void FinGoal()
{
	DeleteGraph(g_GoalHandle);
}

GoalData* CreateGoal(float posX, float posY)
{
	GoalData* goal = g_GoalData;
	for (int i = 0; i < GOAL_MAX; i++, goal++)
	{
		if (!goal->active)
		{
			goal->active = true;

			goal->handle = g_GoalHandle;

			goal->posX = posX;
			goal->posY = posY;

			break;
		}
	}

	return nullptr;
}

GoalData* GetGoal()
{
	return g_GoalData;
}