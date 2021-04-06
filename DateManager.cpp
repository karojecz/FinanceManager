#include "DateManager.h"
/*
struct DateManager::DateParameters
{
        static int day;
      static int  month;
      static int year;
};
*/
string DateManager::getDateFromSystem()
{
    int year, month, day;
    string date;

    SYSTEMTIME st;
    GetSystemTime(&st);

    year=st.wYear;
    month=st.wMonth;
    day=st.wDay;

    date=AuxiliaryMethods::convertIntToString(year)+ "-";
    date+=AuxiliaryMethods::convertIntToString(month)+ "-";
    date+=AuxiliaryMethods::convertIntToString(day);
    return date;
}
int DateManager::changeDateToNumber(string date)
{
    string combineDate;
    int dateConvertedToNumber;
    stringstream ss(date);
    string item;
    while (getline(ss, item, '-'))
    {
        if(item.size()==1)
            item="0"+item;
        combineDate+=item;
    }

    dateConvertedToNumber=AuxiliaryMethods::convertStringToInt(combineDate);
    return dateConvertedToNumber;
}
vector<string> DateManager::divideDateToDayMonthYear(string date)
{
    //DateParameters dateParameters;
    vector<string> combineDate;
    int dateConvertedToNumber;
    stringstream ss(date);
    string item;
    while (getline(ss, item, '-'))
    {
        combineDate.push_back(item);
    }
    /*
    dateParameters.year=AuxiliaryMethods::convertStringToInt(combineDate[0]);
    dateParameters.month=AuxiliaryMethods::convertStringToInt(combineDate[1]);
    dateParameters.day=AuxiliaryMethods::convertStringToInt(combineDate[2]);

    return dateParameters;
    */
    return combineDate;
}

string DateManager:: enterDate()
{
    string date;
    cout<<"Enter date in format yyyy-mm-dd"<<endl;
    cin>>date;

    while(!ifDateCorect(date))
    {
        cout<<"Date is incorrect, enter date again"<<endl;
        cin>>date;
    }
    return date;
}
bool DateManager::ifDateFormatIsCorect(string date)
{

    if(date[4]=='-' && ((date[7]=='-') || (date[6]='-')))
        return true;
    else
        return false;
}
bool DateManager::ifDateCorect(string date)
{
    int year, month, day;
    bool dayCorect, monthCorect, yearCoredct;
    vector <string> devideDate;



    if (ifDateFormatIsCorect(date))
    {
        devideDate=divideDateToDayMonthYear(date);
        year=AuxiliaryMethods::convertStringToInt(devideDate[0]);
        month=AuxiliaryMethods::convertStringToInt(devideDate[1]);
        day=AuxiliaryMethods::convertStringToInt(devideDate[2]);

        yearCoredct=checkIfYearCorect(year);
        dayCorect=checkIfDayCorect(day, getNumberOfDays(month, IfYearIsLeap(year)));
        monthCorect=checkIfMonthCorect( month);

        if(dayCorect && monthCorect && yearCoredct)
            return true;
        else
            return false;
    }
    else
    {
        cout<<"Entered date have wrong format. ";
    }
    return false;
}
bool DateManager::checkIfYearCorect(int year)
{
    int actualYear;

    SYSTEMTIME st;
    GetSystemTime(&st);
    actualYear=st.wYear;

    if(year<2000||year>actualYear)
        return false;
    else
        return true;
}
bool DateManager::IfYearIsLeap(int year)
{
    if((year%4==0 && year%100!=0) || year%400==0)
        return true;
    else
        return false;
}
int DateManager::getNumberOfDays(int month, bool isYearLeap)
{
    if( month == 2)
    {
        //bool Leap=isYearLeap();
        if(isYearLeap)
            return 29;
        else
            return 28;
    }
    else if(month == 2 || month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else
        return 31;
}
bool DateManager::checkIfDayCorect(int day, int numberOfDaysInMonth)
{
    if (day>numberOfDaysInMonth)
        return false;
    else
        return true;
}
bool DateManager::checkIfMonthCorect(int month)
{
    if (month>12)
        return false;
    else
        return true;
}
