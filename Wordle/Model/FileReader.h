#ifndef FILEREADER_H
#define FILEREADER_H
#include "vector"
#include "string"
using namespace std;

namespace model
{

class FileReader
{
public:
    FileReader();
    virtual ~FileReader();
    vector<string> readInText(bool repeating);

protected:

private:
    bool isNotRepeating(string word);
};

}

#endif // FILEREADER_H
