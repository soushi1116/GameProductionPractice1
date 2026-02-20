#include "DxLib.h"
#include "Input.h"

int g_InputState = 0;
int g_PrevInputState = 0;

int g_PadState = 0;
int g_PrevPadState = 0;

void InitInput()
{
	g_InputState = 0;
	g_PrevInputState = 0;

	g_PadState = 0;
	g_PrevPadState = 0;
}

void UpdateInput()
{
	g_PrevInputState = g_InputState;
	g_InputState = 0;

	g_PrevPadState = g_PadState;
	g_PadState = 0;

	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		g_InputState |= KEY_RIGHT;
	}

	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		g_InputState |= KEY_LEFT;
	}

	if (CheckHitKey(KEY_INPUT_UP))
	{
		g_InputState |= KEY_UP;
	}

	if (CheckHitKey(KEY_INPUT_A))
	{
		g_InputState |= KEY_A;
	}

	if (CheckHitKey(KEY_INPUT_X))
	{
		g_InputState |= KEY_X;
	}

	if (CheckHitKey(KEY_INPUT_Z))
	{
		g_InputState |= KEY_Z;
	}

	if (CheckHitKey(KEY_INPUT_C))
	{
		g_InputState |= KEY_C;
	}

	if (CheckHitKey(KEY_INPUT_K))
	{
		g_InputState |= KEY_K;
	}

	if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT)
	{
		g_PadState |= PAD_RIGHT;
	}

	if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT)
	{
		g_PadState |= PAD_LEFT;
	}

	if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_B)
	{
		g_PadState |= PAD_B;
	}

	if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_3)
	{
		g_PadState |= PAD_Y;
	}

	if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_4)
	{
		g_PadState |= PAD_X;
	}

	if (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_A)
	{
		g_PadState |= PAD_A;
	}
}

void DrawInput()
{

}

bool IsInputKey(InputKey key)
{
	return g_InputState & key;
}

bool IsTriggerKey(InputKey key)
{
	return g_InputState & key && !(g_PrevInputState & key);
}

bool IsReleaseKey(InputKey key)
{
	return !(g_InputState & key) && (g_PrevInputState & key);
}

bool IsInputPad(InputPad pad)
{
	return g_PadState & pad;
}

bool IsTriggerPad(InputPad pad)
{
	return g_PadState & pad && !(g_PrevPadState & pad);
}

bool IsReleasePad(InputPad pad)
{
	return !(g_PadState & pad) && (g_PrevPadState & pad);
}
