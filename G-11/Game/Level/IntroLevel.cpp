#include "IntroLevel.h"

void IntroLevel::BeginPlay() 
{
}

void IntroLevel::Tick(float deltaTime) 
{
	std::string filePath = "../Asset/Intro.json";

	HUD hudManager;
	hudManager.Tick(deltaTime, filePath, { 0, 0 });
}

void IntroLevel::Render() 
{
}