// 这是一个日期的类实现

#include "mdate.h"
#include <iostream>

using namespace std;
int main(){
    mdate A;
    mdate B;
    A.day = 1;
    A.month = 10;
    A.year = 2016;

    B.year = 1973;
    B.month = 12;
    B.day = 31;
    cout << B.WhichDaySinceStd();
    return 0;
}