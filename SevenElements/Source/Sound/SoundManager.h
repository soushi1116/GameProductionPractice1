#pragma once

enum BGMType
{
	BGM_PLAY,

	BGM_TYPE_MAX,
};

void LoadBGM();
void PlayBGM(BGMType type);
void StopBGM(BGMType type);
void FinBGM();

enum SEType
{
	SE_WALK,
	SE_RUN,
	SE_JUMP,
	SE_RAND,

	SE_FIRE,
	SE_WATER,
	SE_THUNDER,
	SE_WIND,
	SE_GROUND,
	SE_ICE,
	SE_IRON,

	SE_TYPE_MAX,
};

void LoadSE();
void PlaySE(SEType type);
void FinSE();
