#pragma once

enum InputKey
{
	KEY_UP    = (1 << 0),
	KEY_DOWN  = (1 << 1),
	KEY_LEFT  = (1 << 2),
	KEY_RIGHT = (1 << 3),
	KEY_Z     = (1 << 4),
	KEY_X     = (1 << 5),
	KEY_C     = (1 << 6),
};

void InitInput();
void UpdateInput();
void DrawInput();
void FinInput();

bool IsInputKey(InputKey key);
bool IsTriggerKey(InputKey key);