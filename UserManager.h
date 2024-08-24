#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include "UserFile.h"
#include "Utils.h"
#include "Menus.h"

using namespace std;

class UserManager
{
    int loggedUserId;
    vector <User> users;

    UserFile userFile;
    User enterUserData();
    int getNewUserId();
    string readLine();

public:
    UserManager(string userFileName) : userFile(userFileName)
    {
        users = userFile.loadUsersFromFile();
        loggedUserId = 0;
    }
    void registerUser();
    void loginUser();
    bool isUserLoggedIn();
    void setLoggedUserId(int loggedUserId);
    void showAllUsers();
    int getLoggedUserId();
};

#endif
