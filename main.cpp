#include <iostream>

#include "BudgetMainApp.h"
#include "Menus.h"

using namespace std;

int main()
{
    BudgetMainApp budgetMainApp("Users.xml");
    char choice;

    while (true)
    {
        //if (personalBudget.isUserLoggedIn() == false)
        if (true)
        {
            Menus::showHomeMenu();
            choice = Utils::getCharacter();

            switch (choice)
            {
            case '1':
                budgetMainApp.registerUser();
                break;
            case '2':
                //ksiazkaAdresowa.logowanieUzytkownika();
                ;
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
    }
}
        /*else
        {
            wybor = wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.dodajAdresata();
                break;
            case '2':
                ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
                break;
            case '3':
                ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
                ksiazkaAdresowa.usunAdresata();
                break;
            case '6':
                ksiazkaAdresowa.edytujAdresata();
                break;
            case '7':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                ksiazkaAdresowa.wylogujUzytkownika();
                break;
            }
        }
    }

    return 0;
}*/

