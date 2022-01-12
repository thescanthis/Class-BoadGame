#include<iostream>
#include<string>
#include"RenderOmok.h"
#include"LogicOmok.h"
using namespace std;

int main(void)
{
	LogicOmok lo = LogicOmok(16, 16);
	RenderOmok ro = RenderOmok(16, 16);

	ro.setData(lo.getData());
	int r, c;
	string input;
	bool bgameover = false;
	while (1)
	{
		system("cls");
		ro.printBoard();
		if (bgameover) {
			cout << "gameover";
			break;
		}
		cout << "Input Position: ";
		cin >> input;
		ro.getPosition(r, c, input);
		bgameover = lo.setData(r, c);
	}
	return 0;
}