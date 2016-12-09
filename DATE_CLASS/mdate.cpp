#include "mdate.h"
#include <iostream>

using namespace std;

void mdate::IncreaseOneDay() {
    if (day < index[month - 1]) day++;
    else if (month < 12) {
        month++;
        day = 1;
    } else {
        month = 1;
        year++;
        day = 1;
        RefreshIndex();
    }
}

void mdate::IncreaseOneWeek() {
    if (month < 12) {
        month++;
        if (day > index[month - 1]) day = index[month - 1];
    } else {
        year++;
        RefreshIndex();
        month = 1;
        if (day > index[month - 1]) day = index[month - 1];
    }
}


void mdate::IncreaseOneYear() {
    year++;
    RefreshIndex();
    if (day > index[month - 1]) day = index[month - 1];
}

int mdate::WhichDayInThisYear() {
    int n = 0;
    for (int i = 1; i < month; i++) {
        n += index[i - 1];
    }
    n += day;
    return n;
}

int mdate::operator-(mdate b) {
    int gap = 0;
    gap += WhichDayInThisYear() - b.WhichDayInThisYear();
    if (b.isRunYear()) gap += 1;
    for (int i = b.year; i < year; i++) {
        gap += 365 + isRun(i);
    }
    return gap;

}


int mdate::isRunYear() {
    if (((year % 4 == 0) && ((year % 100 != 0)) || (year % 400 == 0))) return 1;
    else return 0;
}

void mdate::RefreshIndex() {
    if (isRunYear()) index[1] = 29;
    else index[1] = 28;
}


int isRun(int year) {
    if (((year % 4 == 0) && ((year % 100 != 0)) || (year % 400 == 0))) return 1;
    else return 0;
}


int mdate::WhichDayInWeek() {
    mdate stdday;
    stdday.day = 1;
    stdday.month = 1;
    stdday.year = 1901;
    stdday.RefreshIndex();

    return ((*this - stdday) % 7) + 1;

}


int mdate::WhichDaySinceStd() {
    mdate stdday;
    stdday.day = 1;
    stdday.month = 1;
    stdday.year = 1970;
    return *this - stdday;
}

void mdate::describe() {
    cout << "This day is " << year << "/" << month << "/" << day << " , ";
    switch (WhichDayInWeek()) {
        case 1: {
            cout << "Monday";
            break;
        }
        case 2: {
            cout << "Tuesday";
            break;
        }
        case 3: {
            cout << "Wednesday";
            break;
        }
        case 4: {
            cout << "Thursday";
            break;
        }
        case 5: {
            cout << "Friday";
            break;
        }
        case 6: {
            cout << "Saturday";
            break;
        }
        case 7: {
            cout << "Sunday";
            break;
        }
        default:
            break;
    }
    cout << ", "<< WhichDayInThisYear() << " days since 1970/1/1";

}