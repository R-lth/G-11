#pragma once

#include "../System/Singleton.h"
#include "../System/Engine.h"
#include "../Level/TitleLevel.h"
#include "../Level/IntroLevel.h"
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
	Level* mainLevel = nullptr;

	Level* tile = nullptr;
	Level* intro = nullptr;
	Level* miniGame = nullptr;
	Level* ending = nullptr;
	std::vector<Level*> arr;
	int size = 0;
};