#include "Utils.h"

Color Utils::DetermineColor(const char& ch)
{
	switch (ch)
	{
	case '*':
		return Color::CYAN;
	case '.':
		return Color::LIGHTMAGENTA;
	case '+':
		return Color::YELLOW;
	default:
		//return Color::LIGHTBLUE;
		//return Color::CYAN;
		return Color::LIGHTMAGENTA;
	}
}

void Utils::SetCursorPos(const std::vector<int>& pos)
{
	static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = static_cast<short>(pos[0]);
	coord.Y = static_cast<short>(pos[1]);
	SetConsoleCursorPosition(handle, coord);
}

void Utils::SetTextColor(const Color& color)
{
	static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD word = static_cast<WORD>(color);
	SetConsoleTextAttribute(handle, word);
}

void Utils::SetPosColor(const std::vector<int>& pos, const Color& color) 
{
	static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = static_cast<short>(pos[0]);
	coord.Y = static_cast<short>(pos[1]);
	SetConsoleCursorPosition(handle, coord);
	WORD word = static_cast<WORD>(color);
	SetConsoleTextAttribute(handle, word);
}

void Utils::PrintChar(const char& ch, const std::vector<int>& pos)
{
	SetCursorPos(pos);
	SetTextColor(DetermineColor(ch));
	std::cout << ch;
}

void Utils::PrintChar(const char& ch, const std::vector<int>& pos, const Color& color)
{
	SetCursorPos(pos);
	SetTextColor(color);
	std::cout << ch;
}
