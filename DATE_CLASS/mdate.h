//
// Created by shrik3 on 12/9/16.
//

#ifndef OOP_MDATE_H
#define OOP_MDATE_H

class mdate {

public:
    int year = 1970;
    int month = 1;
    int day = 1;
    int weekday = 1;
    int index[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    void RefreshIndex();

    void IncreaseOneDay();

    void IncreaseOneWeek();

    void IncreaseOneYear();

    int WhichDayInThisYear();

    int WhichDayInWeek();

    int operator-(mdate b);

    int WhichDaySinceStd();

    void describe();

private:

    int isRunYear();

};

int isRun(int year);

#endif //OOP_MDATE_H
