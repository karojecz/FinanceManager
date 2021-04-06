#include "fileWithTurnovers.h"

bool FileWithTurnovers::ifFileExist(string fileName)
{
    CMarkup xml;
    return xml.Load(fileName);
}
int FileWithTurnovers:: getTurnoverIdFromFile(string fileName, string elemName)
{
    CMarkup xml;
    int numberOfElems=0;
    xml.Load(fileName);
    xml.ResetPos(); // top of document
    xml.FindElem(); // ORDER element is root
    xml.IntoElem();
    while ( xml.FindElem(elemName))
    {
        numberOfElems++;
    }
    return numberOfElems;
}
