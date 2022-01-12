#include "LogicOthello.h"

LogicOthello::LogicOthello(int _r, int _c) :Logic2D(_r, _c) {//������->�θ�Ŭ������ ������ ����.
    setValue(1, 3, 4);
    setValue(1, 4, 3);
    setValue(2, 3, 3);
    setValue(2, 4, 4);
}

void LogicOthello::setData(int _r, int _c)
{
    if (!isEmpty(_r, _c)) return;//��������ʴٸ� ����
    if (!analyze(_r, _c)) return;//�ٲ����Ұ��̾��ٸ� ����

    setValue(turn, _r, _c);
    nextTurn();
}
bool LogicOthello::analyze(int _r, int _c)
{
    int checkvalue = 3 - turn;
    resetLength();

    for (int dir = U; dir <= UL; dir++) {

        int beforeLength = Length;//���� ���̴�0
        if (analyzeDirection(checkvalue, dir, _r, _c)) {//pair�� first,second�� �þ��Length���̰� ����.
            //���� ����,��ǥ,r,c
            Length = beforeLength;
        }
    }
    if (Length > 0) {
        for (int i = 0; i < Length; i++) {
            setValue(turn, p[i].first, p[i].second);
        }
        return true;
    }
    return false;
}