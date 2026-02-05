#include "Dxlib.h"
#include "Scene/SceneManager.h"
#include "GameSetting/GameSetting.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR IpCmdLine, _In_ int nShowCmd)
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

	while (ProcessMessage() >= 0)
	{
		Sleep(1);

		ClearDrawScreen();

		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;

		ScreenFlip();
	}

	DxLib_End();

	return 0;
}