#include "RenderNarrow.h"

void RenderNarrow::setSize(int _wid, int _hei)
{
	wid = _wid - 2;
	hei = _hei - 2;
}
void RenderNarrow::printLine(int r, int _start)
{
	int index=_start;
	int ci = (dat[r][0] == EMPTY) ? index : (Black - 1) + dat[r][0];
	printConsole(ci);
	index++;

	for (int i = 0; i < wid; i++) {
		ci = (dat[r][i + 1] == EMPTY) ? index : (Black - 1) + dat[r][i + 1];
		printConsole(ci);
	}
	index++;
		ci = (dat[r][wid + 1] == EMPTY) ? index : (Black - 1) + dat[r][wid + 1];
	printConsole(ci);
	println();

}

void RenderNarrow::println()
{
	cout << endl;
}

void RenderNarrow::printup()
{
	cout << endl;
}

void RenderNarrow::printBoard()
{
	printup();
	printLine(0, TL);
	for (int i = 0; i < hei; i++) printLine(i + 1, ML);
	printLine(hei + 1, BL);
}
