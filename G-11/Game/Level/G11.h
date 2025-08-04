#pragma once

#include "Level.h"
#include "../HUD/HUD.h"

class G11 : public Level
{
public:
	G11() = default;
	~G11() = default;

	void BeginPlay();
	void Tick(float deltaTime);
	void Render();
};