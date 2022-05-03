#include "UserProfileWindow.h"

namespace View{

UserProfileWindow::UserProfileWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    this->CurrentObject = 0;
    begin();
    this->Header = new Fl_Output(180, 15, 0, 0, "Statistics");

    this->SetUpStatisticsOutputs(this->GamesPlayedOutput);
    this->SetUpStatisticsLabels(this->GamesPlayedLabel);
    this->SetUpStatisticsOutputs(this->WinPercentOutput);
    this->SetUpStatisticsLabels(this->WinPercentLabel);
    this->SetUpStatisticsOutputs(this->WinStreakOutput);
    this->SetUpStatisticsLabels(this->WinStreakLabel);
    this->SetUpStatisticsOutputs(this->MaxWinStreakOutput);
    this->SetUpStatisticsLabels(this->MaxWinStreakLabel);
    this->GuessLabel = new Fl_Output(220, 100, 0, 0, "Guess Distribution");
    this->SetUpGuessLabels();

    end();
}

void UserProfileWindow::SetUpStatisticsLabels(Fl_Output* label)
{
     int x = (this->CurrentObject * 40) + InitialPosition + 23;
     label = new Fl_Output(x + 10, 70, 0, 0, this->labelValues[this->CurrentObject].c_str());
     label->labelsize(10);
     this->CurrentObject += 1;
}

void UserProfileWindow::SetUpStatisticsOutputs(Fl_Box* output)
{
    int x = (this->CurrentObject * 40) + InitialPosition;
    output = new Fl_Box(x, 30, 30, 30);
    output->labelsize(30);
    output->box (FL_DOWN_BOX);
    output->color(FL_WHITE);
    //this->CurrentObject += 1;
}

void UserProfileWindow::SetUpGuessLabels()
{
    this->guessValues = new vector<Fl_Output*>;
    vector<string> values = {"1", "2", "3", "4", "5", "6"};
    int x = 60;
    for (int i = 0; i < 6; i++)
    {
        //string val = to_string(i);
        Fl_Output *guess = new Fl_Output(x, 120, 20, 20, "1");
        x += 35;
        this->guessValues->push_back(guess);
    }
}

void UserProfileWindow::setUser(User* user)
{
    this->user = user;
}

UserProfileWindow::~UserProfileWindow()
{
    //dtor
}

}
