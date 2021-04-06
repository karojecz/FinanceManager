#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>
#include "UserManager.h"
#include "LogedUser.h"

using namespace std;

class FinanseManager
{
    UserManager userManager;
    LogedUser *logedUser;

    bool isUserLogedIn(int userId);

public:
    void userRegistration();
    bool userLogin();
    void userLogout();
    void addNewIncome();
    void adNewExpense();
    void showBalance();
    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();

};
#endif
