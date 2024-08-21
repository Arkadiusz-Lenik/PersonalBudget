#include "Menus.h"

void Menus::showTitle(string menuTitle)
{
    cout << menuTitle << endl;
}

void Menus::showHomeMenu()
{
    system("cls");
    cout << "1. Create account" << endl;
    cout << "2. Log in" << endl;
    cout << "3. Show all users" << endl;
    cout << "9. Exit" << endl << endl;
}

void Menus::showMainMenu()
{
    system("cls");
    cout << "1. Add new income" << endl;
    cout << "2. Add new expense" << endl;
    cout << "3. Show balance of current month" << endl;
    cout << "4. Show balance of previous month" << endl;
    cout << "5. Show balance of selected period" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl << endl;
}
