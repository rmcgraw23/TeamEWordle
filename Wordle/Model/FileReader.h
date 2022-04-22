#ifndef FILEREADER_H
#define FILEREADER_H
#include "vector"
#include "string"
using namespace std;


class FileReader
{
    public:
        FileReader();
        virtual ~FileReader();
        vector<string> readInText();

    protected:

    private:
};

#endif // FILEREADER_H
