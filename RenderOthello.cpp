#include "RenderOthello.h"

RenderOthello::RenderOthello(int r, int c)
{
	setSize(r, c);
	line = 0;
}
void RenderOthello::println()
{
	cout << (line++) << endl;//line끝의 UI를 출력함.
}

void RenderOthello::printUp()
{
	line = 0;
	for (int i = 0; i <= wid; i++) cout << "   " << i;
	cout << endl;
}

void RenderOthello::printBlank(int r, int c)
{
	int index = dat[r][c];
	if (index == EMPTY) cout << "  ";
	else printConsole(Black - 1 + index);
}
