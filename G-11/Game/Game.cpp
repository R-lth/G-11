#include "Engine/Engine.h"
#include <Windows.h>
#include <iostream>

int main()
{
    Engine* engine = new Engine();
    engine->Run();

    delete engine;
    engine = nullptr;

    // TODO. 게임 진행 순서
    // 1. Title (완료)
    // 2. Intro (완료)
    // 3. Game  (진행 중/레벨 전환 이슈)
    // 4. Ending

    std::cin.get();
}