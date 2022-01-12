#pragma once
#include "RenderConsole.h"
using namespace std;
class RenderNarrow : public RenderConsole
{
protected:
	int wid, hei;

	void printLine(int, int);
	void setSize(int, int);
	virtual void println();
	virtual void printup();
public:
	void printBoard();
};

