#include "GameMode.h"

GameMode::GameMode()
{
	tile = new TitleLevel();
	intro = new IntroLevel();
	miniGame = new G11();
	ending = new EndingLevel();

	arr.emplace_back(tile);
	arr.emplace_back(intro);
	arr.emplace_back(miniGame);
	arr.emplace_back(ending);

	size = static_cast<int>(arr.size());
	mainLevel = arr[0];
}

GameMode::~GameMode()
{
	for (Level*& level : arr)
	{
		if (level) 
		{
			delete level;
			level = nullptr;
		}
	}
	arr.clear();
}

void GameMode::SetLevel(Level* newLevel)
{
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
