#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include "markup.h"
#include "Turnover.h"

#include "fileWithTurnovers.h"
#include "AuxiliaryMethods.h"
#include <vector>

class FileWithIncomes: public FileWithTurnovers
{
    string fileName;

public:

    FileWithIncomes(){
    fileName="incomes.xml";
    };
    virtual void addItemToFile(Turnover income);
    vector<Turnover> loadIncomesFromFile(int userId);


};
#endif
