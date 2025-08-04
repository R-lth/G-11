#pragma once

#include "../System/GameMode.h"
#include "../Level/Level.h"
#include "../Utils/Utils.h"
#include "../Input/Input.h"
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

class MenuUI : public Singleton<MenuUI>
{
    friend class Singleton;

public:
    MenuUI();
    ~MenuUI();

    void KeyInput();
    void Render(const std::vector<int>& startPos) const;
    void Run(const std::vector<int>& startPos);

private:
    std::vector<MenuItem*> menus;
    int size = 0;
    int currentIndex = 0;
};