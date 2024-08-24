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
            //if (true)
        {
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
            case '3':
                budgetMainApp.showAllUsers();
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
            Menus::showMainMenu();
            choice = Utils::getCharacter();

            switch (choice)
            {
            case '1':
                ;
                break;
            case '2':
                ;
                break;
            case '3':
                ;
                break;
            case '4':
                ;
                break;
            case '5':
                ;
                break;
            case '6':
                ;
                break;
            case '7':
                budgetMainApp.logoutUser();
                break;
            }
        }
    }

    return 0;
}

