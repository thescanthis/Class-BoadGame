#pragma once
#include<iostream>
#include "LogicBase.h"
#define ARRSIZE 100
using namespace std;
class Logic2D : public LogicBase
{
protected:
	int turn;//���� ������.
	int Length;//LogicBase�� ���Ӽ��� �����ؾ��ϴ� �Լ�.
	int** dat;
	int row, col;//2���� �������� ũ�Ⱚ
	pair<int, int>p[ARRSIZE];
	enum {U,UR,R,DR,D,DL,L,UL};
	int move[8][2] = {
		{-1,0}, {-1,1},
		{0,1}, {1,1},
		{1,0}, {1,-1},
		{0,-1}, {-1,-1} };
	Logic2D(int, int);//Ŭ������ü�� ȣ��Ǹ鼭 �����ڰ� ȣ��.
	~Logic2D();//���α׷��� ����Ǹ鼭 �Ҹ��� ȣ��.

	void initData();//�ɹ� ���� �� ��ü ������ �ʱ�ȭ����.
	bool analyzeDirection(int, int, int, int);
	//2������������ Ư�������͸� Ž�� �м�
	bool isEmpty(int, int);//������������ �Ǻ�
	void nextTurn();//���� �����ܰ�� ����.
	void resetLength();//Length�ǰ��� �ʱ�ȭ
	void setValue(int,int,int);//������ ������ ���� �����Ѵ�.

	virtual bool analyze(int, int) = 0;
	//�߻��Լ� ��ӽ� �ݵ�� �����ϵ��� ����ȭ��Ŵ.

public:
	int** getData();
};

