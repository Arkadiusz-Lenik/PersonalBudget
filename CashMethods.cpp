#include "CashMethods.h"

bool CashMethods::validateAmount(string temporaryAmount)
{
    int numberOfDecimalSeparators = 0, positionOfDecimalSeparator = 0, indexOfLastCharacterInString = 0;

    for (size_t i = 0; i < temporaryAmount.length(); i++)
    {
        if (isdigit(temporaryAmount[i]) != 0)
        {
            continue;
        }
        else if (temporaryAmount[i] == '.' || temporaryAmount[i] == ',')
        {
            numberOfDecimalSeparators++;
            positionOfDecimalSeparator = i;

            if (numberOfDecimalSeparators > 1)
            {
                cout << "Entered value has more than one decimal separator. Try again" << endl << endl;
                return false;
            }
            else
            {
                continue;
            }
        }
        else
        {
            cout << "Entered number contains invalid characters. Try again" << endl << endl;
            return false;
        }
    }

    indexOfLastCharacterInString = temporaryAmount.length() - 1;

    if (indexOfLastCharacterInString - positionOfDecimalSeparator > 2)
    {
        cout << "Entered value has more than two decimal places. Try again" << endl << endl;
        return false;
    }

    return true;
}

string CashMethods::changeCommaToDot(string temporaryAmount)
{
    for (size_t i = 0; i < temporaryAmount.length(); i++)
    {
        if (temporaryAmount[i] == ',')
        {
            temporaryAmount.replace(i,1,".");
        }
    }

    return temporaryAmount;
}
