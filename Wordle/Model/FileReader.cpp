#include "FileReader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

namespace model
{

FileReader::FileReader()
{
    //ctor
}

FileReader::~FileReader()
{
    //dtor
}

vector<string> FileReader::readInText()
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
              words.push_back(line);
            }
          }
        }
        myfile.close();
        return words;
      }

}
