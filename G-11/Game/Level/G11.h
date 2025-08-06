#pragma once

#include "Level.h"
#include "../Utils/Utils.h"
#include <stdlib.h>
#include <time.h>

class G11 : public Level
{
public:
	G11();
	~G11() = default;

	void PlayGame();
	// 게임 종료 여부
	void GameClear();

	void BeginPlay();
	void Tick(float deltaTime);
	void Render();

public:
	float timer = 0;

	// TODO. ★ 지금 beatInterval을 잘 못 생각해서
	// 너무 빠르게 출력됨.
	double bpm = 155.0;
	double beatInterval = 60.0 / bpm;

	bool isValid;
};