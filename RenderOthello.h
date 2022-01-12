#pragma once
#include "RenderWide.h"
class RenderOthello : public RenderWide
{
private:
	int line;

	void println();
	void printUp();
	void printBlank(int, int);

public:
	RenderOthello(int, int);
};

