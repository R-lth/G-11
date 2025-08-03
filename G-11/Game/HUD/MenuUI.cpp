#include "MenuUI.h"

MenuUI::MenuUI()
{
    menus.emplace_back("Start Game", 
        [this]() { isRunning = false;});

    menus.emplace_back("Quit Game", 
        []() { exit(0);});
}

void MenuUI::Run(const std::vector<int>& startPos)
{
    // TODO. Engine(.h 및 .cpp 만들기)
    while (isRunning)
    {
        Input::Get().ProcessInput();         
        KeyInput();                          
        Render(startPos);                  
        Input::Get().StorePreviousKeyStates();

        // 임시로 프레임 조절
        Sleep(50);
    }
}

void MenuUI::Render(const std::vector<int>& startPos) const
{
    Utils::SetPosColor(startPos, Color::DARKGRAY);
    std::cout << "=== Game Menu ===\n\n";

    std::vector<int> pos = startPos;
    pos[1] += 2;

    for (size_t i = 0; i < menus.size(); ++i)
    {
        Utils::SetCursorPos({ pos[0], pos[1] + static_cast<int>(i) });

        Color color = (i == currentIndex) ? Color::YELLOW : Color::DARKGRAY;
        Utils::SetTextColor(color);

        std::cout << menus[i].text;
    }

    Utils::SetTextColor(Color::WHITE);
}

void MenuUI::KeyInput()
{
    // 모듈러로 0에서 items.size() 직전까지 범위 지정
    if (Input::Get().GetKeyDown(VK_UP)) 
    {
        /*0에서 위로 올라가면 마지막으로 순환시켜야 하는데,
           -1 하면 음수가 되니 + size로 보정해서 항상 양수로 만든다.*/
        currentIndex = ((currentIndex - 1) + menus.size()/*음수 방지*/) % menus.size();
    }
    else if (Input::Get().GetKeyDown(VK_DOWN)) 
    {
        currentIndex = (currentIndex + 1) % menus.size();
    }
    // currentIndex로 menu 지정
    else if (Input::Get().GetKeyDown(VK_RETURN)) // Enter
    { 
        if (!menus.empty()) 
        {
            menus[currentIndex].onSelected(); // 함수 호출
        }
    }
    else if (Input::Get().GetKeyDown(VK_ESCAPE)) 
    {
        exit(0);
    }
}

void MenuUI::ClearConsole() const
{
    system("cls");
}