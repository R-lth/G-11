#include "GameMode.h"

GameMode::GameMode()
{
	// 뭔가 여기가 문제야...
	tile = new TitleLevel();
	intro = new IntroLevel();
	miniGame = new G11();
	ending = new EndingLevel();

	arr.emplace_back(tile);
	arr.emplace_back(intro);
	arr.emplace_back(miniGame);
	arr.emplace_back(ending);

	size = static_cast<int>(arr.size());

	// TODO. 첫 화면 테스트 
	if (mainLevel == nullptr) 
	{
		mainLevel = arr[0];
	}
}

GameMode::~GameMode()
{
	// TODO. ★ 레벨 전환 문제 살펴보기
	// 왜 nullptr인지
	/*for (Level*& level : arr)
	{
		if (level) 
		{
			delete level;
			level = nullptr;
		}
	}
	arr.clear();*/
}

void GameMode::SetLevel(Level* newLevel)
{
	//printf("AddLevel : new %p main %p", newLevel, mainLevel);

	if (mainLevel)
	{
		delete mainLevel;
		mainLevel = nullptr;
	}

	mainLevel = newLevel;

	//printf("AddLevel : new %p main %p", newLevel, mainLevel);
}

Level* GameMode::GetLevel()
{
	return mainLevel;
}

void GameMode::NextLevel()
{
	system("cls");

	// TODO. ★ 레벨 전환 이슈
	index = (index + 1 == size) ? size : index + 1;

	if (index == size) 
	{
		Engine::Get().Quit();
	}

	SetLevel(arr[index]);
}
