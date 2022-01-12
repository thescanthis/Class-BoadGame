#include "LogicBase.h"

void LogicBase::setCheckValue(int _CheckValue)
{
	//연속성을 검사할 체크값을 설정한다.
	CheckValue = _CheckValue;
}

bool LogicBase::isSequential(int _data, int& _length)
{
	//_length:외부에서 구성된 변수를 call by reference형태로 가지고온다.
	//즉, 외부 변수값을 함수 내에서 수정하려는 의도임.
	if (_data == CheckValue) { _length++;  return true; }
	//체크하는 값과 일치하기 때문에 연속성의 길이값을 증가시켜준다.
	//연속중에 있따고 참을 반환한다.
	else {
		//체크하는 값의 연속성이 깨졋다
		return false;//연속성이 깨졋기때문에 거짓을 반환한다.
	}
}
