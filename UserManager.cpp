#include "UserManager.h"

void UserManager::registerUser()
{
    User user = enterUserData();
    users.push_back(user);

    cout << endl << "Your account has been created." << endl;

    if (userFile.addUserToFile(user))
    {
        cout << "Your account has been added to file." << endl << endl;
    }

    system("pause");
}

User UserManager::enterUserData()
{
    User user;
    user.userId = getNewUserId();
    string login = "";
    cout << "Enter login: ";
    //login = Utils::readLine();
    login = readLine();

    vector <User>::iterator itr = users.begin();

    while (itr != users.end())
    {
        if (itr->login == login)
        {
            cout << "Entered login is already taken. Try again" << endl;
            login = readLine();
            itr = users.begin();
        }
        else
        {
            itr++;
        }
    }

    user.login = login;
    cout << "Enter password: ";
    //user.password = Utils::readLine();
    user.password = readLine();
    cout << "Enter name: ";
    //user.firstName = Utils::readLine();
    user.firstName = readLine();
    cout << "Enter lastname: ";
    //user.lastName = Utils::readLine();
    user.lastName = readLine();

    return user;
}

int UserManager::getNewUserId()
{
    if (users.empty())
        return 1;
    else
        return users.back().userId + 1;
}

string UserManager::readLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

void UserManager::showAllUsers()
{
    for (size_t i = 0; i < users.size(); i++)
    {
        cout << users[i].userId << "|" << users[i].login << "|" << users[i].password << "|" << users[i].firstName << "|" << users[i].lastName << endl;
    }

    system("pause");
}

void UserManager::loginUser()
{
    string login = "", password = "";
    bool userExists = false;

    cout << endl << "Enter login: ";
    login = Utils::readLine();

    for (size_t i = 0; i < users.size(); i++)
    {
        if (users[i].login == login)
        {
            userExists = true;

            for (int attemptsLeft = 3; attemptsLeft > 0; attemptsLeft--)
            {
                cout << "Enter password. Attempts left: " << attemptsLeft << ": ";
                password = Utils::readLine();

                if (users[i].password == password)
                {
                    cout << endl << "You are logged in." << endl << endl;
                    loggedUserId = users[i].userId;
                    system("pause");
                    return;
                }
            }

            cout << endl << "You have entered wrong password three times." << endl;
            system("pause");
            return;
        }
    }

    if (userExists == false)
    {
        cout << "Entered user do not exist" << endl << endl;
        system("pause");
        return;
    }
}

bool UserManager::isUserLoggedIn()
{
    return (loggedUserId > 0) ? true : false;
}

void UserManager::setLoggedUserId(int loggedUserId)
{
    this->loggedUserId = loggedUserId;
}



