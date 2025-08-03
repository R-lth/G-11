#include "HUD/HUD.h"
#include "HUD/MenuUI.h"

int main()
{
    SetConsoleTitle(L"G- 11");

    // 1. 게임 시작
#pragma region 게임 시작 화면
    SetConsoleOutputCP(CP_UTF8);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    // TODO. 정가운데 정렬(슈팅 게임 참고)
#pragma region Title
    std::string filePath = "../Asset/Title.txt";
    std::vector<int> cursorPos = { 0, 0 };

    HUD hudManager;
    hudManager.RenderText(filePath, cursorPos);
#pragma endregion

#pragma region ToggleBtn
    std::vector<int> menuStartPos = { 0, 12 };

    MenuUI menu;
    menu.Run(menuStartPos);
#pragma endregion
#pragma endregion
    // TODO.
    // 2. Intro : 게임 세계관 및 Skip
    // 3. Game
    // 4. Ending

    std::cin.get();
}