#pragma once

#include "Level.h"

class IntroLevel : public Level 
{
public:
	IntroLevel() = default;
	~IntroLevel() = default;

	void Render();
};