#include "Words.h"

Words::Words()
{
    this->guessCount = 0;
    this->word = "";
}

Words::~Words()
{

}

int Words::getGuessCount()
{
    return this->guessCount;
}

string Words::getWord()
{
    return this->word;
}

void Words::setGuessCount(int guesses)
{
    this->guessCount = guesses;
}

void Words::setWord(string word)
{
    this->word = word;
}
