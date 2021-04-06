#include "fileWithIncomes.h"


void FileWithIncomes::addItemToFile(Turnover income)
{
  CMarkup xml;
    //xml.Load("incomes.xml");
    bool fileExist= xml.Load("incomes.xml");
    cout<<"to file"<<endl;
    if (!fileExist)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incoms");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "INCOME" );
    xml.IntoElem();
    xml.AddElem( "IncomeId",income.getTurnoverId() );
    xml.AddElem( "UserId",income.getUserId() );
    xml.AddElem( "date", income.getDate() );
    xml.AddElem( "income",income.getAmount() );
    xml.AddElem( "description", income.getDescription() );
    xml.Save("incomes.xml");
}
vector<Turnover> FileWithIncomes::loadIncomesFromFile(int userId)
{
CMarkup xml;
    vector <Turnover> incomes;
    Turnover income;
    string item;
    int downloadedId;
    //bool ifFileExist = xml.Load("Users.xml");

    xml.Load("incomes.xml");
    xml.ResetPos(); // top of document
    xml.FindElem(); // ORDER element is root
    xml.IntoElem();

    while ( xml.FindElem("INCOME"))
    {
        xml.FindChildElem("UserId");
        item=xml.GetChildData();
        xml.ResetChildPos();
        downloadedId=AuxiliaryMethods::convertStringToInt(item);

        if(downloadedId==userId)
        {

        xml.FindChildElem("IncomeId");
        item=xml.GetChildData();
        income.setTurnoverId(AuxiliaryMethods::convertStringToInt(item));
        xml.ResetChildPos();

        xml.FindChildElem("UserId");
        item=xml.GetChildData();
        income.setUserId(AuxiliaryMethods::convertStringToInt(item));
        xml.ResetChildPos();

        xml.FindChildElem("date");
        item=xml.GetChildData();
        income.setDate(item);
        xml.ResetChildPos();

        xml.FindChildElem("income");
        item=xml.GetChildData();
        income.setAmount(AuxiliaryMethods::convertStringToFloat(item));
        xml.ResetChildPos();

        xml.FindChildElem("description");
        item=xml.GetChildData();
        income.setDescription(item);
        xml.ResetChildPos();

        incomes.push_back(income);
    }
    }
    return incomes;
}
