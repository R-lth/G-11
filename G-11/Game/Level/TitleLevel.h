#pragma once

#include "Level.h"
#include "../HUD/HUD.h"

class TitleLevel : public Level 
{
public:
	TitleLevel();
	~TitleLevel() = default;

	void BeginPlay();
	void Tick(float deltaTime);
	void Render();
};