#pragma once

#include "../Utils/Singleton.h"
#include "../Engine/Engine.h"
#include "../Level/TitleLevel.h"
#include "../Level/IntroLevel.h"
#include "../Level/G11.h"
#include "../Level/EndingLevel.h"
#include <vector>

class Level;
class GameMode : public Singleton<GameMode>
{
	friend class Singleton<GameMode>;

public:
	GameMode();
	~GameMode();

	void SetLevel(Level* newLevel);
	Level* GetLevel();
	void NextLevel();

private:
	int index = 0;
	Level* tile = nullptr;
	Level* intro = nullptr;
	Level* miniGame = nullptr;
	Level* ending = nullptr;

	Level* mainLevel = nullptr;
	std::vector<Level*> arr;
	int size = 0;
};