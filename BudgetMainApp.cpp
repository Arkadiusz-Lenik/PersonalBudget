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
        budgetManager = new BudgetManager(userManager.getLoggedUserId(), INCOME_FILE_NAME, EXPENSE_FILE_NAME);
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

void BudgetMainApp::addIncome()
{
    budgetManager->addIncome();
}

void BudgetMainApp::addExpense()
{
    budgetManager->addExpense();
}




