#include "FinanseManager.h"


void FinanseManager:: userRegistration()
{
    userManager.Registration();
}
bool FinanseManager::isUserLogedIn(int userId)
{
    if(userId!=0)
        return true;
    else
        return false;
}
bool FinanseManager::userLogin()
{
    int userId;
    userId=userManager.UserLogin();

   if(isUserLogedIn(userId))
   {
    logedUser=new LogedUser(userId);
    return true;
   }
   else
    return false;
}
void FinanseManager::userLogout()
{
    delete logedUser;
    logedUser=NULL;
    cout<<"You are logout"<<endl;
}
void FinanseManager::addNewIncome()
{
    logedUser->addNewIncome();
}
void FinanseManager::adNewExpense()
{
    logedUser->addNewExpense();
}
void FinanseManager::showBalance()
{
    logedUser->showTurnovers();
}
char FinanseManager::chooseOptionFromMainMenu()
{
    char choose;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. REGISTRATION" << endl;
    cout << "2. LOGIN" << endl;
    cout << "9. QUIT PROGRAM" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choose: ";
    cin>>choose;

    return choose;
}
char FinanseManager::chooseOptionFromUserMenu()
{
    char choose;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. ADD INCOME" << endl;
    cout << "2. ADD EXPENSE" << endl;
    cout << "3. SHOW TURNOVERS" << endl;
    cout << "4. LOGOUT" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choose: ";
    cin>>choose;

    return choose;
}
