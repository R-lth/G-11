#include "GameMode.h"

GameMode::GameMode()
{
	tile = new TitleLevel();
	intro = new IntroLevel();
	//miniGame = new MiniGame();
	//ending = new Ending();

	arr.emplace_back(tile);
	arr.emplace_back(intro);
	//arr.emplace_back(miniGame);
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

	// TODO. ★ 4가지 레벨(제목/인트로/게임/엔딩)을 어떻게 전환시킬지
	// 메뉴는 고정돼 있고, 이미 할당된 벡터에서만 이동 시키는 식으로

	index = (index + 1 == size) ? 0 : index + 1;
	mainLevel = arr[index];
}
