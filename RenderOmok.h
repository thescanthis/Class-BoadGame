#pragma once
#include"RenderNarrow.h"
class RenderOmok : public RenderNarrow
{
private:
	int line;

	void println();// virtual함수의 override정의
	void printup();// 이거도 마찬가지.

public:
	RenderOmok(int, int);//생성자.
};

