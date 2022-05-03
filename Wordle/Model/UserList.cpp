#include "UserList.h"

namespace model{

UserList::UserList()
{
    FileReader reader = FileReader();
    this->users = reader.ReadInUsers();
}

vector<User*> UserList::getUsers()
{
    return this->users;
}

void UserList::addUser(User* user)
{
    this->users.push_back(user);
}

void UserList::updateUser(User* user)
{
    for (int i = 0; i < this->users.size(); i++)
    {
        if(this->users[i]->getName() == user->getName())
        {
            this->users[i] = user;
        }
    }
}

UserList::~UserList()
{
    //dtor
}

}
