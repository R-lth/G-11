#pragma once

#include "Utils.h"
#include <fstream>
#include <sstream> 

class HUD 
{
public:
	void RenderText(std::string filePath, std::vector<int> cursorPos, Color color);
};