#include "TitleLevel.h"

TitleLevel::TitleLevel()
{

}

void TitleLevel::BeginPlay() 
{

}

void TitleLevel::Tick(float deltaTime)
{

}

void TitleLevel::Render()
{
    std::string filePath = "../Asset/Title.txt";

    //TODO. 정렬 자동화
    //int x = (Engine::Get().Width() / 2) - (maxLineLength / 2);
    //int y = Engine::Get().Height() - 1;*/
    
    // Title
    HUD hudManager;
    hudManager.RenderText(filePath, {0, 0});
}

