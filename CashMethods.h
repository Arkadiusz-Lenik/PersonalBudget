#ifndef CASHMETHODS_H
#define CASHMETHODS_H

#include <iostream>

using namespace std;

class CashMethods
{
public:
    static bool validateAmount(string temporaryAmount);
    static string changeCommaToDot(string temporaryAmount);
};

#endif
