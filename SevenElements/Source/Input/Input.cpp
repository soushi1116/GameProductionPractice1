#include "DxLib.h"
#include "Input.h"

Input::Input()
{
	g_InputState = 0;
	g_PrevInputState = 0;
}

Input::~Input()
{
	
}

void Input::UpdateInput()
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

	if (CheckHitKey(KEY_INPUT_A))
	{
		g_InputState |= KEY_A;
	}

	if (CheckHitKey(KEY_INPUT_X))
	{
		g_InputState |= KEY_X;
	}
}

void Input::DrawInput()
{

}

bool Input::IsInputKey(InputKey key)
{
	return g_InputState & key;
}

bool Input::IsTriggerKey(InputKey key)
{
	return g_InputState & key && !(g_PrevInputState & key);
}