#include "Menus.h"

void Menus::showTitle(string menuTitle)
{
    system("cls");
    cout << endl << "\t \t >>> " << menuTitle << " <<<" << endl;
}

void Menus::showSubtitle(string menuTitle)
{
    cout << endl << "\t \t >>> " << menuTitle << " <<<" << endl;
}

void Menus::showHomeMenu()
{
    cout << "1. Create account" << endl;
    cout << "2. Log in" << endl;
    cout << "9. Exit" << endl << endl;
}

void Menus::showMainMenu()
{
    cout << "1. Add new income" << endl;
    cout << "2. Add new expense" << endl;
    cout << "3. Show balance of current month" << endl;
    cout << "4. Show balance of previous month" << endl;
    cout << "5. Show balance of selected period" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl << endl;
}
