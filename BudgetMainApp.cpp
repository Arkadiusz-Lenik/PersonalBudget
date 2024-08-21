#include "BudgetMainApp.h"

void BudgetMainApp::registerUser()
{
    userManager.registerUser();
}

void BudgetMainApp::loginUser()
{
    userManager.loginUser();
}

bool BudgetMainApp::isUserLoggedIn()
{
    return userManager.isUserLoggedIn();
}

void BudgetMainApp::logoutUser()
{
    userManager.setLoggedUserId(0);
}

void BudgetMainApp::showAllUsers()
{
    userManager.showAllUsers();
}




