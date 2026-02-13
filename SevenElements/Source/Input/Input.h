#pragma once

enum InputKey
{
	KEY_RIGHT = (1 << 0),
	KEY_LEFT  = (1 << 1),
	KEY_A     = (1 << 2),
	KEY_X     = (1 << 3),
};

void InitInput();
void UpdateInput();
void DrawInput();
void FinInput();

bool IsInputKey(InputKey key);
bool IsTriggerKey(InputKey key);