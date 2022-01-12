#pragma once
#include<iostream>
#include "LogicBase.h"
#define ARRSIZE 100
using namespace std;
class Logic2D : public LogicBase
{
protected:
	int turn;//턴을 전개함.
	int Length;//LogicBase의 연속성을 구별해야하는 함수.
	int** dat;
	int row, col;//2차원 데이터의 크기값
	pair<int, int>p[ARRSIZE];
	enum {U,UR,R,DR,D,DL,L,UL};
	int move[8][2] = {
		{-1,0}, {-1,1},
		{0,1}, {1,1},
		{1,0}, {1,-1},
		{0,-1}, {-1,-1} };
	Logic2D(int, int);//클래스객체가 호출되면서 생성자가 호출.
	~Logic2D();//프로그램이 종료되면서 소멸자 호출.

	void initData();//맴버 변수 및 객체 생성시 초기화진행.
	bool analyzeDirection(int, int, int, int);
	//2차원구조에서 특정데이터를 탐색 분석
	bool isEmpty(int, int);//데이터유무를 판별
	void nextTurn();//턴을 다음단계로 전개.
	void resetLength();//Length의값을 초기화
	void setValue(int,int,int);//임의의 지점의 값을 지정한다.

	virtual bool analyze(int, int) = 0;
	//추상함수 상속시 반드시 정의하도록 강제화시킴.

public:
	int** getData();
};

