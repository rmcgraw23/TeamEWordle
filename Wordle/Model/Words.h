#ifndef WORDS_H
#define WORDS_H
#include <string>
#include <vector>
#include "FileReader.h"

using namespace std;

#include "FileReader.h"

namespace model
{

class Words
{
    public:
        Words();
        Words(bool repeating);
        virtual ~Words();
        int getGuessCount();
        void setGuessCount(int count);
        string getWord();
        vector<string> getWords();
        void setWord(string word);
        void setWords(vector<string> words);
        void setRandomWord();


    protected:

    private:
        int guessCount;
        string word;
        vector<string> words;
        FileReader reader;
};

}

#endif // WORDS_H
