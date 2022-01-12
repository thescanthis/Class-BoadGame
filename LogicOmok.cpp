#include "LogicOmok.h"

LogicOmok::LogicOmok(int _r, int _c) :Logic2D(_r, _c) {}

bool LogicOmok::setData(int _r, int _c)
{
    if (!isEmpty(_r, _c)) return false;

    bool res=analyze(_r,_c);
    setValue(turn, _r, _c);
    nextTurn();
    return res;
}

bool LogicOmok::analyze(int _r, int _c)
{
    int checkvalue = turn;

    for (int dir = U; dir <= DR; dir++) {
        analyzeDirection(checkvalue, dir, _r, _c);
        analyzeDirection(checkvalue, dir + 4, _r, _c);

        if (Length >= 4) return true;//해당길이가 4이상이면 오목.
        resetLength();
    }
    return false;
}
