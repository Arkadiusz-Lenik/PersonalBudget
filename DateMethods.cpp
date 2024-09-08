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
        cout << "Entered date is too short/long" << endl;
        return false;
    }

    for (size_t characterPosition = 0; characterPosition < dateAssociatedValue.length(); characterPosition++)
    {
        if (isdigit(dateAssociatedValue[characterPosition]))
        {
            continue;
        }
        else if ((dateAssociatedValue[characterPosition] == '-') && (characterPosition == 4 || characterPosition == 7))
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

    time_t currentTime = time(NULL);
    tm* currentTimePointer = localtime(&currentTime);

    if (enteredDate["year"] == ((currentTimePointer->tm_year) + 1900))
    {
        if (enteredDate["month"] >= 1 && enteredDate["month"] <= currentTimePointer->tm_mon + 1)
        {
            if (enteredDate["day"] >= 1 && enteredDate["day"] <= howManyDaysDoesEachMonthHave(enteredDate))
            {
                return true;
            }
            else
            {
                cout << "Entered day is incorrect" << endl;
                return false;
            }
        }
        else
        {
            cout << "Entered month is incorrect" << endl;
            return false;
        }
    }

    if (enteredDate["year"] >= 2000 && enteredDate["year"] <= ((currentTimePointer->tm_year) + 1900 - 1))
    {
        if (enteredDate["month"] >= 1 && enteredDate["month"] <= 12)
        {
            if (enteredDate["day"] >= 1 && enteredDate["day"] <= howManyDaysDoesEachMonthHave(enteredDate))
            {
                return true;
            }
            else
            {
                cout << "Entered day is incorrect" << endl;
                return false;
            }
        }
        else
        {
            cout << "Entered month is incorrect" << endl;
            return false;
        }
    }
    else
    {
        cout << "Entered year is incorrect" << endl;
        return false;
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

int DateMethods::convertStringDateToInt(const string dateAsString)
{
    string tempStringDateWithoutDashes = "";
    int dateAsInt = 0;

    for (size_t characterPosition = 0; characterPosition < dateAsString.length(); characterPosition++)
    {
        if (isdigit(dateAsString[characterPosition]))
        {
            tempStringDateWithoutDashes += dateAsString[characterPosition];
        }
        else
        {
            continue;
        }
    }

    dateAsInt = stoi(tempStringDateWithoutDashes);

    return dateAsInt;
}

int DateMethods::getCurrentMonthStartDate()
{
    time_t currentTime = time(NULL);
    tm* currentTimePointer = localtime(&currentTime);

    string currentMonthStartDateAsString = "", year = "", month = "", days = "01";
    int currentMonthStartDateAsInt = 0;

    year = to_string(currentTimePointer->tm_year + 1900);

    if ((currentTimePointer->tm_mon + 1) < 10)
    {
        month = "0" + to_string(currentTimePointer->tm_mon + 1);
    }
    else
    {
        month = to_string(currentTimePointer->tm_mon + 1);
    }

    currentMonthStartDateAsString = year + month + days;
    currentMonthStartDateAsInt = stoi(currentMonthStartDateAsString);

    return currentMonthStartDateAsInt;
}

int DateMethods::getCurrentMonthEndDate()
{
    time_t currentTime = time(NULL);
    tm* currentTimePointer = localtime(&currentTime);

    map <string, int> date;
    string currentMonthEndDateAsString = "", year = "", month = "", days = "";
    int currentMonthEndDateAsInt = 0;

    year = to_string(currentTimePointer->tm_year + 1900);

    if ((currentTimePointer->tm_mon + 1) < 10)
    {
        month = "0" + to_string(currentTimePointer->tm_mon + 1);
    }
    else
    {
        month = to_string(currentTimePointer->tm_mon + 1);
    }

    date["year"] = stoi(year);
    date["month"] = stoi(month);

    days = to_string(howManyDaysDoesEachMonthHave(date));

    currentMonthEndDateAsString = year + month + days;
    currentMonthEndDateAsInt = stoi(currentMonthEndDateAsString);

    return currentMonthEndDateAsInt;
}

int DateMethods::getPreviousMonthStartDate()
{
    time_t currentTime = time(NULL);
    tm* currentTimePointer = localtime(&currentTime);

    string previousMonthStartDateAsString = "", year = "", month = "", days = "01";
    int previousMonthStartDateAsInt = 0;

    if ((currentTimePointer->tm_mon + 1) == 1)
    {
        year = to_string(currentTimePointer->tm_year + 1900 - 1);
        month = to_string(currentTimePointer->tm_mon + 11);
    }
    else
    {
        year = to_string(currentTimePointer->tm_year + 1900);

        if ((currentTimePointer->tm_mon + 1) < 11)
        {
            month = "0" + to_string(currentTimePointer->tm_mon);
        }
        else
        {
            month = to_string(currentTimePointer->tm_mon);
        }
    }

    previousMonthStartDateAsString = year + month + days;
    previousMonthStartDateAsInt = stoi(previousMonthStartDateAsString);

    return previousMonthStartDateAsInt;
}

int DateMethods::getPreviousMonthEndDate()
{
    time_t currentTime = time(NULL);
    tm* currentTimePointer = localtime(&currentTime);

    map <string, int> date;
    string previousMonthEndDateAsString = "", year = "", month = "", days = "";
    int previousMonthEndDateAsInt = 0;

    if ((currentTimePointer->tm_mon + 1) == 1)
    {
        year = to_string(currentTimePointer->tm_year + 1900 - 1);
        month = to_string(currentTimePointer->tm_mon + 11);
    }
    else
    {
        year = to_string(currentTimePointer->tm_year + 1900);

        if ((currentTimePointer->tm_mon + 1) < 11)
        {
            month = "0" + to_string(currentTimePointer->tm_mon);
        }
        else
        {
            month = to_string(currentTimePointer->tm_mon);
        }
    }

    date["year"] = stoi(year);
    date["month"] = stoi(month);

    days = to_string(howManyDaysDoesEachMonthHave(date));

    previousMonthEndDateAsString = year + month + days;
    previousMonthEndDateAsInt = stoi(previousMonthEndDateAsString);

    return previousMonthEndDateAsInt;
}

string DateMethods::convertDateToStringWithDashes(int dateAsInt)
{
    string dateWithDashes = "", tempYear = "", tempMonth = "", tempDay = "", tempStringDate = to_string(dateAsInt);

    tempYear = tempStringDate.substr(0,4);
    tempMonth = tempStringDate.substr(4,2);
    tempDay = tempStringDate.substr(6,2);

    dateWithDashes = tempYear + "-" + tempMonth + "-" + tempDay;

    return dateWithDashes;
}





