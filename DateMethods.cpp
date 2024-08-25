#include "DateMethods.h"

int DateMethods::getTodaysDate()
{
    time_t rawTime;
    tm* timeInfo;
    char buffer [80];

    time(&rawTime);
    timeInfo = localtime(&rawTime);

    strftime(buffer,80,"%Y%m%d",timeInfo);

    return stoi(buffer);
}


map <string, int> DateMethods::splitEnteredDate(string dateAssociatedValue)
{
    map <string, int> enteredDate;

    enteredDate["year"] = stoi(dateAssociatedValue.substr(0,4));
    enteredDate["month"] = stoi(dateAssociatedValue.substr(5,2));
    enteredDate["day"] = stoi(dateAssociatedValue.substr(8,2));

    return enteredDate;
}

bool DateMethods::validateDate(string dateAssociatedValue)
{
    if (dateAssociatedValue == "t" || dateAssociatedValue == "T")
    {
        return true;
    }

    if (dateAssociatedValue.length() != 10)
    {
        cout << "Entered date is too short" << endl;
        return false;
    }

    for (size_t signPosition = 0; signPosition < dateAssociatedValue.length(); signPosition++)
    {
        if (isdigit(dateAssociatedValue[signPosition]) || signPosition == 4 || signPosition == 7)
        {
            continue;
        }
        else
        {
            cout << "Date contains invalid characters. Try again" << endl;
            return false;
        }
    }

    map <string, int> enteredDate;
    enteredDate = splitEnteredDate(dateAssociatedValue);
    bool isDateCorrect = false;

    time_t currentTime = time(NULL);
    tm* currentTimePointer = localtime(&currentTime);

    if (enteredDate["year"] == ((currentTimePointer->tm_year) + 1900))
    {
        if (enteredDate["month"] >= 1 && enteredDate["month"] <= currentTimePointer->tm_mon + 1)
        {
            if (enteredDate["day"] >= 1 && enteredDate["day"] <= howManyDaysDoesEachMonthHave(enteredDate))
            {
                return isDateCorrect = true;
            }
            else
            {
                cout << "Entered day is incorrect" << endl;
                return isDateCorrect = false;
            }
        }
        else
        {
            cout << "Entered month is incorrect" << endl;
            return isDateCorrect = false;
        }
    }

    if (enteredDate["year"] >= 2000 && enteredDate["year"] <= ((currentTimePointer->tm_year) + 1900 - 1))
    {
        if (enteredDate["month"] >= 1 && enteredDate["month"] <= 12)
        {
            if (enteredDate["day"] >= 1 && enteredDate["day"] <= howManyDaysDoesEachMonthHave(enteredDate))
            {
                return isDateCorrect = true;
            }
            else
            {
                cout << "Entered day is incorrect" << endl;
                return isDateCorrect = false;
            }
        }
        else
        {
            cout << "Entered month is incorrect" << endl;
            return isDateCorrect = false;
        }
    }
    else
    {
        cout << "Entered year is incorrect" << endl;
        return isDateCorrect = false;
    }
}


bool DateMethods::isLeapYear(int year)
{
    bool isLeapYear = false;

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        isLeapYear = true;
    }

    return isLeapYear;
}

int DateMethods::howManyDaysDoesEachMonthHave(map <string, int> enteredDate)
{
    int days = 0;

    switch(enteredDate["month"])
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            days = 31;
            break;
        case 4: case 6: case 9: case 11:
            days = 30;
            break;
    }

    if (enteredDate["month"] == 2)
    {
        days = isLeapYear(enteredDate["year"]) ? 29 : 28;
    }

    return days;
}

int DateMethods::covertStringDateToInt(const string dateAsString)
{
    string tempStringDateWithoutDashes = "";
    int dateAsInt = 0;

    for (size_t signPosition = 0; signPosition < dateAsString.length(); signPosition++)
    {
        if (isdigit(dateAsString[signPosition]))
        {
            tempStringDateWithoutDashes += dateAsString[signPosition];
        }
        else
        {
            continue;
        }
    }

    dateAsInt = stoi(tempStringDateWithoutDashes);

    return dateAsInt;
}




