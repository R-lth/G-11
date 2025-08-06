#include "Timer.h"

Timer::Timer(double targetTime)
    : targetTime(targetTime)
{
    
}

void Timer::Tick(float deltaTime)
{
    // 경과시간 업데이트.
    elapsedTime += static_cast<double>(deltaTime);
}

void Timer::Reset()
{
    elapsedTime = 0.0f;
}

bool Timer::IsTimeout() const
{
    return elapsedTime >= targetTime;
}

void Timer::SetTargetTime(float newTargetTime)
{
    targetTime = newTargetTime;
}