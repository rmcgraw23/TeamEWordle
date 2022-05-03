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
    this->words = this->reader.readInText(true);
    this->setRandomWord();


}

Words::Words(bool repeating)
{
    this->guessCount = 0;
    this->word = "";
    this->reader = FileReader();
    this->words = this->reader.readInText(repeating);
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

void Words::setWords(vector<string> words) {
    this->words = words;
}

void Words::setRandomWord()
{
    srand(time(0));
    int randomIndex = (rand() % this->words.size()) + 1;
    this->word = this->words[randomIndex];


}

}
