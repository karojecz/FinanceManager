#ifndef FILEWITHTURNOVERS_H
#define FILEWITHTURNOVERS_H

#include <iostream>
#include "markup.h"
#include "Turnover.h"

#include <vector>

using namespace std;

class FileWithTurnovers
{
public:

    virtual void addItemToFile(Turnover turnover)=0;
    bool ifFileExist(string fileName);
    int getTurnoverIdFromFile(string fileNanme, string elemName);
};
#endif
