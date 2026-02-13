#pragma once

enum InputKey
{
	KEY_RIGHT = (1 << 0),
	KEY_LEFT  = (1 << 1),
	KEY_A     = (1 << 2),
	KEY_X     = (1 << 3),
};

class Input
{
public:
	Input();
	~Input();

public:
	void UpdateInput();
	void DrawInput();

	bool IsInputKey(InputKey key);
	bool IsTriggerKey(InputKey key);

private:
	int g_InputState = 0;
	int g_PrevInputState = 0;
};
