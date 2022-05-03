#ifndef FILEREADER_H
#define FILEREADER_H
#include "vector"
#include "string"
using namespace std;

#include "User.h"

namespace model
{

class FileReader
{
    public:
        FileReader();
        virtual ~FileReader();

 		vector<string> readInText();
        vector<User*> ReadInUsers();
        
        vector<string> readInText(bool repeating);
        bool isNotRepeating(string word);

    protected:

    private:
        void addToList(User user, vector<User*> userList);
        User* setUserStatistics(vector<string> values);

};

}

#endif // FILEREADER_H
