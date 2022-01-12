#pragma once
#include "Logic2D.h"
class LogicOmok : public Logic2D
{
private:
	bool analyze(int, int);

public:
	LogicOmok(int, int);
	bool setData(int,int);
};

