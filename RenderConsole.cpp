#include "RenderConsole.h"

void RenderConsole::printConsole(int s)
{
	cout << line[s];
}

char RenderConsole::getChar(const int& ch)
{
	int res = (ch < 10) ? ch + 48 : ch + 87;

	return (char)res;
}

int RenderConsole::getInt(const char&ch)
{
	char res = (ch < 97) ? ch - 48 : ch - 87;
	return res;
}

void RenderConsole::setData(int** _dat)
{
	dat = _dat;
}

void RenderConsole::getPosition(int& r, int& c, string pos)
{
	//Main���� �ʱ�ȭ�� �ȵǾ� �־� ���� ������ ���;� ����������
	//�����ڸ� �Ҵ�޾Ƽ�,������ �������ʰ� ���������� ���Ѱ��� ���´�.
	r = getInt(pos[0]);
	c = getInt(pos[1]);
}
