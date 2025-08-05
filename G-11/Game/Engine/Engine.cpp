#include "Engine.h"

Engine::Engine()
{
#pragma region 콘솔 창
	// 콘솔 창 이름
	SetConsoleTitle(L"G- 11");
	// 콘솔 커서 끄기.
	CONSOLE_CURSOR_INFO info; //Windows API 구조체로, 콘솔 커서의 정보
	info.bVisible = false;
	info.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	//
	SetConsoleOutputCP(CP_UTF8);
#pragma endregion
	// 엔진 설정
	LoadEngineSettings();

	// TODO. ★ 음악 테스트
	//PlaySound(TEXT("../Asset/Imtr.mp3"), NULL, SND_FILENAME | SND_ASYNC);
}

Engine::~Engine()
{
	if (mainLevel) 
	{
		delete mainLevel;
		mainLevel = nullptr;
	}
}

void Engine::Run()
{
	// 프레임
	float targetFrameRate = settings.framerate == 0.0f ? 60.0f : settings.framerate;
	float oneFrameTime = 1.0f / targetFrameRate;

	// 델타 타임
	LARGE_INTEGER currentTime, previousTime, frequency;
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&currentTime);
	previousTime = currentTime;

	while (true)
	{
		if (isQuit) 
		{
			break;
		}

		QueryPerformanceCounter(&currentTime);
		float deltaTime = static_cast<float>(currentTime.QuadPart - previousTime.QuadPart) / frequency.QuadPart;

		// 입력 처리는 빠르게
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
	exit(1);
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
	MenuUI::Get().Run({ 20, 15 });
	mainLevel = GameMode::Get().GetLevel();

	if (mainLevel) 
	{
		mainLevel->BeginPlay();
	}
}

void Engine::Tick(float deltaTime)
{
	if (mainLevel) 
	{
		mainLevel->Tick(deltaTime);
	}
}

void Engine::Render()
{
	if (mainLevel)
	{
		mainLevel->Render();
	}
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
