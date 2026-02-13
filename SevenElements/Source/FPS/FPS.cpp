#include "DxLib.h"
#include "FPS.h"

#define FPS_SAMPLE_NUM (60)

#define FPS (60)

int g_StartTime;
int g_Count;
float g_Fps;

void InitFPS()
{
	g_StartTime = 0;
	g_Count = 0;
	g_Fps = 0.0f;
}

void UpdateFPS()
{
	if (g_Count == 0)
	{
		g_StartTime = GetNowCount();
	}

	if (g_Count == FPS_SAMPLE_NUM)
	{
		int time = GetNowCount();

		g_Fps = 1000.0f / ((time - g_StartTime) / (float)FPS_SAMPLE_NUM);
		g_Count = 0;
		g_StartTime = time;
	}
	g_Count++;
}

void DrawFPS()
{
	DrawFormatString(32, 24, GetColor(0, 0, 0), "FPSy%.1fz", g_Fps);
}

void FPSWait()
{
	int takeTime = GetNowCount() - g_StartTime;

	int waitTime = g_Count * 1000 / FPS - takeTime;

	if (waitTime > 0)
	{
		Sleep(waitTime);
	}
}