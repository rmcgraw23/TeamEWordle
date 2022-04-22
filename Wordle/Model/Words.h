#ifndef WORDS_H
#define WORDS_H
#include <string>
#include <vector>
#include <FileReader.h>

using namespace std;

class Words
{
    public:
        Words();
        virtual ~Words();
        int getGuessCount();
        void setGuessCount(int count);
        string getWord();
        vector<string> getWords();
        void setWord(string word);

    protected:

    private:
        int guessCount;
        string word;
        vector<string> words;
        FileReader reader;
        void setRandomWord();
};

#endif // WORDS_H
