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

namespace View{

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

        void SetUpStatisticsOutputs(Fl_Box* output);
        void SetUpStatisticsLabels(Fl_Output* label);
        void SetUpGuessLabels();
        vector<Fl_Output*> *guessValues;

        int CurrentObject;
        int GuessCount;

    public:
        UserProfileWindow(int width, int height, const char* title);
        virtual ~UserProfileWindow();

};

}

#endif // USERPROFILEWINDOW_H
