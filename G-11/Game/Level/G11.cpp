#include "G11.h"

G11::G11()
{
	//매 프레임마다 타이머 갱신
	timer = beatInterval;

	// 아무래도 게임이 시작하자마자 게임 인풋 받고 시작해야 겠지?
	Play();
}

void G11::Play()
{
	// 여기서 입력 처리와 동시에
	// 실질적인 게임 계산

	/*int main()
{
	double begin = timeGetTime();
	//cout << fixed; // 출력 소수점 자리수 고정
	//cout.precision(3); // 소수점 밑 3자리까지 출력

	while (true) {
		// 리듬 게임 종료 조건
		if (inputCnt == 9)
			break;

		double end = timeGetTime();
		// 경과 시간
		double timer = (end - begin) / 1000;

		cout << "타이머 : " << timer << endl;
		cout << endl;

		// 1) 입력 했음.
		if (_kbhit()/*사용자 입력 여부) {
			isMatched = true;

			// TODO. ★ 박자 인덱스하고 입력 횟수하고 일치 시키는 거 수정하기
			// 한 리듬 당 사용자가 정확하게 한 박자만 누르지 않음...
			// 이 부분을 어떻게 수정할지 고민해보기
			double diff = fabs((double)beats[inputCnt] - timer);

			if (diff <= (double)0.25)
			{
				score += 100;
				// 출력 (색깔 다 다르게)
				str = "Perfect";
			}
			else if (diff <= (double)0.5 && diff > (double)0.25)
			{
				score += 80;
				// 출력 (색깔 다 다르게)
				str = "Excellent";
			}
			else if (diff <= (double)0.75 && diff > (double)0.5)
			{
				score += 50;
				// 출력 (색깔 다 다르게)
				str = "Good";
			}
			else
			{
				isMatched = false;
				// 출력 (색깔 다 다르게)
				str = "Bad";
			}

			// 출력, 랭크
			rank[score];
			// 입력 횟수
			inputCnt++;
			// 콤보 계산
			combo += isMatched;

			// 임시. _kbhit()로 인해 버퍼 지워야 함
			_getch();
		}

		// 2) ★ 입력하지 않음.
		// 근데 입력하지 않았을 때의, 비트와 입력 횟수의 상관 관계도 고민해봐야 함
		/*for (int i = 0; i < size; ++i)
		{
			if (timer > beats[i] && inputCnt == i)
			{
				userPoint[inputCnt] = scoring[i];
			}
		}
		if (timer > beats[inputCnt])
		{
			isMatched = false;
			"Bad";
		}


		// 3) 이후 랭크 계산
		rank[score];

		// 4) ★ 필요하지만 너무 깜빡거림......
		system("cls");
	}

	// timer interrupt 초기화
	timeEndPeriod(1);
}*/
}

void G11::GameClear()
{
}

void G11::BeginPlay()
{
}

void G11::Tick(float deltaTime)
{
	// TODO. [레벨] beat에 맞춰서 액터를 생성
	// TODO. [액터] beat에 맞춰서 액터가 점차 내려옴...

	timer.Tick(deltaTime);

	if (timer.IsTimeout()) 
	{
		// TODO. ■ 테스트. 그럼 여기서 액터(A,S,D)를 랜덤으로 생성
		Utils::SetCursorPos({ 0, 0 });
		std::cout << "A" << std::endl;

		Utils::SetCursorPos({ 20, 0 });
		std::cout << "A" << std::endl;

		Utils::SetCursorPos({ 40, 0 });
		std::cout << "A" << std::endl;
		// 임시
		system("cls");

		timer.Reset();
	}
}

void G11::Render()
{

}