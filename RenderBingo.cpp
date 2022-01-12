#include "RenderBingo.h"
#include<iomanip>
void RenderBingo::printBlank(int r, int c)
{
	int index = dat[r][c];
	if (index < 100) cout << setw(2) << setfill('0') << index;
	else {
		index = (index - 100) + Black;
		printConsole(index);
	}
}

RenderBingo::RenderBingo(int _w, int _h)
{
	setSize(_w, _h);
	column = 2;
}
