#pragma once

#include "Level.h"
#include "../HUD/HUD.h"

class EndingLevel : public Level
{
public:
	EndingLevel() = default;
	~EndingLevel() = default;

	void BeginPlay();
	void Tick(float deltaTime);
	void Render();
};