#include "AuxiliaryMethods.h"

int AuxiliaryMethods::convertStringToInt(string word)
{
    int item;
    stringstream geek(word);
        geek>>item;
    return item;
}
float AuxiliaryMethods::convertStringToFloat(string str)
{
    float num_float;
    num_float = std::stof(str);
    return num_float;
}
string AuxiliaryMethods::convertIntToString(int number)
{
    std::ostringstream ss;
    ss << number ;
    std::string str = ss.str();
    return str;
}

bool AuxiliaryMethods::isFirstNumberGreaterThanSecond(int number_1, int number_2)
{
    if(number_1>number_2)
        return true;
    else
        return false;
}

