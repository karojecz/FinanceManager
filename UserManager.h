#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include "User.h"
#include "FileWithUsers.h"
#include <vector>
#include <windows.h>


using namespace std;

class UserManager
{
    vector<User> users;
    FileWithUsers fileWithUser;
    int setIdOfNewUser();

    User getNewUserData();
    bool isLoginExist(string login);

public:

    UserManager()
    {
        if (fileWithUser.ifFileExist())
        {
            users=fileWithUser.loadUsersFromFile();
        }
    };
    void Registration();
    int UserLogin();

};
#endif
