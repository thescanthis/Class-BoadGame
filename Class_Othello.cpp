#include<iostream>
#include "LogicOthello.h"
#include "RenderOthello.h"
using namespace std;

int main(void)
{
	LogicOthello lo = LogicOthello(8, 8);
	RenderOthello ro = RenderOthello(8, 8);
	ro.setData(lo.getData());

	int r, c;
	string input;

	while (1)
	{
		system("cls");
		ro.printBaord();
		cout << "input Position: ";
		cin >> input;
		ro.getPosition(r, c, input);
		lo.setData(r, c);
	}
	return 0;
}