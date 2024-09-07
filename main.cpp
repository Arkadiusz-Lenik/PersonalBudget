#include <iostream>

#include "BudgetMainApp.h"
#include "Menus.h"

using namespace std;

int main()
{
    BudgetMainApp budgetMainApp("users.xml", "incomes.xml", "expenses.xml");
    char choice;

    while (true)
    {
        if (budgetMainApp.isUserLoggedIn() == false)
        {
            Menus::showTitle("HOME MENU");
            Menus::showHomeMenu();
            choice = Utils::getCharacter();

            switch (choice)
            {
                case '1':
                    budgetMainApp.registerUser();
                    break;
                case '2':
                    budgetMainApp.loginUser();
                    break;
                case '9':
                    exit(0);
                    break;
                default:
                    cout << endl << "Character not used. Try again" << endl << endl;
                    system("pause");
                    break;
            }
        }
        else
        {
            Menus::showTitle("MAIN MENU");
            Menus::showMainMenu();
            choice = Utils::getCharacter();

            switch (choice)
            {
                case '1':
                    budgetMainApp.addIncome();
                    break;
                case '2':
                    budgetMainApp.addExpense();
                    break;
                case '3':
                    budgetMainApp.showCurrentMonthBalance();
                    break;
                case '4':
                    budgetMainApp.showPreviousMonthBalance();
                    break;
                case '5':
                    budgetMainApp.showCustomPeriodBalance();
                    break;
                case '6':
                    budgetMainApp.changeUserPassword();
                    break;
                case '7':
                    budgetMainApp.logoutUser();
                    break;
            }
        }
    }

    return 0;
}

