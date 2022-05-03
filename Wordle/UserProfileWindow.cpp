#include "UserProfileWindow.h"

#include <iostream>

namespace View{

UserProfileWindow::UserProfileWindow(int width, int height, const char* title, User* user) : Fl_Window(width, height, title)
{
    this->CurrentObject = 0;
    this->user = user;
    this->values = {to_string(this->user->getGamesPlayed()), to_string(this->user->getWinPercentage()), to_string(this->user->getWinStreak()),
                    to_string(this->user->getMaxWinStreak())};
    this->GuessCount = 0;
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
    //this->updateOutputValues();
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
    output = new Fl_Box(x, 30, 30, 30, values[this->GuessCount].c_str());
    //output->labelsize(30);
    output->box (FL_DOWN_BOX);
    output->color(FL_WHITE);
    this->GuessCount += 1;
    //output->label("H");
    //this->CurrentObject += 1;
}

void UserProfileWindow::SetUpGuessLabels()
{
    this->guessValues = new vector<Fl_Output*>;
    vector<const char*> values = {"1", "2", "3", "4", "5", "6"};
    vector<string> vals = {to_string(this->user->getguesses()[0]), to_string(this->user->getguesses()[1]), to_string(this->user->getguesses()[2]),
                            to_string(this->user->getguesses()[3]), to_string(this->user->getguesses()[4]), to_string(this->user->getguesses()[5])};
    int x = 60;
    for (int i = 0; i < 6; i++)
    {
        //string val = to_string(i);
        Fl_Output *guess = new Fl_Output(x, 120, 20, 20, values[i]);
        guess->value(vals[i].c_str());
        x += 35;
        this->guessValues->push_back(guess);
    }
}

void UserProfileWindow::setUser(User* user)
{
    this->user = user;

    this->GamesPlayedLabel->redraw();
    cout << this->user->getGamesPlayed() << endl;
}

void UserProfileWindow::updateOutputValues()
{
    this->GamesPlayedOutput->label("H");

}

UserProfileWindow::~UserProfileWindow()
{
    //dtor
}

}
