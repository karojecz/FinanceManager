#ifndef USER_H
#define USER_H

#include <iostream>
#include "User.h"
#include <vector>

using namespace std;

class User
{
    string name, surename, login, password;
    int id;

public:
    string downloadName();
    string downloadSurename();
    string downloadLogin();
    string downloadPassword();
    int downloadId();

    void setName(string newName);
    void setSurename(string  newSurename);
    void setlogin(string newLogin);
    void setPassword(string newPasword);
    void setId(int newId);


};
#endif
