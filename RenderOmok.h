#pragma once
#include"RenderNarrow.h"
class RenderOmok : public RenderNarrow
{
private:
	int line;

	void println();// virtual�Լ��� override����
	void printup();// �̰ŵ� ��������.

public:
	RenderOmok(int, int);//������.
};

