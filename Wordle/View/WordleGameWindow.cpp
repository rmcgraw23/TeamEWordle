#include "WordleGameWindow.h"
#include "string"
#include "cctype"

namespace View {

WordleGameWindow::WordleGameWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    begin();

    this->values = new vector<Fl_Output*>();
    this->words = Words();
    this->LabelBuffer = new Fl_Box(100, 20, 50, 50);
    this->SetUpLetters();
    this->words.setWord("CANDY");
    //this->FirstLetterOutput = new Fl_Output(115, 75, 50, 50);
    //this->FirstLetterOutput = new Fl_Output(170, 75, 50, 50);
    //this->FirstLetterOutput = new Fl_Output(225, 75, 50, 50);
    //this->FirstLetterOutput = new Fl_Output(280, 75, 50, 50);
    //this->FirstLetterOutput = new Fl_Output(335, 75, 50, 50);
    //this->LetterOutputLabel->textsize(30);
    Fl_Output* value = this->values->at(0);
    value->value("A");
    value = this->values->at(1);
    value->value("Y");
    value = this->values->at(5);
    value->value("C");
    value = this->values->at(6);
    value->value("A");
    value = this->values->at(7);
    value->value("N");
    value = this->values->at(8);
    value->value("D");
    value = this->values->at(9);
    value->value("Y");
    this->SetUpButtons();
    this->validateGuess(0);
    this->validateGuess(5);
    this->validateGuess(10);
    this->validateGuess(15);
    this->validateGuess(20);
    this->validateGuess(25);
    end();
}

WordleGameWindow::~WordleGameWindow()
{
    //dtor
}

void WordleGameWindow::SetUpLetters()
{
    int x = INITIAL_X;
    int y = INITIAL_Y;
    int width = WIDTH_BUFFER;
    int height = HEIGHT_BUFFER;
    for (int i = 0; i < 30; i++)
    {
        if (i > 4 && i < 6)
        {
            y += 55;
            x = 115;
        }
        else if (i > 9 && i < 11)
        {
            y += 55;
            x = 115;
        }
        else if (i > 14 && i < 16)
        {
            y += 55;
            x = 115;
        }
        else if (i > 19 && i < 21)
        {
            y += 55;
            x = 115;
        }
        else if (i > 24 && i < 26)
        {
            y = 325;
            x = 115;
        }
        values->push_back(new Fl_Output(x, y, 50, 50));
        x += 55;
    }

}

void WordleGameWindow::validateGuess(int start)
{
    int count = 0;
    for (int i = start; i < start + 5; i++ ) {

        Fl_Output* value = this->values->at(i);
        auto letter = value->value();

        string word = this->words.getWord();
        for(auto& c : word)
        {
        c = toupper(c);
        }
        if (word.find(*letter) != string::npos) {
            value->color(FL_YELLOW);
        }
        if (*letter == word[count]) {
            value->color(FL_GREEN);
        }
        count++;
    }
}

void WordleGameWindow::SetUpButtons()
{
    int x = 55;
    int y = 385;
    vector<Fl_Button*> *buttons = new vector<Fl_Button*>();
    for (int i = 0; i < 28; i++)
    {
        this->keyboardButons = new string(this->keyValues[i]);
        if (i > 9 && i < 11)
        {
            y = 440;
            x = 75;
            buttons->push_back(new Fl_Button(x, y, 35, 50, this->keyboardButons->c_str()));
            x += 40;
        }
        else if (i > 18 && i < 20)
        {
            y = 495;
            x = 55;
            buttons->push_back(new Fl_Button(x, y, 55, 50, this->keyboardButons->c_str()));
            x += 60;
        }
        else if (i == 27)
        {
            buttons->push_back(new Fl_Button(x, y, 55, 50, this->keyboardButons->c_str()));
        }
        else
        {
            buttons->push_back(new Fl_Button(x, y, 35, 50, this->keyboardButons->c_str()));
            x += 40;
        }

    }
}

}
