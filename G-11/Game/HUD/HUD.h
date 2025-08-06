#pragma once

#include "json.hpp"
#include "../Utils/Utils.h"
#include "../Utils/Timer.h"
#include <fstream>
#include <sstream> 
#include <thread>
#include <chrono>
#include <time.h>

using json = nlohmann::json;

class HUD 
{
public:

#pragma region txt 파일
	void RenderText(std::string filePath, std::vector<int> cursorPos);
	void RenderText(std::string filePath, std::vector<int> cursorPos, Color color);
#pragma endregion
	void RenderJson(std::string filePath, std::vector<int> cursorPos);
	void Tick(float deltaTime, std::string filePath, std::vector<int> cursorPos);

	Timer timer;
};