#include "Utils.h"

char Utils::getCharacter()
{
    string input = "";
    char singleCharacter  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            singleCharacter = input[0];
            break;
        }

        cout << "It is not a single character. Try again." << endl;
    }

    return singleCharacter;
}

string Utils::readLine()
{
    string input = "";
    cin.sync();
    getline(cin, input);
    return input;
}

