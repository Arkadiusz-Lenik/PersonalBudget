#include "UserFile.h"

bool UserFile::addUserToFile(const User &user)
{
    bool fileExists = xmlDoc.Load("users.xml");

    if (!fileExists)
    {
        xmlDoc.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlDoc.AddElem("Users");
    }

    xmlDoc.FindElem();
    xmlDoc.IntoElem();
    xmlDoc.AddElem("User");
    xmlDoc.IntoElem();
    xmlDoc.AddElem("UserId", user.userId);
    xmlDoc.AddElem("Login", user.login);
    xmlDoc.AddElem("Password", user.password);
    xmlDoc.AddElem("FirstName", user.firstName);
    xmlDoc.AddElem("LastName", user.lastName);

    return xmlDoc.Save("users.xml");
}

vector <User> UserFile::loadUsersFromFile()
{
    vector <User> users;
    User user;

    xmlDoc.Load("users.xml");
    xmlDoc.FindElem();
    xmlDoc.IntoElem();

    while ( xmlDoc.FindElem("User") )
    {
        xmlDoc.IntoElem();
        xmlDoc.FindElem( "UserId" );
        user.userId = stoi(xmlDoc.GetData());
        xmlDoc.FindElem( "Login" );
        user.login = xmlDoc.GetData();
        xmlDoc.FindElem( "Password" );
        user.password = xmlDoc.GetData();
        xmlDoc.FindElem( "FirstName" );
        user.firstName = xmlDoc.GetData();
        xmlDoc.FindElem( "LastName" );
        user.lastName = xmlDoc.GetData();

        users.push_back(user);
        xmlDoc.OutOfElem();
    }

    return users;
}

bool UserFile::changeUserPasswordInFile(int loggedUserId, string password)
{
    int userIdInFile = 0;
    bool flag = false;

    xmlDoc.Load("users.xml");
    xmlDoc.FindElem();
    xmlDoc.IntoElem();

    while (xmlDoc.FindElem("User"))
    {
        xmlDoc.IntoElem();
        xmlDoc.FindElem("UserId");
        userIdInFile = stoi(xmlDoc.GetData());

        if (userIdInFile == loggedUserId)
        {
            xmlDoc.FindElem("Password");
            xmlDoc.SetData(password);
            flag = true;
            break;
        }

        xmlDoc.OutOfElem();
    }

    xmlDoc.Save("users.xml");

    return flag;
}

