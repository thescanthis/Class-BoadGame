#pragma once
#define ERROR -1//수학적 판단을 용이하게 하기위해 상수가아닌 전처리기를 사용한다.
#define EMPTY 0
class LogicBase
{
private:
	int CheckValue = ERROR;//주어지는 연속성을 체크하기위해 -1로 초기화함.

protected:
	//맴버변수의 접근제어는 private으로하고
	//변수에 대한 접근 및 수정은 함수 형태의 메소드로 제공하는것이 가장 바람직하다.
	void setCheckValue(int);//이함수때문에 맴버변수는 쓰기전용 변수가 되었다.
	
	//주어지는 값이 체크해야할 값과 비교하여 연속성을 판단한다.
	bool isSequential(int, int&);
};
/*
변수는 모든상황에서 제일 중요한 요소이다.
그래서, 변수는 언제나 보호받아야 함이 마땅하다.
하지만, 개발 과정에서 편리성때문에 접근제어를 열어버리는 경우가 제법 많다.
하지만, 큰 틀에서는 언제나 변수는 보호받아야하며, 되도록이면 private으로
구성하는것을 추천한다.
*/

