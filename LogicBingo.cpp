#include "LogicBingo.h"

LogicBingo::LogicBingo(int r, int c) :Logic2D(r, c)
{
    Mcol = col / 2;

    srand(time(NULL));
    mix(0);
    mix(1);
}
LogicBingo::~LogicBingo(){}

void LogicBingo::swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
void LogicBingo::mix(int _col)
{
    int mx = row * Mcol;
    int* temp = new int[mx];
    int i = 0;
    for (; i < mx; i++) temp[i] = i + 1;

    while (mx > 0) {
        i = rand() % mx;
        if (i != mx - 1) swap(temp[i], temp[mx - 1]);
        mx--;
    }

    mx = row * Mcol;
    for (i = 0; i < mx; i++) setValue(temp[i], i/row, _col * Mcol + i % Mcol);
    delete temp;
}
bool LogicBingo::analyze(int _r, int _c)
{
    int cc = col / 2;
    lines = 0;
    int checkvalue = 100 + _c;

    for (int r = 0; r < row; r++) analyzeLine(checkvalue, R, r, _c * 5);
    for (int c = _c * 5; c < _c * 5 + col; c++) analyzeLine(checkvalue, D, 0, c);
    analyzeLine(checkvalue, UR, row - 1, _c * 5);
    analyzeLine(checkvalue, DR, 0, _c * 5);

    return lines == 5;
}

void LogicBingo::analyzeLine(int _cv, int _dir, int _r, int _c)
{
    Length = (dat[_r][_c] == _cv) ? 1 : 0;
    analyzeDirection(_cv, _dir, _r, _c);

    if (Length == 5) lines++;
}

bool LogicBingo::setBingoValue(int value)
{
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            if (dat[r][c] == value) dat[r][c] = 100 + c / (col / 2);
        }
    }

        return analyze(0, 0) || analyze(0, 1);
}
