#ifndef FILEREADER_H
#define FILEREADER_H
#include "vector"
#include "string"
using namespace std;

#include "User.h"
using namespace model;

namespace Datatier
{

class FileReader
{
public:
    FileReader();
    virtual ~FileReader();
    vector<string> readInText(bool repeating);
    vector<User*> ReadInUsers();

protected:

private:
    bool isNotRepeating(string word);
    User* setUserStatistics(vector<string> values);
};

}

#endif // FILEREADER_H
