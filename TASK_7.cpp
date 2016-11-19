/*
 * Write functions to add one day, one month, and one year to a Date as defined in §5.9[13].
 * Write a function that gives the day of the week for a given Date.
 * Write a function that gives the Date of the first Monday following a given Date.
 */

#include <iostream>

using namespace std;

struct date {
    int year;
    int month;
    int day;
    int index[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    void init() {
        if (((year % 4 == 0) && ((year % 100 != 0)) || (year % 400 == 0))) index[1] = 29;
    }
};

void IncreaseOneDay(date *d) {
    if (d->day < d->index[d->month - 1]) d->day++;
    else if (d->month < 12) {
        d->month++;
        d->day = 1;
    } else {
        d->month = 1;
        d->year++;
        d->day = 1;
        d->init();
    }
}

int isRunYear(int year) {
    if (((year % 4 == 0) && ((year % 100 != 0)) || (year % 400 == 0))) return 1;
    else return 0;
}

int WhichDay(date d) {               // 计算此日期是当年的第几天
    int n = 0;
    for (int i = 1; i < d.month; i++) {
        n += d.index[i - 1];
    }
    n += d.day;
    return n;
}


int DateMinus(date a, date b) {      // assuming a > b
    int gap = 0;
    gap += WhichDay(a) - WhichDay(b) + 365;
    if (isRunYear(b.year)) gap += 1;
    for (int i = b.year; i < a.year; i++) {
        gap += 365 + isRunYear(i);
    }
    return gap;
}

int WhichWeekDay(date d) {
    date stddate;
    stddate.year = 1901;
    stddate.month = 1;
    stddate.day = 1;
    stddate.init();
    return (DateMinus(d, stddate) % 7) + 1;
}


void IncreaseOneMonth(date *d) {
    if (d->month < 12) {
        d->month++;
        if (d->day > d->index[d->month - 1]) d->day = d->index[d->month - 1];
    } else {
        d->year++;
        d->init();
        d->month = 1;
        if (d->day > d->index[d->month - 1]) d->day = d->index[d->month - 1];
    }
}

void IncreaseOneYear(date *d) {
    d->year++;
    d->init();
    if (d->day > d->index[d->month - 1]) d->day = d->index[d->month - 1];

}


int main() {
    date a;
    a.year = 2015;
    a.month = 11;
    a.day = 17;
    a.init();
    IncreaseOneDay(&a);
    cout << a.year << '/' << a.month << '/' << a.day << endl;
    IncreaseOneMonth(&a);
    cout << a.year << '/' << a.month << '/' << a.day << endl;
    IncreaseOneYear(&a);
    cout << a.year << '/' << a.month << '/' << a.day << endl;

    cout << WhichWeekDay(a);
    return 0;
}


