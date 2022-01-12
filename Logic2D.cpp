#include "Logic2D.h"

Logic2D::Logic2D(int _row, int _col)
{
	row = _row;
	col = _col;
	dat = (int**) new int*[row];
	dat[0] = (int*) new int[row * col];
	for (int i = 1; i < row; i++) dat[i] = dat[i - 1] + col;

	this->initData();
	//�����ڷ� Ŭ������ ȣ��Ǹ鼭 �̰� ���� ȣ��Ǳ⶧����this�� ���°Ű���.
}
//�Ҹ��� �Լ�
//�����Ҵ��� ������Ű�� Ŭ������ ����Ǹ鼭 �Ҹ���ȣ��
Logic2D::~Logic2D()
{
	delete(dat[0]);
	delete(dat);
}

void Logic2D::initData()
{
	memset(dat[0], 0, sizeof(int) * row * col);
	turn = 1;
	Length = 0;
}

bool Logic2D::analyzeDirection(int cv, int dir, int sr, int sc)
{
	setCheckValue(cv);//�θ�Ŭ�������� �ʱ�ȭ�� -1��.

	for (int _r = sr, _c = sc;
		(0 <= _r && _r < row) && (0 <= _c && _c < col);
		_r += move[dir][0], _c += move[dir][1])
	{
		if (_r == sr && _c == sc) continue;
		//������ ���ٸ� �ǳ� �ڴ�.
		if (!isSequential(dat[_r][_c], Length)) return(dat[_r][_c] == EMPTY);
		else {//üũ�ؾ��� ������ ��� ���Ӽ��� �����ǰ��ִ»�Ȳ.
			int index = Length - 1;
			//������ ������ ����صд�.
			p[index].first = _r;
			p[index].second = _c;
		}
	}
	return true;
}

bool Logic2D::isEmpty(int _r, int _c)
{
	return (dat[_r][_c] == EMPTY);
}

void Logic2D::nextTurn()
{
	turn = 3 - turn;
}

void Logic2D::resetLength()
{
	//���Ἲ�� ���̰��� �ʱ�ȭ�Ѵ�.
	Length = 0;
}

void Logic2D::setValue(int v, int _r, int _c)
{
	//Ư�������� ������ ���� v�� �����Ѵ�.
	dat[_r][_c] = v;
}

int** Logic2D::getData()
{
	return dat;
}
