#include "System/Engine.h"
#include "HUD/HUD.h"
#include "HUD/MenuUI.h"

int main()
{
    SetConsoleTitle(L"G- 11");

    // 1. 게임 시작
    SetConsoleOutputCP(CP_UTF8);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    // Title
    std::string filePath = "../Asset/Title.txt";

    //TODO. 정렬 자동화
    /*int maxLineLength = 0;
    int x = (Engine::Get().Width() / 2) - (maxLineLength / 2);
    int y = Engine::Get().Height() - 1;*/
    std::vector<int> cursorPos = { 0, 0 };

    HUD hudManager;
    hudManager.RenderText(filePath, cursorPos);

    // MenuUI
    std::vector<int> menuStartPos = { 20, 0 + 12 };

    MenuUI menu;
    menu.Run(menuStartPos);

    // TODO.
    // 2. Intro : 게임 세계관 및 Skip
    // 3. Game
    // 4. Ending

    std::cin.get();
}