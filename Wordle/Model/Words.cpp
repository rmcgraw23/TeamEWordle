#include "Words.h"
#include <stdlib.h>
#include <iostream>

namespace model
{

Words::Words()
{
    this->guessCount = 0;
    this->word = "";
    this->reader = FileReader();
    this->words = this->reader.readInText();
    this->setRandomWord();


}

Words::~Words()
{

}

int Words::getGuessCount()
{
    return this->guessCount;
}

vector<string> Words::getWords()
{
    return this->words;
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

void Words::setRandomWord()
{
    srand(time(0));
    int randomIndex = (rand() % this->words.size()) + 1;
    this->word = this->words[randomIndex];


}

}
