#ifndef FILEWITHEXPENSE_H
#define FILEWITHEXPENSE_H

#include <iostream>
#include "markup.h"
#include "turnover.h"
#include "fileWithTurnovers.h"
#include <vector>
#include "AuxiliaryMethods.h"

class FileWithExpense:public FileWithTurnovers
{
    string fileName;

public:

    FileWithExpense()
    {
        fileName="expenses.xml";
    };
    virtual void addItemToFile(Turnover expense);
    vector <Turnover> loadExpenseFromFile(int userId);

};
#endif
