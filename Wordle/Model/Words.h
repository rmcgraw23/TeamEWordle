#ifndef WORDS_H
#define WORDS_H
#include <string>

using namespace std;

class Words
{
    public:
        Words();
        virtual ~Words();
        int getGuessCount();
        void setGuessCount(int count);
        string getWord();
        void setWord(string word);

    protected:

    private:
        int guessCount;
        string word;
};

#endif // WORDS_H
