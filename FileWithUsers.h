#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include "user.h"
#include <vector>
#include "markup.h"
#include "AuxiliaryMethods.h"


using namespace std;

class FileWithUsers
{
        User user;

public:

    //void adNewUserToFile();
    bool ifFileExist();
    vector <User> loadUsersFromFile();
    void adNewUserToFile(User user);


};
#endif
