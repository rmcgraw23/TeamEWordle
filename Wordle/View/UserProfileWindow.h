#ifndef USERPROFILEWINDOW_H
#define USERPROFILEWINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>

#include <string>
#include <vector>
using namespace std;

#include "User.h"
using namespace model;

#include "WordleGameWindow.h"

namespace View
{

class UserProfileWindow : public Fl_Window
{
private:
    static const int InitialPosition = 70;

    vector<string> labelValues = {"Played", "Win%", "Current\nStreak", "Max\nStreak"};

    Fl_Output *Header;
    Fl_Box *GamesPlayedOutput;
    Fl_Output *GamesPlayedLabel;
    Fl_Box *WinPercentOutput;
    Fl_Output *WinPercentLabel;
    Fl_Box *WinStreakOutput;
    Fl_Output *WinStreakLabel;
    Fl_Box *MaxWinStreakOutput;
    Fl_Output *MaxWinStreakLabel;
    Fl_Output *GuessLabel;
    Fl_Button *NewGameButton;

    void SetUpStatisticsOutputs(Fl_Box* output);
    void SetUpStatisticsLabels(Fl_Output* label);
    void SetUpGuessLabels();
    vector<Fl_Output*> *guessValues;

    int CurrentObject;
    int GuessCount;

    User* user;
    vector<string> values;

    static void handleNewGame(Fl_Widget* widget, void* data);

public:
    UserProfileWindow(int width, int height, const char* title, User* user);
    virtual ~UserProfileWindow();

    void setUser(User* user);
    void updateOutputValues();

};

}

#endif // USERPROFILEWINDOW_H
