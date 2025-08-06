#include "HUD.h"

void HUD::RenderText(std::string filePath, std::vector<int> cursorPos)
{
    std::ifstream file;
    file.open(filePath);

    if (!file.is_open())
    {
        std::cout << "Failed to open file: " << filePath << std::endl;
        return;
    }

    std::stringstream stream;
    stream << file.rdbuf();
    file.close();

    std::string str = stream.str();
    std::vector<int> movePos = cursorPos;

    for (char ch : str)
    {
        if (ch == '\n')
        {
            movePos[0] = cursorPos[0];
            ++movePos[1];
            continue;
        }

        Utils::PrintChar(ch, movePos);
        ++movePos[0];
    }
}

void HUD::RenderText(std::string filePath, std::vector<int> cursorPos, Color color)
{
    std::ifstream file;
    file.open(filePath);

    if (!file.is_open())
    {
        std::cout << "Failed to open file: " << filePath << std::endl;
        return;
    }

    std::stringstream stream;
    stream << file.rdbuf();
    file.close();

    std::string str = stream.str();
    std::vector<int> movePos = cursorPos; 

    for (char ch : str)
    {
        if (ch == '\n')
        {
            movePos[0] = cursorPos[0]; 
            ++movePos[1];             
            continue;
        }

        Utils::PrintChar(ch, movePos, color); 
        ++movePos[0];
    }
}

void HUD::Tick(float deltaTime, std::string filePath, std::vector<int> cursorPos)
{
    timer.SetTargetTime(2.0f);

    //
    std::ifstream file(filePath);
    if (!file.is_open()) 
    {
        std::cerr << "Failed to open json: " << std::endl;
    }

    json j;
    file >> j;

    //Utils::SetTextColor(Color::Orange);
    //Utils::SetCursorPos({ 0, 0});

    Utils::SetPosColor({0, 0}, Color::Orange);

    for (const auto& credit : j["intro_credit"]) 
    {
        timer.Tick(deltaTime);

        if (timer.IsTimeout()) 
        {
            std::string str = credit.get<std::string>(); // "따음표" 제외
            std::cout << str << std::endl;
        }

        timer.Reset();
    }
}