#ifndef WORDLEGAMEWINDOW_H
#define WORDLEGAMEWINDOW_H


#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>

#include <string>
#include <vector>
#include <iomanip>

#include "../Model/Words.h"
using namespace std;

namespace View {

class WordleGameWindow : public Fl_Window
{
    private:
        static const int INITIAL_X = 115;
        static const int INITIAL_Y = 50;
        static const int WIDTH_BUFFER = 50;
        static const int HEIGHT_BUFFER = 50;
        static const int LETTERS_PER_ROW = 5;

        vector<string> keyValues = {"Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "A", "S", "D", "F",
                                    "G", "H", "J", "K", "L", "enter", "Z", "X", "C", "V", "B", "N", "M", "back"};
        string* keyboardButons;
        Fl_Box *LabelBuffer;
        Fl_Output *FirstLetterOutput;
        Fl_Output *SecondLetterOutput;
        Fl_Output *ThirdLetterOutput;
        Fl_Output *FourthLetterOutput;
        Fl_Output *FifthLetterOutput;

        void SetUpLetters();
        void SetUpButtons();

        vector<Fl_Output*> *values;

        void validateGuess(int start);
        Words words;

    public:
        WordleGameWindow(int width, int height, const char* title);
        virtual ~WordleGameWindow();

};

}
#endif // WORDLEGAMEWINDOW_H
