#include "RenderOmok.h"

RenderOmok::RenderOmok(int _w, int _h)
{
	setSize(_w, _h);
	line = 0;
}
void RenderOmok::println()
{
	cout << getChar(line++) << endl;
}

void RenderOmok::printup()
{
	line = wid + 3;
	int cnt = 0;
	while (--line) cout << " " << getChar(cnt++);
	cout << endl;
}
