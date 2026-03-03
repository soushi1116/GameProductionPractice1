#include "DxLib.h"
#include "SoundManager.h"

int g_BGMHandle[BGM_TYPE_MAX] = { 0 };
int g_SEHandle[SE_TYPE_MAX] = { 0 };

void LoadBGM()
{
	g_BGMHandle[BGM_PLAY] = LoadSoundMem("Data/Sound/BGM/Play.mp3");

	for (int i = 0; i < BGM_TYPE_MAX; i++)
	{
		ChangeVolumeSoundMem(120, g_BGMHandle[i]);
	}
}

void PlayBGM(BGMType type)
{
	PlaySoundMem(g_BGMHandle[type], DX_PLAYTYPE_LOOP);
}

void StopBGM(BGMType type)
{
	StopSoundMem(g_BGMHandle[type]);
}

void FinBGM()
{
	for (int i = 0; i < BGM_TYPE_MAX; i++)
	{
		DeleteSoundMem(g_BGMHandle[i]);
	}
}

void LoadSE()
{
	g_SEHandle[SE_WALK] = LoadSoundMem("Data/Sound/SE/PlayerWalk.mp3");
	g_SEHandle[SE_RUN] = LoadSoundMem("Data/Sound/SE/PlayerRun.mp3");
	g_SEHandle[SE_JUMP] = LoadSoundMem("Data/Sound/SE/PlayerJump.mp3");
	g_SEHandle[SE_RAND] = LoadSoundMem("Data/Sound/SE/PlayerRand.mp3");

	g_SEHandle[SE_FIRE] = LoadSoundMem("Data/Sound/SE/Fire.mp3");
	g_SEHandle[SE_WATER] = LoadSoundMem("Data/Sound/SE/Water.mp3");
	g_SEHandle[SE_THUNDER] = LoadSoundMem("Data/Sound/SE/Thunder.mp3");
	g_SEHandle[SE_WIND] = LoadSoundMem("Data/Sound/SE/Wind.mp3");
	g_SEHandle[SE_GROUND] = LoadSoundMem("Data/Sound/SE/Ground.mp3");
	g_SEHandle[SE_ICE] = LoadSoundMem("Data/Sound/SE/Ice.mp3");
	g_SEHandle[SE_IRON] = LoadSoundMem("Data/Sound/SE/Iron.mp3");

	for (int i = 0; i < SE_TYPE_MAX; i++)
	{
		ChangeVolumeSoundMem(100, g_SEHandle[i]);
	}
}

void PlaySE(SEType type)
{
	PlaySoundMem(g_SEHandle[type], DX_PLAYTYPE_BACK);
}

void FinSE()
{
	for (int i = 0; i < SE_TYPE_MAX; i++)
	{
		DeleteSoundMem(g_SEHandle[i]);
	}
}