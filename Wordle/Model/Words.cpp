#include "Words.h"
#include <stdlib.h>
#include <iostream>

namespace model
{

/**
*The constructor for the words class
*/
Words::Words()
{
    this->guessCount = 0;
    this->word = "";
    this->reader = FileReader();
    this->words = this->reader.readInText(true);
    this->setRandomWord();


}

/**
*The destructor for the words class
*/
Words::~Words()
{

}

/**
*Gets the guess count for the game.
*
*@returns this->guessCount
*/
int Words::getGuessCount()
{
    return this->guessCount;
}

/**
*Gets Words collection for the game
*
*@returns this->words
*/
vector<string> Words::getWords()
{
    return this->words;
}

/**
*Gets the selected word for the game
*
*@returns this->word
*/
string Words::getWord()
{
    return this->word;
}

/**
*Sets the guess count for the game.
*
*@param guesses the number of guesses.
*/
void Words::setGuessCount(int guesses)
{
    this->guessCount = guesses;
}

/**
*Sets the word for the game.
*
*@param word the word being set.
*/
void Words::setWord(string word)
{
    this->word = word;
}

/**
*Sets the collection of words for the game
*
*@param words the collection of words being set
*/
void Words::setWords(vector<string> words)
{
    this->words = words;
}

/**
*Sets the selected word to be a random word from the collection of words to start the game.
*
*/
void Words::setRandomWord()
{
    srand(time(0));
    int randomIndex = (rand() % this->words.size()) + 1;
    this->word = this->words[randomIndex];


}

}
