#include "DxLib.h"
#include "Option.h"
#include "../SceneManager.h"
#include "../../Input/Input.h"

// 画像ハンドル
int bg;
int option;
int bgm;
int se;
int gauge;

void OptionInit()
{
    // 画像を読み込む
    bg = LoadGraph("Data/Option/BG.png");
    option = LoadGraph("Data/Option/Option.png");
    bgm = LoadGraph("Data/Option/BGM.png");
    se = LoadGraph("Data/Option/SE.png");
    gauge = LoadGraph("Data/Option/Gauge.png");
}

void OptionUpdate()
{
    // Cキーを押したらタイトルに戻る
    if (IsTriggerKey(KEY_C))
    {
        ChangeScene(SCENE_TITLE);
    }
}

void OptionDraw()
{
    // 背景
    DrawGraph(0, 0, bg, TRUE);

    // Option
    DrawGraph(500, 50, option, TRUE);

    // BGM
    DrawGraph(400, 250, bgm, TRUE);
    DrawGraph(700, 250, gauge, TRUE);

    // SE
    DrawGraph(400, 350, se, TRUE);
    DrawGraph(700, 350, gauge, TRUE);
}

void OptionFin()
{
    // 画像を消す
    DeleteGraph(bg);
    DeleteGraph(option);
    DeleteGraph(bgm);
    DeleteGraph(se);
    DeleteGraph(gauge);
}
