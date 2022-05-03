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
#include <FL/Fl_Input.H>
#include "../Model/Words.h"

#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#include <../Model/Words.h>
#include<User.h>
#include<UserList.h>
using namespace model;

#include "../UserProfileWindow.h"

namespace View {

class WordleGameWindow : public Fl_Window
{
    private:
        static const int INITIAL_X = 115;
        static const int INITIAL_Y = 50;
        static const int WIDTH_BUFFER = 50;
        static const int HEIGHT_BUFFER = 50;
        static const int LETTERS_PER_ROW = 5;
        int currentBox = 0;

        vector<Fl_Box*> *values;
        vector<Fl_Button*> *buttons;

        vector<string> keyValues = {"Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "A", "S", "D", "F",
                                    "G", "H", "J", "K", "L", "enter", "Z", "X", "C", "V", "B", "N", "M", "back"};
        string* keyboardButons;
        Fl_Box *LabelBuffer;
        Fl_Label *label;
        Fl_Output *FirstLetterOutput;
        Fl_Output *SecondLetterOutput;
        Fl_Output *ThirdLetterOutput;
        Fl_Output *FourthLetterOutput;
        Fl_Output *FifthLetterOutput;

        void SetUpLetters();
        void SetUpButtons();

        static int keyhandler(int event);
        inline static WordleGameWindow* window;
        Words words;
        void validateGuess(int start);
        void isValidWord();


        void GetWindow(WordleGameWindow* cwindow);
        void DeleteLetter(WordleGameWindow* window);

        Words* word;

        User* user;
        UserList* userList;

        void UpdateUserForloss();
        void UpdateUserForWin(int position);

    public:
        WordleGameWindow(int width, int height, const char* title);
        virtual ~WordleGameWindow();

        static void keyboardButtonClicked(Fl_Widget* widget, void* data);
        static void keyboardPressed(Fl_Widget* widget, void* data);
        static void EnterButtonClicked(Fl_Widget* widget, void* data);
        static void BackspaceButtonClicked(Fl_Widget* widget, void* data);
        void SetBoxValue(const char* value);
        void SetUpUser(const string& name);


};

}
#endif // WORDLEGAMEWINDOW_H
