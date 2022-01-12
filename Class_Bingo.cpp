#include<iostream>
#include<string>
#include "RenderBingo.h"
#include "LogicBingo.h"
using namespace std;

int main(void)
{
	LogicBingo lb = LogicBingo(5, 10);
	RenderBingo rb = RenderBingo(5, 5);
	rb.setData(lb.getData());
	
	int r, c;
	string input;

	bool bgameover = false;
	while (1)
	{
		system("cls");
		rb.printBaord();
		if (bgameover) {
			cout << "gmaeover";
			break;
		}
		cout << "input position: ";
		cin >> input;
		bgameover = lb.setBingoValue(stoi(input));
	}
	return 0;
}