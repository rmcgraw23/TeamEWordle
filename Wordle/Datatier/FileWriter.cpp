#include "FileWriter.h"

FileWriter::FileWriter(const string& filename, vector<User*> users)
{
    ofstream myfile;
    cout << users.size() << endl;
    myfile.open(filename, ofstream::trunc);

    if (myfile.is_open())
    {
        myfile << this->formatOutput(users);
    }
    myfile.close();
}

string FileWriter::formatOutput(vector<User*> users)
{
    stringstream buffer;
    for (int i = 0; i < users.size(); i++)
    {
        buffer << users[i]->getName() << "," << users[i]->getGamesPlayed() << "," << users[i]->getWinPercentage() << "," << users[i]->getWinStreak() << "," <<
               users[i]->getMaxWinStreak();
        //cout << buffer.str() << endl;
        for (int j = 0; j < users[i]->getguesses().size(); j++)
        {
            buffer << "," << users[i]->getguesses()[j];
            //cout << buffer.str() << endl;
        }
        buffer << endl;
    }
    //cout << buffer.str() << endl;
    return buffer.str();
}

FileWriter::~FileWriter()
{
    //dtor
}
