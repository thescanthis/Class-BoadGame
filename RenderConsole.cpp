#include "RenderConsole.h"

void RenderConsole::printConsole(int s)
{
	cout << line[s];
}

char RenderConsole::getChar(const int& ch)
{
	int res = (ch < 10) ? ch + 48 : ch + 87;

	return (char)res;
}

int RenderConsole::getInt(const char&ch)
{
	char res = (ch < 97) ? ch - 48 : ch - 87;
	return res;
}

void RenderConsole::setData(int** _dat)
{
	dat = _dat;
}

void RenderConsole::getPosition(int& r, int& c, string pos)
{
	//Main에서 초기화가 안되어 있어 원랜 오류가 나와야 정상이지만
	//참조자를 할당받아서,오류가 나오지않고 같은공간의 대한값이 나온다.
	r = getInt(pos[0]);
	c = getInt(pos[1]);
}
