#include "Turnover.h"

string Turnover::getDate()
{
    return date;
}
void Turnover::setDate(string newDate)
{
    date=newDate;
    dateConvertedToNumber=DateManager::changeDateToNumber(date);
}
int Turnover::getUserId()
{
    return UserId;
}
void Turnover::setUserId(int newId)
{
    UserId=newId;
}
int Turnover::getTurnoverId()
{
    return TurnoverId;
}
void Turnover::setTurnoverId(int newId)
{
    TurnoverId=newId;
}
string Turnover::getDescription()
{
    return description;
}
void Turnover::setDescription(string newDescription)
{
    description=newDescription;
}
/*
int Turnover::changeDateToNumber(string date)
{
    string combineDate;
    int dateConvertedToNumber;
    stringstream ss(date);
    string item;
    while (getline(ss, item, '-'))
    {
        combineDate+=item;
    }

    dateConvertedToNumber=AuxiliaryMethods::convertStringToInt(combineDate);
    return dateConvertedToNumber;
}
*/
int Turnover::getDateConvertedToNumber() const
{
    return dateConvertedToNumber;
}
float Turnover::getAmount()
{
    return amount;
}
void Turnover::setAmount(float newAmount)
{
    amount=newAmount;
}
