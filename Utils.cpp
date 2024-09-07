#include "Utils.h"

char Utils::getCharacter()
{
    string input = "";
    char singleSign  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            singleSign = input[0];
            break;
        }

        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }

    return singleSign;
}

string Utils::readLine()
{
    string input = "";
    cin.sync();
    getline(cin, input);
    return input;
}

double Utils::getDecimalNumber()
{
    string input = "";
    double number = 0;

    while (true)
    {
        getline(cin, input);
        stringstream myStream(input);

        if (myStream >> number)
            break;
        cout << "Entered character string is not a number. Try again." << endl;
    }
    return number;
}
