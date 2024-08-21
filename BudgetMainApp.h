#ifndef BUDGETMAINAPP_H
#define BUDGETMAINAPP_H

#include <iostream>
#include "UserManager.h"

using namespace std;

class BudgetMainApp
{
    UserManager userManager;

public:
    BudgetMainApp(string userFileName)
    : userManager (userFileName)
    {
        ;
    }
    ~BudgetMainApp()
    {
        ;
    }

    void registerUser();
    void loginUser();
    void logoutUser();
    bool isUserLoggedIn();
    void showAllUsers();
};

#endif
