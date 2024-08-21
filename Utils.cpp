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
    getline(cin, input);
    return input;
}
