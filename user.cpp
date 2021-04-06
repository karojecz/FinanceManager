#include "user.h"

    string User:: downloadName()
    {
        return name;
    }
    string User::downloadSurename()
    {
        return surename;
    }
    string User::downloadLogin()
    {
        return login;
    }
    string User::downloadPassword()
    {
        return password;
    }
    int User::downloadId()
    {
        return id;
    }

    void User::setName(string newName)
    {
        name=newName;
    }
    void User::setSurename(string newSurename)
    {
        surename=newSurename;
    }
    void User::setlogin(string newLogin)
    {
        login=newLogin;
    }
    void User::setPassword(string newPasword)
    {
        password=newPasword;
    }
    void User::setId(int newId)
    {
        id=newId;
    }
