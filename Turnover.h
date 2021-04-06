#ifndef TURNOVER_H
#define TURNOVER_H
#include <iostream>
#include <vector>
#include <sstream>
#include "AuxiliaryMethods.h"
#include "DateManager.h"

using namespace std;

class Turnover
{
    string date, description;
    int UserId, TurnoverId, dateConvertedToNumber;
    float amount;
public:

    bool operator < (const Turnover& str) const
    {
        return (dateConvertedToNumber > str.getDateConvertedToNumber());
    }
    float getAmount();
    void setAmount(float newAmount);

    int getUserId();
    void setUserId(int newId);

    int getTurnoverId();
    void setTurnoverId(int newId);

    string getDate();
    void setDate(string newDate);

    string getDescription();
    void setDescription(string newDescription);

    int getDateConvertedToNumber() const;

    bool comp( const Turnover & l, const Turnover & r );
    //int changeDateToNumber(string date);

};
#endif
