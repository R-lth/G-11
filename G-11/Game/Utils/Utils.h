#pragma once

#include "Color.h"
#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>

namespace Utils 
{
	Color DetermineColor(const char& ch);
	void SetCursorPos(const std::vector<int>& pos);
	void SetTextColor(const Color& color);
	void SetPosColor(const std::vector<int>& pos, const Color& color);
	void PrintChar(const char& ch, const std::vector<int>& pos);
	void PrintChar(const char& ch, const std::vector<int>& pos, const Color& color);
	void PrintStr(const std::string& str, const std::vector<int>& pos);
}