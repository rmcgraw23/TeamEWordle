#include "FileReader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <sstream>
using namespace std;

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

vector<User*> FileReader::ReadInUsers()
{
    vector<User*> users;
    vector<string> values;
    string line;
    ifstream myfile ("users.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            stringstream ss(line);
            while(getline(ss, line,  ' '))
            {
                values.push_back(line);
            }
            //vector<int> values = {stoi(values[4]), stoi(stoi(stoi(values[5]), stoi(values[6]), stoi(values[7]),
                                    //stoi(values[8]), stoi(values[9])};
            User* user = this->setUserStatistics(values);
            users.push_back(user);
        }
    }
    return users;
}

User* FileReader::setUserStatistics(vector<string> values)
{
    User* user = new User(values[0]);
    user->setGamesPlayed(stoi(values[1]));
    user->setWinPercentage(stoi(values[2]));
    user->setWinStreak(stoi(values[3]));
    user->setMaxWinStreak(stoi(values[4]));
    vector<int> guesses;
    for (int i = 0; i < 6; i++)
    {
        guesses.push_back(stoi(values[i]));
    }
    user->setGuessAmount(guesses);
    return user;
}

void FileReader::addToList(User user, vector<User*> userList)
{

}

}
