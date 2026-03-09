#pragma once

#define GOAL_MAX (1)
#define GOAL_WIDTH (50)
#define GOAL_HEIGHT (100)

struct GoalData
{
	float posX;
	float posY;

	int handle;

	bool active;
};

void InitGoal();
void LoadGoal();
void StartGoal();
void DrawGoal();
void FinGoal();

GoalData* CreateGoal(float posX, float posY);

GoalData* GetGoal();