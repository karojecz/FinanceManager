#include <iostream>
#include "FileWithUsers.h"
#include "FinanseManager.h"
#include "user.h"
#include "markup.h"
#include "Turnover.h"



using namespace std;

int main()
{
    FinanseManager finanseManager;



    char choose;
    bool ifUserLogin=false;

    while (true)
    {
        if (ifUserLogin == false)
        {
            choose = finanseManager.chooseOptionFromMainMenu();

            switch (choose)
            {
            case '1':
                finanseManager.userRegistration();
                break;
            case '2':
                ifUserLogin=finanseManager.userLogin();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "You pressed wrong button." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choose = finanseManager.chooseOptionFromUserMenu();

            switch (choose)
            {
            case '1':
                finanseManager.addNewIncome();
                break;
            case '2':
                finanseManager.adNewExpense();
                break;
            case '3':
                finanseManager.showBalance();
                break;
            case '4':
                finanseManager.userLogout();
                ifUserLogin=false;
                break;

            }
        }
    }

    return 0;
}
