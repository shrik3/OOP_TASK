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
    if (d->day < d->index[d->month-1]) d->day++;
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

void IncreaseOneMonth(date *d){
    if (d->month <12){
        d->month++;
        if(d->day>d->index[d->month-1]) d->day = d->index[d->month-1];
    }else{
        d->year ++;
        d->init();
        d->month = 1;
        if(d->day>d->index[d->month-1]) d->day = d->index[d->month-1];
    }
}

void IncreaseOneYear(date *d){
    d->year++;
    d->init();
    if(d->day>d->index[d->month-1]) d->day = d->index[d->month-1];

}

int main() {
    date a;
    a.year = 1999;
    a.month = 1;
    a.day = 30;
    a.init();
    IncreaseOneDay(&a);
    cout << a.year << '/' << a.month << '/' << a.day << endl;
    IncreaseOneMonth(&a);
    cout << a.year << '/' << a.month << '/' << a.day << endl;
    IncreaseOneYear(&a);
    cout << a.year << '/' << a.month << '/' << a.day << endl;
    return 0;
}


