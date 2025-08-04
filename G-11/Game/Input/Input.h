#pragma once
#include "../Utils/Singleton.h"

class Input : public Singleton<Input>
{
    // Singleton만은 생성자에 접근 가능하도록 집 열쇠 줌
    friend class Singleton<Input>;

    struct KeyState
    {
        bool isPressed = false;
        bool wasPressed = false;
    };

private:
    // 정보 은닉. 외부로부터 보호
    Input() = default; 
    ~Input() = default;

public:
    bool GetKey(int keyCode);     // 계속 누름
    bool GetKeyDown(int keyCode); // 막 누름
    bool GetKeyUp(int keyCode);   // 막 뗌
    void ProcessInput();
    void StorePreviousKeyStates();

private:
    KeyState keyStates[256] = {};
};
