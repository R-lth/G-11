#include "G11.h"

G11::G11() 
{
}

void G11::BeginPlay() 
{
	
}

void G11::Tick(float deltaTime)
{
}

void G11::Render() 
{
	// TODO. 테스트용
	Utils::SetPosColor({ 0, 0 }, Color::BLUE);
	std::cout << "=== G11 Mini Game ===\n";
}