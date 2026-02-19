#pragma once
#include "DxLib.h"
#include "../Animation/Animation.h"

#define PLAYER_WIDTH (64)
#define PLAYER_HEIGHT (126)

enum PlayerAnimationType
{
	PLAYER_ANIM_RIGHT,
	PLAYER_ANIM_LEFT,
	PLAYER_ANIM_MAX,
	PLAYER_ANIM_NONE = -1
};

struct PlayerData
{
	VECTOR pos;
	VECTOR move;

	int playerHandle;
	int level;
	int selectState;
	int runTimer;

	bool active;
	bool randing;
	bool selectElements;
	bool runRight;
	bool runLeft;
	bool isTurn;

	AnimationData animation[PLAYER_ANIM_MAX];
	PlayerAnimationType playAnim;
};

void InitPlayer();
void LoadPlayer();
void StartPlayer();
void StepPlayer();
void UpdatePlayer();
void DrawPlayer();
void FinPlayer();

PlayerData GetPlayer();

void PlayerHitMap();

void StartPlayerAnimation(PlayerAnimationType anim);
void UpdatePlayerAnimation();