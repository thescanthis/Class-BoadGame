#include "RenderWide.h"

void RenderWide::setSize(int _wid, int _hei)
{
	wid = _wid - 1;
	hei = _hei - 1;
}
void RenderWide::printLine(int _start,int _times)
{
	while (_times--) {//수평으로 확장해야 할 보드의 개수
		int index = _start;
		printConsole(index++);
		printConsole(Horz);

		for (int i = 0; i < wid; i++) {
			printConsole(index);
			printConsole(Horz);
		}
		printConsole(++index);
	}
	cout << endl;
}

void RenderWide::printSpace(int _r, int _times)
{
	int col = 0;
	while (_times--)
	{
		for (int i = 0; i < wid + 1; i++) {
			printConsole(Vert);
			printBlank(_r, i+5*col);//돌아니면 공백이거임->othello의경우
			//데이터위치를 column 값에 따라 대응되도록 구성한다.
		}
		printConsole(Vert);
		col++;
	}
	println();
}

void RenderWide::printUp()
{
	cout << endl;
}

void RenderWide::printBlank(int _r, int _c)
{
	cout << "  ";
}
void RenderWide::println()
{
	cout << endl;
}

void RenderWide::printBaord()
{
	printUp();
	printLine(TL,column); printSpace(0,column);//수평,수직.
	for (int i = 0; i < hei; i++) {
		printLine(ML,column);
		printSpace(i + 1,column);
	}
	printLine(BL,column);
}
