#include "HUD.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    std::string filePath = "../Asset/Title.txt";
    std::vector<int> cursorPos = { 0, 0 };

    HUD hudManager;
    hudManager.RenderText(filePath, cursorPos, Color::YELLOW);

    std::cin.get();
}