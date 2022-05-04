#include "FileReader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <sstream>
namespace Datatier
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

vector<User*> FileReader::ReadInUsers()
{
    vector<User*> users;
    string line;
    ifstream myfile ("users.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            stringstream ss(line);
            vector<string> values;
            while(getline(ss, line,  ','))
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
    for (int i = 5; i < 11; i++)
    {
        guesses.push_back(stoi(values[i]));
    }
    user->setGuessAmount(guesses);
    return user;
}

}

