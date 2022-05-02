#include "User.h"

namespace model{

User::User(const string& name)
{
    this->name = name;
    this->gamesPlayed = 0;
    this->winPercent = 0;
    this->winStreak = 0;
    this->maxWinStreak = 0;
}

string User::getName()
{
    return this->name;
}

int User::getGamesPlayed()
{
    return this->gamesPlayed;
}

int User::getWinPercentage()
{
    return this->winPercent;
}

int User::getWinStreak()
{
    return this->winStreak;
}

int User::getMaxWinStreak()
{
    return this->maxWinStreak;
}

vector<int> User::getguesses()
{
    return this->guessValues;
}

void User::setName(string const& name)
{
    this->name = name;
}

void User::setGamesPlayed(int gamesPlayed)
{
    this->gamesPlayed = gamesPlayed;
}

void User::setWinPercentage(int wins)
{
    this->winPercent = (wins / this->gamesPlayed) * 100;
}

void User::setWinStreak(int winStreak)
{
    this->winStreak = winStreak;
}

void User::setMaxWinStreak(int maxWinStreak)
{
    this->maxWinStreak;
}

void User::setGuessAmount(int guessCount, int amount)
{
    this->guessValues.at(amount) = guessCount;
}

User::~User()
{
    //dtor
}

}
