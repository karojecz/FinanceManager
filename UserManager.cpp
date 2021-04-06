# include "UserManager.h"

User UserManager::getNewUserData()
{
    User user;
    string name, surename, login, password;
    int userId;

    user.setId(setIdOfNewUser());

    cout<<"Enter Your name"<<endl;
    cin>>name;
    user.setName(name);
    cout<<"Enter Your surname"<<endl;
    cin>>surename;
    user.setSurename(surename);
    cout<<"Enter Your login"<<endl;
    cin>>login;
    while(isLoginExist(login))
    {
        cout<<"This login already exist, enter different login"<<endl;
        cin>>login;
    }
    user.setlogin(login);
    cout<<"Enter Your password"<<endl;
    cin>>password;
    user.setPassword(password);

    return user;

}
int UserManager::setIdOfNewUser()
{
    User lastUser;
    if(!fileWithUser.ifFileExist())
    {
        return 1;
    }
    else
    {
        lastUser=users.back();
        return lastUser.downloadId()+1;
    }
}
void UserManager::Registration()
{
    User user=getNewUserData();
    users.push_back(user);
    fileWithUser.adNewUserToFile(user);
    cout<<"Registration complete"<<endl;
    system ("pause");

}
bool UserManager::isLoginExist(string login)
{
    for (int i=0; i<users.size(); i++)
    {
        if(login==users[i].downloadLogin())
            return true;
    }
    return false;
}
int UserManager::UserLogin()
{
    string login,password;
    User user;
    cout<<"Enter Your login"<<endl;
    cin>>login;

    if( isLoginExist(login))
    {
        for (int i=0; i<users.size(); i++)
        {
            if(login==users[i].downloadLogin())
                user=users[i];
        }
        cout<<"Enter Your password"<<endl;


        for(int i=0; i<3; i++)
        {
            cin>>password;
        if (password==user.downloadPassword())
        {
            cout<<"You are logged in."<<endl;
            system ("pause");
            return user.downloadId();
        }
        else
        {
            cout<<"Password is incorrect, try again."<<endl;

        }
        }
        cout<<"You enter wrong password tree times. Try again later."<<endl;
        Sleep(2500);

        return 0;
    }
    else
        cout<<"Login does not exist"<<endl;
        system("pause");
        return 0;
}
