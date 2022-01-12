#include "LogicOthello.h"

LogicOthello::LogicOthello(int _r, int _c) :Logic2D(_r, _c) {//생성자->부모클래스의 변수를 받음.
    setValue(1, 3, 4);
    setValue(1, 4, 3);
    setValue(2, 3, 3);
    setValue(2, 4, 4);
}

void LogicOthello::setData(int _r, int _c)
{
    if (!isEmpty(_r, _c)) return;//비어있지않다면 종료
    if (!analyze(_r, _c)) return;//바뀌어야할곳이없다면 종료

    setValue(turn, _r, _c);
    nextTurn();
}
bool LogicOthello::analyze(int _r, int _c)
{
    int checkvalue = 3 - turn;
    resetLength();

    for (int dir = U; dir <= UL; dir++) {

        int beforeLength = Length;//현재 길이는0
        if (analyzeDirection(checkvalue, dir, _r, _c)) {//pair의 first,second가 늘어나면Length길이가 증가.
            //돌의 구분,좌표,r,c
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