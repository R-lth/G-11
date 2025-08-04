#include "GameMode.h"

GameMode::GameMode()
{
	tile = new TitleLevel();
	intro = new IntroLevel();
	miniGame = new G11();
	//ending = new Ending();

	arr.emplace_back(tile);
	arr.emplace_back(intro);
	arr.emplace_back(miniGame);
	//arr.emplace_back(ending);

	size = static_cast<int>(arr.size());
}

GameMode::~GameMode()
{
	if (mainLevel) 
	{
		delete mainLevel;
		mainLevel = nullptr;
	}
}

void GameMode::SetLevel(Level* newLevel)
{
	if (mainLevel) 
	{
		delete mainLevel;
		mainLevel = nullptr;
	}

	mainLevel = newLevel;
}

Level* GameMode::GetLevel()
{
	return mainLevel;
}

void GameMode::NextLevel()
{
	system("cls");

	index = (index + 1 == size) ? 0 : index + 1;
	SetLevel(arr[index]);
}
