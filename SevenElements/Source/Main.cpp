#include "DxLib.h"
#include "Scene/SceneManager.h"
#include "GameSetting/GameSetting.h"
#include "Input/Input.h"
#include "FPS/FPS.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR IpCmdline, _In_ int nShowCmd)
{
	ChangeWindowMode(TRUE);

	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLOR_DEPTH);

	if (DxLib_Init() == -1)
	{
		return -1;
	}

	SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	SetTransColor(TRANCE_COLOR_R, TRANCE_COLOR_G, TRANCE_COLOR_B);

	SetDrawScreen(DX_SCREEN_BACK);

	Input input;

	FPS fps;

	while (ProcessMessage() >= 0)
	{
		Sleep(1);

		ClearDrawScreen();

		input.UpdateInput();

		input.DrawInput();

		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;

		fps.UpdateFPS();

		fps.DrawFPS();

		fps.FPSWait();

		ScreenFlip();
	}

	DxLib_End();

	return 0;
}