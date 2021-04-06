#include "FileWithExpense.h"


void FileWithExpense::addItemToFile(Turnover expense)
{
    CMarkup xml;
    xml.Load("expenses.xml");

    if (!ifFileExist(fileName))
    {
        xml.AddElem("Expense");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "EXPENSE" );
    xml.IntoElem();
    xml.AddElem( "ExpenseId",expense.getTurnoverId() );
    xml.AddElem( "UserId",expense.getUserId() );
    xml.AddElem( "date", expense.getDate() );
    xml.AddElem( "expense",expense.getAmount() );
    xml.AddElem( "description", expense.getDescription() );

    xml.Save("expenses.xml");
}
vector<Turnover> FileWithExpense::loadExpenseFromFile(int userId)
{
    CMarkup xml;
    vector <Turnover> expenses;
    Turnover expense;
    string item;
    int downloadedId;
    //bool ifFileExist = xml.Load("Users.xml");

    xml.Load("expenses.xml");
    xml.ResetPos(); // top of document
    xml.FindElem(); // ORDER element is root
    xml.IntoElem();

    while ( xml.FindElem("EXPENSE"))
    {
        xml.FindChildElem("UserId");
        item=xml.GetChildData();
        xml.ResetChildPos();
        downloadedId=AuxiliaryMethods::convertStringToInt(item);

        if(downloadedId==userId)
        {
            xml.FindChildElem("ExpenseId");
            item=xml.GetChildData();
            expense.setTurnoverId(AuxiliaryMethods::convertStringToInt(item));
            xml.ResetChildPos();

            xml.FindChildElem("UserId");
            item=xml.GetChildData();
            expense.setUserId(AuxiliaryMethods::convertStringToInt(item));
            xml.ResetChildPos();

            xml.FindChildElem("date");
            item=xml.GetChildData();
            expense.setDate(item);
            xml.ResetChildPos();

            xml.FindChildElem("expense");
            item=xml.GetChildData();
            expense.setAmount(AuxiliaryMethods::convertStringToFloat(item));
            xml.ResetChildPos();

            xml.FindChildElem("description");
            item=xml.GetChildData();
            expense.setDescription(item);
            xml.ResetChildPos();

            expenses.push_back(expense);
        }
    }
    return expenses;
}
