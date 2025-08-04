#include "System/Engine.h"
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
    // 2. Intro (진행 중)
    // 3. Game
    // 4. Ending

    std::cin.get();
}