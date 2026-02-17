#include "DxLib.h"
#include "Input.h"

int g_InputState = 0;
int g_PrevInputState = 0;

void InitInput()
{
	g_InputState = 0;
	g_PrevInputState = 0;
}

void UpdateInput()
{
	g_PrevInputState = g_InputState;
	g_InputState = 0;

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

bool IsTriggerKey(InputKey key)
{
	return !(g_InputState & key) && (g_PrevInputState & key);
}