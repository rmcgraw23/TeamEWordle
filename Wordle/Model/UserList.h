#ifndef USERLIST_H
#define USERLIST_H

#include <string>
#include<vector>
using namespace std;

#include "../Datatier/FileReader.h"
using namespace Datatier;

#include "User.h"

namespace model
{

class UserList
{
private:
    vector<User*> users;

public:
    UserList();
    virtual ~UserList();

    vector<User*> getUsers();
    void addUser(User* user);
    void updateUser(User* user);
};

}

#endif // USERLIST_H
