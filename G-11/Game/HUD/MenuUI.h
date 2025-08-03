#pragma once

#include "../System/Utils.h"
#include "../System/Input.h"
#include <functional>
#include <conio.h> 

struct MenuItem
{
    std::string text;
    std::function<void()> onSelected; // 함수 객체. ex, 람다

    MenuItem(const std::string& txt, std::function<void()> callback)
        : text(txt), onSelected(callback) 
    {
    }
};

class MenuUI
{
public:
    MenuUI();
    ~MenuUI() = default;

    void Run(const std::vector<int>& startPos);
    void Render(const std::vector<int>& startPos) const;

private:
    std::vector<MenuItem> menus;
    int currentIndex = 0;
    bool isRunning = true;

    void KeyInput();
    void ClearConsole() const;
};