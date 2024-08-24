#include "BudgetMainApp.h"

void BudgetMainApp::registerUser()
{
    userManager.registerUser();
}

void BudgetMainApp::loginUser()
{
    userManager.loginUser();

    if (userManager.isUserLoggedIn())
    {
        budgetManager = new BudgetManager(userManager.getLoggedUserId());
    }
}

bool BudgetMainApp::isUserLoggedIn()
{
    return userManager.isUserLoggedIn();
}

void BudgetMainApp::logoutUser()
{
    userManager.setLoggedUserId(0);
    delete budgetManager;
    budgetManager = NULL;
}

void BudgetMainApp::showAllUsers()
{
    userManager.showAllUsers();
}




