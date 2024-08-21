#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>
#include "File.h"
#include "User.h"

using namespace std;

class UserFile : public File
{
public:
    UserFile(string userFileName) : File(userFileName) {};
    bool addUserToFile(const User &user);
    vector <User> loadUsersFromFile();
};

#endif
