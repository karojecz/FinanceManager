#include "LogedUser.h"

string LogedUser::chooseDate()
{
    char mark='0';
    string date;

    while (mark!='y' && mark!='n')
    {
        cout<<"Save turnover with today's date (press 'y') or other (press 'n')  ?"<<endl;
        cin>>mark;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (mark=='y')
        {
            date=DateManager::getDateFromSystem();
        }
        else if(mark=='n')
        {
            date=DateManager::enterDate();
        }
        else
            cout<<"You pressed incorrect button, try again"<<endl;
    }
    return date;
}
Turnover LogedUser::enterTurnoverData(int USERID, int lastTurnoverId)
{
    Turnover turnover;
    float amount;
    string date, description;

    turnover.setTurnoverId(lastTurnoverId+1);
    turnover.setUserId(USERID);

    cout<<"ENTER TURNOVER DATA"<<endl;

    cout<<"Enter amount"<<endl;
    amount=AuxiliaryMethods::enterAmount();
    turnover.setAmount(amount);

    cout<<"Enter description"<<endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin,description);
    //cin>>description;
    turnover.setDescription(description);

    date=chooseDate();

    turnover.setDate(date);
    return turnover;
}
void LogedUser::addNewIncome()
{
    Turnover income;
    income=enterTurnoverData(USERID, lastIncomeId);
    lastIncomeId=lastIncomeId+1;

    incomes.push_back(income);
    fileWithIncomes.addItemToFile(income);
    cout<<"Income was added"<<endl;
    Sleep(1500);

}
void LogedUser::addNewExpense()
{
    Turnover expense;
    expense=enterTurnoverData(USERID, lastExpenseId);
    lastExpenseId=lastExpenseId+1;

    expenses.push_back(expense);
    fileWithExpense.addItemToFile(expense);
    cout<<"Expense was added"<<endl;
    Sleep(1500);
}
void LogedUser::showItem(Turnover turnover)
{
    cout<<"ID: "<<turnover.getTurnoverId()<<endl;
    cout<<turnover.getDate()<<endl;
    cout<<turnover.getAmount()<<" zl"<<endl;
    cout<<turnover.getDescription()<<endl;
    cout<<"--------------------"<<endl;

}
char LogedUser::chooseOptionFromTurnoverMenu()
{
    char mark='0';
    system ("cls");

    cout<<"SHOW BALANSE"<<endl;
    cout<<"From this month__________chose 1"<<endl;
    cout<<"From previous month______chose 2"<<endl;
    cout<<"From selection period_____chose 3"<<endl;

    cin>>mark;

    return mark;
}
void LogedUser::showBalance(float sumOfINcomes, float sumOfExpeneses)
{
    cout<<"Sum of incomes is: "<<sumOfINcomes<<" Sum of expense is: "<<sumOfExpeneses<<endl;
    cout<<" Balance: "<<sumOfINcomes-sumOfExpeneses<<endl;
}
void LogedUser::showTurnovers()
{
    char choose;
    float sumOfIncomes=0;
    float sumOfExpenses=0;

    choose=chooseOptionFromTurnoverMenu();

    switch (choose)
    {
    case '1' :
        cout<<"INCOMES:"<<endl;
        sumOfIncomes=showTurnoversFromActualMonth(incomes);
        cout<<"EXPENSES:"<<endl;
        sumOfExpenses=showTurnoversFromActualMonth(expenses);
        showBalance(sumOfIncomes,sumOfExpenses);
        system("pause");
        break;
    case '2' :
        cout<<"INCOMES:"<<endl;
        sumOfIncomes=showTurnoversFromPreviousMonth(incomes);
        cout<<"EXPENSES:"<<endl;
        sumOfExpenses=showTurnoversFromPreviousMonth(expenses);
        showBalance(sumOfIncomes,sumOfExpenses);
        system("pause");
        break;
    case '3' :
        showTurnoversFromSelectionPeroid();
        system("pause");
        break;
    default :
        cout<<"Wrong choose. You need press 1, 2 or 3 . "<<endl;
        Sleep(2000);
        break;
    }
}
void LogedUser::showTurnoversFromSelectionPeroid()
{
    int firstNumber, lastNumber;
    float sumOfIncomes=0;
    float sumOfExpenses=0;
    string firstDate, lastDate;
    Turnover item;

    sort (incomes.begin(), incomes.end());
    sort (expenses.begin(), expenses.end());

    cout<<"FIRST DATE"<<endl;
    firstDate=DateManager::enterDate();

    cout<<"LAST DATE"<<endl;
    lastDate=DateManager::enterDate();

    firstNumber=DateManager::changeDateToNumber(firstDate);
    lastNumber=DateManager::changeDateToNumber(lastDate);

    cout<<"INCOMES:"<<endl<<endl;
    for(int i=0; i<incomes.size(); i++)
    {
        if (incomes[i].getDateConvertedToNumber()>=firstNumber && incomes[i].getDateConvertedToNumber()<=lastNumber)
        {
            item=incomes[i];
            sumOfIncomes+=incomes[i].getAmount();
            showItem(incomes[i]);
        }
    }
        cout<<"EXPENSES:"<<endl;
        for(int i=0; i<expenses.size(); i++)
    {
        if (expenses[i].getDateConvertedToNumber()>=firstNumber && expenses[i].getDateConvertedToNumber()<=lastNumber)
        {
            item=expenses[i];
            sumOfExpenses+=expenses[i].getAmount();
            showItem(item);
        }
    }
    showBalance(sumOfIncomes, sumOfExpenses);
}
float LogedUser::showTurnoversFromPreviousMonth(vector <Turnover> incomes)
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    Turnover item;
    int downloadedMonth;
    int  month=st.wMonth;
    float sumOfTurnovers=0;

    sort (incomes.begin(), incomes.end());

    for(int i=0; i <incomes.size(); i++)
    {
        string date=incomes[i].getDate();
        string MonthTwoNubers;
        vector <string> devideDate;
        devideDate=DateManager::divideDateToDayMonthYear(date);
        MonthTwoNubers=devideDate[1];
        downloadedMonth=AuxiliaryMethods::convertStringToInt(MonthTwoNubers);

        if(month==downloadedMonth-1)
        {
            item=incomes[i];
            sumOfTurnovers+=incomes[i].getAmount();
            showItem(item);
        }
    }
    return sumOfTurnovers;
}
float LogedUser::showTurnoversFromActualMonth(vector <Turnover> incomes)
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    Turnover item;
    int downloadedMonth;
    int  month=st.wMonth;
    float sumOfTurnovers=0;

    sort (incomes.begin(), incomes.end());

    for(int i=0; i <incomes.size(); i++)
    {
        string date=incomes[i].getDate();
        string MonthTwoNubers;
        vector <string> devideDate;
        devideDate=DateManager::divideDateToDayMonthYear(date);
        MonthTwoNubers=devideDate[1];
        downloadedMonth=AuxiliaryMethods::convertStringToInt(MonthTwoNubers);

        if(month==downloadedMonth)
        {
            item=incomes[i];
            sumOfTurnovers+=incomes[i].getAmount();
            showItem(item);
        }
    }
    return sumOfTurnovers;
}

