#pragma once

enum InputKey
{
	KEY_RIGHT = (1 << 0),
	KEY_LEFT  = (1 << 1),
	KEY_UP    = (1 << 2),
	KEY_A     = (1 << 3),
	KEY_X     = (1 << 4),
	KEY_Z     = (1 << 5),
	KEY_C     = (1 << 6),
	KEY_K     = (1 << 7),
};

void InitInput();
void UpdateInput();
void DrawInput();

bool IsInputKey(InputKey key);
bool IsTriggerKey(InputKey key);
bool IsReleaseKey(InputKey key);
