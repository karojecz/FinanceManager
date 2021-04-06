#include "FileWithUsers.h"


void FileWithUsers::adNewUserToFile(User user)
{
    CMarkup xml;
    xml.Load("users.xml");

    if (!ifFileExist())
    {
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "USER" );
    xml.IntoElem();
    xml.AddElem( "id",user.downloadId() );
    xml.AddElem( "name", user.downloadName() );
    xml.AddElem( "surename",user.downloadSurename() );
    xml.AddElem( "login", user.downloadLogin() );
    xml.AddElem( "password",user.downloadPassword() );

    xml.Save("users.xml");

}
bool FileWithUsers::ifFileExist()
{
    CMarkup xml;
    return xml.Load("users.xml");
}

vector <User> FileWithUsers::loadUsersFromFile()
{
    CMarkup xml;
    vector <User> users;
    User user;
    string item;
    //bool ifFileExist = xml.Load("Users.xml");

    xml.Load("users.xml");
    xml.ResetPos(); // top of document
    xml.FindElem(); // ORDER element is root
    xml.IntoElem();

    while ( xml.FindElem("USER"))
    {
        xml.FindChildElem("id");
        item=xml.GetChildData();
        user.setId(AuxiliaryMethods::convertStringToInt(item));
        xml.ResetChildPos();

        xml.FindChildElem("name");
        item=xml.GetChildData();
        user.setName(item);
        xml.ResetChildPos();

        xml.FindChildElem("surename");
        item=xml.GetChildData();
        user.setSurename(item);
        xml.ResetChildPos();

        xml.FindChildElem("login");
        item=xml.GetChildData();
        user.setlogin(item);
        xml.ResetChildPos();

        xml.FindChildElem("password");
        item=xml.GetChildData();
        user.setPassword(item);
        xml.ResetChildPos();

        users.push_back(user);
    }
    return users;
}

