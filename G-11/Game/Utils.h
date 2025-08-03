#pragma once

#include "Color.h"
#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>

namespace Utils 
{
	void SetCursorPos(const std::vector<int>& pos);
	void SetTextColor(const Color& color);
	void PrintChar(const char& ch, const std::vector<int>& pos, const Color& color);
}