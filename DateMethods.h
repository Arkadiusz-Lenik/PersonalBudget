#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <iostream>
#include <cstdio>
#include <ctime>
#include <map>

using namespace std;

class DateMethods
{
public:
    static bool isLeapYear(int year);
    static int getTodaysDate();
    static bool validateDate(string dateAssociatedValue);
    static int howManyDaysDoesEachMonthHave(map <string, int> enteredDate);
    static map <string, int> splitEnteredDate(string dateAssociatedValue);
    static int covertStringDateToInt(const string dateAsString);
};

#endif
