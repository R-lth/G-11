#pragma once

#include "../Utils/Utils.h"
#include "../Utils/Singleton.h"
#include "../Input/Input.h"
#include "../Level/Level.h"
#include "../HUD/MenuUI.h"
#include <fstream>
#include <sstream>

// TODO. 음악 테스트
//#include <windows.h>
//#pragma comment (lib, "winmm.lib")
//#include <mmsystem.h>

struct EngineSettings
{
	int width = 0;
	int height = 0;
	float framerate = 0.0f;
};

class Level;
class Engine : public Singleton<Engine>
{
	friend class Singleton<Engine>;

public:
	Engine();
	virtual ~Engine();

	void Run();
	void Quit();

	// 화면 가로·세로 크기 반환 함수.
	int Width() const;
	int Height() const;

private:
	void BeginPlay();
	void Tick(float deltaTime = 0.0f);
	void Render();

	// 엔진 설정 로드 함수.
	void LoadEngineSettings();

protected:
	bool isQuit = false;
	Level* mainLevel = nullptr;
	EngineSettings settings;
};