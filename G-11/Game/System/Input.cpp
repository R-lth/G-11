#include "Input.h"
#include <Windows.h>

void Input::ProcessInput()
{
	for (int ix = 0; ix < 255; ++ix)
	{
		keyStates[ix].isPressed
			= GetAsyncKeyState(ix) & 0x8000;
	}
}

void Input::StorePreviousKeyStates()
{
	for (int ix = 0; ix < 255; ++ix)
	{
		keyStates[ix].wasPressed
			= keyStates[ix].isPressed;
	}
}

bool Input::GetKey(int keyCode)
{
	return keyStates[keyCode].isPressed;
}

bool Input::GetKeyDown(int keyCode)
{
	return !keyStates[keyCode].wasPressed
		&& keyStates[keyCode].isPressed;
}

bool Input::GetKeyUp(int keyCode)
{
	return keyStates[keyCode].wasPressed
		&& !keyStates[keyCode].isPressed;
}