#include "LogicBase.h"

void LogicBase::setCheckValue(int _CheckValue)
{
	//���Ӽ��� �˻��� üũ���� �����Ѵ�.
	CheckValue = _CheckValue;
}

bool LogicBase::isSequential(int _data, int& _length)
{
	//_length:�ܺο��� ������ ������ call by reference���·� ������´�.
	//��, �ܺ� �������� �Լ� ������ �����Ϸ��� �ǵ���.
	if (_data == CheckValue) { _length++;  return true; }
	//üũ�ϴ� ���� ��ġ�ϱ� ������ ���Ӽ��� ���̰��� ���������ش�.
	//�����߿� �ֵ��� ���� ��ȯ�Ѵ�.
	else {
		//üũ�ϴ� ���� ���Ӽ��� ������
		return false;//���Ӽ��� �����⶧���� ������ ��ȯ�Ѵ�.
	}
}
