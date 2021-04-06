#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <windows.h>
#include <winbase.h>
#include "AuxiliaryMethods.h"
#include <algorithm>

class DateManager
{

    static  bool checkIfYearCorect( int year);
    static  bool checkIfMonthCorect(int month);
    static bool IfYearIsLeap(int year);
    static int getNumberOfDays(int month, bool isYearLeap);
    static bool checkIfDayCorect(int day, int numberOfDaysInMonth);
    static bool ifDateFormatIsCorect(string date);
    //bool ifDateCorect(string date);
    int enterYear();

public:

    static vector <string> divideDateToDayMonthYear(string date);
    static string getDateFromSystem();
    static int changeDateToNumber(string date);
    static string enterDate();
    static bool ifDateCorect(string date);


};
#endif
