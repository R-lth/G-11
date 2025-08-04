#pragma once

#include "Level.h"
#include "../HUD/HUD.h"

class IntroLevel : public Level 
{
public:
	IntroLevel() = default;
	~IntroLevel() = default;

	void BeginPlay();
	void Tick(float deltaTime);
	void Render();
};