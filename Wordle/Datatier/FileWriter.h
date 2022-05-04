#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

#include <User.h>
using namespace model;

class FileWriter
{
    private:
        string formatOutput(vector<User*> users);
    public:
        FileWriter(const string& filename, vector<User*> users);
        virtual ~FileWriter();

};

#endif // FILEWRITER_H
