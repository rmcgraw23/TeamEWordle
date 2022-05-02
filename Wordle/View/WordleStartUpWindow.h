#ifndef WORDLESTARTUPWINDOW_H
#define WORDLESTARTUPWINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>

#include <string>
#include <vector>
using namespace std;

#include <../Model/Words.h>
using namespace model;

#include "WordleGameWindow.h"

namespace View {

class WordleStartUpWindow : public Fl_Window
{
    private:
        Fl_Output *Header;
        Fl_Output *EnterNameLabel;
        Fl_Input *NameInput;
        Fl_Output *SettingsLabel;
        Fl_Button *SettingsButton;
        Fl_Button *StartButton;

        WordleGameWindow *mainWindow;

    public:
        WordleStartUpWindow(int width, int height, const char* title);
        virtual ~WordleStartUpWindow();

        static void HandleSettings(Fl_Widget* widget, void* data);
        static void HandleStart(Fl_Widget* widget, void* data);

};

}

#endif // WORDLESTARTUPWINDOW_H
