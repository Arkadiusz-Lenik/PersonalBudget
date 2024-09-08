#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <iostream>
#include <cstdio>
#include <ctime>
#include <map>

using namespace std;

class DateMethods
{
    static bool isLeapYear(int year);
    static map <string, int> splitEnteredDate(string dateAssociatedValue);
    static int howManyDaysDoesEachMonthHave(map <string, int> enteredDate);
public:
    static int getTodaysDate();
    static bool validateDate(string dateAssociatedValue);
    static int convertStringDateToInt(const string dateAsString);
    static int getCurrentMonthStartDate();
    static int getCurrentMonthEndDate();
    static int getPreviousMonthStartDate();
    static int getPreviousMonthEndDate();
    static string convertDateToStringWithDashes(int dateAsInt);
};

#endif
