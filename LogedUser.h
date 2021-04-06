#ifndef LOGEDUSER_H
#define LOGEDUSER_H

#include <iostream>
#include <vector>
#include "FileWithExpense.h"
#include "FileWithIncomes.h"
#include "FileWithTurnovers.h"
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <windows.h>
#include <winbase.h>
#include "AuxiliaryMethods.h"
#include <algorithm>
#include "DateManager.h"


using namespace std;

class LogedUser
{
    FileWithExpense fileWithExpense;
    FileWithIncomes fileWithIncomes;
    vector <Turnover> incomes;
    vector <Turnover> expenses;

    int const USERID;
    int lastIncomeId;
    int lastExpenseId;

    Turnover enterTurnoverData(int USERID, int lastTurnoverId);
    void showItem(Turnover turnover);
    string chooseDate();
    char chooseOptionFromTurnoverMenu();
    float showTurnoversFromActualMonth(vector <Turnover> incomes);
    float showTurnoversFromPreviousMonth(vector <Turnover> incomes);
    void showTurnoversFromSelectionPeroid();
    void showBalance(float sumOfINcomes, float sumOfExpeneses);


public:

    LogedUser(int userId):USERID(userId)
    {

        if (fileWithIncomes.ifFileExist("incomes.xml"))
        {
            incomes=fileWithIncomes.loadIncomesFromFile(userId);
            lastIncomeId=fileWithIncomes.getTurnoverIdFromFile("incomes.xml","INCOME");
        }
        else
        {
            lastIncomeId=0;
        }
        if (fileWithExpense.ifFileExist("expenses.xml"))
        {
            expenses=fileWithExpense.loadExpenseFromFile(userId);
            lastExpenseId=fileWithExpense.getTurnoverIdFromFile("expenses.xml","EXPENSE");

        }
        else
        {
            lastExpenseId=0;
        }

    };
    void addNewIncome();
    void addNewExpense();
    void showTurnovers();
    //bool ifUserLogin();
};
#endif
