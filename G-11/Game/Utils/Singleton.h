#pragma once

template <typename T>
class Singleton
{
public:
    static T& Get()
    {
        static T instance;
        return instance;
    }

    Singleton() = default;
    virtual ~Singleton() = default;

    // 복사 생성자 예방
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    // 이동 생성자(r-value) 예방
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;
};
