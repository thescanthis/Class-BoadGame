#pragma once
#include "Logic2D.h"
class LogicOthello : public Logic2D
{
private:
	bool analyze(int, int);

public:
	LogicOthello(int, int);
	void setData(int, int);
};

