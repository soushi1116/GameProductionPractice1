#pragma once

class FPS
{
public:
	FPS();
	~FPS();

public:
	void UpdateFPS();
	void DrawFPS();

	void FPSWait();

private:
	int g_StartTime;
	int g_Count;
	float g_Fps;
};