#include "WordleStartUpWindow.h"

namespace View
{

WordleStartUpWindow::WordleStartUpWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    this->begin();
    this->Header = new Fl_Output(270, 15, 0, 0, "Welcome to Wordle");
    this->EnterNameLabel = new Fl_Output(285, 60, 0, 0, "Please enter a username");
    this->NameInput = new Fl_Input(145, 80, 100, 25);
    this->StartButton = new Fl_Button(145, 225, 100, 30, "Start Game");
    this->StartButton->callback(HandleStart, this);
    this->end();

    this->username = "";
}

void WordleStartUpWindow::HandleStart(Fl_Widget* widget, void* data)
{
    WordleStartUpWindow* window = (WordleStartUpWindow*)data;
    window->username = window->NameInput->value();
    window->mainWindow = new WordleGameWindow(500, 600, "Wordle by Mcgraw and Thompson");
    window->mainWindow->SetUpUser(window->username);
    window->mainWindow->show();
    window->hide();
}

WordleStartUpWindow::~WordleStartUpWindow()
{
    //dtor
}

}
