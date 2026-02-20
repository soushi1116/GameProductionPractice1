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

enum InputPad
{
	PAD_RIGHT = (1 << 0),
	PAD_LEFT  = (1 << 1),
	PAD_B     = (1 << 2),
	PAD_Y     = (1 << 3),
	PAD_X     = (1 << 4),
	PAD_A     = (1 << 5),
};

void InitInput();
void UpdateInput();
void DrawInput();

bool IsInputKey(InputKey key);
bool IsTriggerKey(InputKey key);
bool IsReleaseKey(InputKey key);

bool IsInputPad(InputPad pad);
bool IsTriggerPad(InputPad pad);
bool IsReleasePad(InputPad pad);
