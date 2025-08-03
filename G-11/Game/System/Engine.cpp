#include "Engine.h"

Engine::Engine()
{
	LoadEngineSettings();
}

Engine::~Engine()
{
}

void Engine::Run()
{
	float targetFrameRate = settings.framerate == 0.0f ? 60.0f : settings.framerate;
	float oneFrameTime = 1.0f / targetFrameRate;

	LARGE_INTEGER currentTime, previousTime, frequency;
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&currentTime);
	previousTime = currentTime;

	while (!isQuit)
	{
		QueryPerformanceCounter(&currentTime);
		float deltaTime = static_cast<float>(currentTime.QuadPart - previousTime.QuadPart) / frequency.QuadPart;

		Input::Get().ProcessInput();

		if (deltaTime >= oneFrameTime)
		{
			BeginPlay();
			Tick(deltaTime);
			Render();

			previousTime = currentTime;
			Input::Get().StorePreviousKeyStates();
		}
	}
}


void Engine::Quit()
{
	isQuit = true;
}

int Engine::Width() const
{
	return settings.width;
}

int Engine::Height() const
{
	return settings.height;
}

void Engine::BeginPlay()
{
	// 사용자 정의 초기화
}

void Engine::Tick(float deltaTime)
{
	// 매 프레임 로직
}

void Engine::Render()
{
	// 렌더링 처리
}

void Engine::LoadEngineSettings()
{
	std::ifstream file("../Setting/EngineSettings.txt");
	if (!file.is_open())
	{
		std::cerr << "Failed to open EngineSettings: " << std::endl;
		return;
	}

	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		std::string key;
		char eq;

		if (ss >> key >> eq)
		{
			if (key == "framerate" && eq == '=')
			{
				ss >> settings.framerate;
			}
			else if (key == "width" && eq == '=')
			{
				ss >> settings.width;
			}
			else if (key == "height" && eq == '=')
			{
				ss >> settings.height;
			}
		}
	}
}
