#include "FileReader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

namespace model
{

/**
*The constructor for the FileReader
*/
FileReader::FileReader()
{
    //ctor
}

/**
*The destructor for the FileReader
*/
FileReader::~FileReader()
{
    //dtor
}


/**
*Reads in the text and adds it to a collection
*
*@param repeating whether or not repeating letters is allowed
*
*@return words the vector of words
*/
vector<string> FileReader::readInText(bool repeating)
{
    vector<string> words;
    string line;
    ifstream myfile ("dictionary.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            if(line.length() == 6)
            {
                line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
                if (!repeating)
                {
                    if(isNotRepeating(line))
                    {
                        words.push_back(line);
                    }
                }
                else
                {
                    words.push_back(line);
                }
            }
        }
    }
    myfile.close();
    return words;
}

bool FileReader::isNotRepeating(string word)
{
    for (int i = 0, j = word.size(); i < j; i++)
    {
        for (int k = i+1; k < j; k++)
        {
            if (word[i] == word[k])
            {
                return false;
            }

        }
    }
    return true;
}

}

