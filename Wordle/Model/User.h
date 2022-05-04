#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
using namespace std;

namespace model
{

class User
{
private:
    string name;
    int gamesPlayed;
    int winPercent;
    int winStreak;
    int maxWinStreak;
    vector<int> guessValues = {0, 0, 0, 0, 0, 0};

public:
    User(const string& name);

    virtual ~User();

    string getName();
    int getGamesPlayed();
    int getWinPercentage();
    int getWinStreak();
    int getMaxWinStreak();
    vector<int> getguesses();

    void setName(string const& name);
    void setGamesPlayed(int gamesPlayed);
    void setWinPercentage(int winPercent);
    void setWinStreak(int winStreak);
    void setMaxWinStreak(int maxWinstreak);
    void setGuessAmount(vector<int> guesses);

    int getTotalGuesses();
    void setOneGuessAmount(int positon, int guess);

};

}

#endif // USER_H
