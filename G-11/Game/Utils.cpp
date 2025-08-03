#include "Utils.h"

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

void Utils::PrintChar(const char& ch, const std::vector<int>& pos, const Color& color)
{
	SetCursorPos(pos);
	SetTextColor(color);
	std::cout << ch;
}
