#ifndef BUDGETMAINAPP_H
#define BUDGETMAINAPP_H

#include <iostream>
#include "UserManager.h"
#include "BudgetManager.h"

using namespace std;

class BudgetMainApp
{
    UserManager userManager;
    BudgetManager *budgetManager;

public:
    BudgetMainApp(string userFileName)
    : userManager (userFileName)
    {
        budgetManager = NULL;
    }
    ~BudgetMainApp()
    {
        delete budgetManager;
        budgetManager = NULL;
    }

    void registerUser();
    void loginUser();
    void logoutUser();
    bool isUserLoggedIn();
    void showAllUsers();
};

#endif
