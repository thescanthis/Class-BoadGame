#pragma once
#include "Logic2D.h"
class LogicBingo : public Logic2D
{
private:
	int Mcol;
	int lines;

	bool analyze(int, int);
	void mix(int);
	void swap(int&, int&);
	void analyzeLine(int, int, int, int);

public:
	LogicBingo(int, int);
	~LogicBingo();

	bool setBingoValue(int);
};

