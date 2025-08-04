#include "IntroLevel.h"

void IntroLevel::BeginPlay() 
{
}

void IntroLevel::Tick(float deltaTime) 
{
}

void IntroLevel::Render() 
{
	std::string filePath = "../Asset/Intro.json";

	HUD hudManager;
	hudManager.RenderJson(filePath, { 0, 0 });
}