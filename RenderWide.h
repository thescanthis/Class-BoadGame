#pragma once
#include "RenderConsole.h"
class RenderWide : public RenderConsole
{
protected:
	int wid, hei;
	int column = 1;
	void printLine(int,int);
	void setSize(int, int);
	void printSpace(int,int);
	virtual void println();
	virtual void printUp();
	virtual void printBlank(int, int);
public:
	void printBaord();
};

