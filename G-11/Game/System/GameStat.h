#pragma once

#include "../Utils/Singleton.h"
#include <string>
#include <unordered_map>

class GameStat : public Singleton<GameStat>
{
public:
	GameStat() = default;
	~GameStat() = default;

private:
	// 총 점
	int score = 0;

	// TODO. input 여부도 받아야 함
	// 중요한 건 박자에서 많이 벗어나서
	// 실수로 눌렀을 때를 어떻게 판별하며
	// 어떤 계산할지

	// 콤보
	bool isSuccessful = false;
	int combo = 0;

	// TODO. 정확히 어디서 관리할지
	// 평가 유아이
	std::string str = "";

	// 랭크
	std::unordered_map<int, std::string> rank = {
		{    1, "C"  },
		{ 5400, "B"  },
		{13500, "A"  },
		{15600, "S"  },
		{16200, "SSS"}
	};
};