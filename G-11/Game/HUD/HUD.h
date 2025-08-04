#pragma once

#include "json.hpp"
#include "../Utils/Utils.h"
#include <fstream>
#include <sstream> 
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>

using json = nlohmann::json;

class HUD 
{
public:

#pragma region txt 파일
	void RenderText(std::string filePath, std::vector<int> cursorPos);
	void RenderText(std::string filePath, std::vector<int> cursorPos, Color color);
#pragma endregion
	void RenderJson(std::string filePath, std::vector<int> cursorPos);
};