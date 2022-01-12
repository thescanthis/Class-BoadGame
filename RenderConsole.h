#pragma once
#include<iostream>
#define ERROR -1
#define EMPTY 0
using namespace std;

class RenderConsole
{
private:
	//��½�ų ���ڿ��� �迭�����ͷ� �����Ѵ�.
	string line[13] = {
		"��","��",
		"��","��","��",
		"��","��","��",
		"��","��","��",
		"��","��"
	};

protected:
	int** dat;
	enum {
		Horz,Vert,
		TL,TC,TR,
		ML,MC,MR,
		BL,BC,BR,
		Black,White
	};
	
	void printConsole(int);
	char getChar(const int&);
	int getInt(const char&);

public:
	void setData(int**);
	void getPosition(int&, int&, string);
};

