#include "Dxlib.h"
#include "Scene/SceneManager.h"
#include "GameSetting/GameSetting.h"
#include "Input/Input.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR IpCmdLine, _In_ int nShowCmd)
{
	// ウィンドウモードON
	ChangeWindowMode(TRUE);

	//画像会の設定
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLOR_DEPTH);

	if (DxLib_Init() == -1)   // DXライブラリ初期初期化処理
	{
		return -1;      // エラーが起きたら直ちに終了
	}

	// ウィンドウサイズ設定
	SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	// 透過色の設定
	SetTransColor(TRANCE_COLOR_R, TRANCE_COLOR_G, TRANCE_COLOR_B);

	// 描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	// 入力システムを初期化
	InitInput();

	// ゲームのメインループ
	while (ProcessMessage() >= 0)
	{
		// ループ処理前に1ミリ秒止めると処理が安定する
		Sleep(1);

		// 画面をクリア
		ClearDrawScreen();

		// 入力を更新
		UpdateInput();

		// シーン管理の更新
		SceneManagerUpdate();

		// 入力システムの描画
		DrawInput();

		// エスケープキーで終了
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;

		// 画面フリップ
		ScreenFlip();
	}

	// 入力システムの終了
	FinInput();

	DxLib_End();    // DXライブラリ使用の終了処理

	return 0;       // ソフトの終了
}