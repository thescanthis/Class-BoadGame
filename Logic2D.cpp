#include "Logic2D.h"

Logic2D::Logic2D(int _row, int _col)
{
	row = _row;
	col = _col;
	dat = (int**) new int*[row];
	dat[0] = (int*) new int[row * col];
	for (int i = 1; i < row; i++) dat[i] = dat[i - 1] + col;

	this->initData();
	//생성자로 클래스가 호출되면서 이게 같이 호출되기때문에this가 나온거같다.
}
//소멸자 함수
//동적할당을 해제시키고 클래스가 종료되면서 소멸자호출
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
	setCheckValue(cv);//부모클래스에선 초기화로 -1임.

	for (int _r = sr, _c = sc;
		(0 <= _r && _r < row) && (0 <= _c && _c < col);
		_r += move[dir][0], _c += move[dir][1])
	{
		if (_r == sr && _c == sc) continue;
		//지점이 같다면 건너 뛴다.
		if (!isSequential(dat[_r][_c], Length)) return(dat[_r][_c] == EMPTY);
		else {//체크해야할 값으로 계속 연속성이 유지되고있는상황.
			int index = Length - 1;
			//현재의 지점을 기록해둔다.
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
	//연결성의 길이값을 초기화한다.
	Length = 0;
}

void Logic2D::setValue(int v, int _r, int _c)
{
	//특정지점의 데이터 값을 v로 설정한다.
	dat[_r][_c] = v;
}

int** Logic2D::getData()
{
	return dat;
}
