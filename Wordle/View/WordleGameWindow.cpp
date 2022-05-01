#include "WordleGameWindow.h"
#include <algorithm>
#define Level_1

namespace View {

WordleGameWindow::WordleGameWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    begin();
    this->words = Words();
    this->LabelBuffer = new Fl_Box(100, 20, 50, 50);
    values = new vector<Fl_Box*>();
    buttons = new vector<Fl_Button*>();
    this->SetUpLetters();
    #ifdef Level_1
    cout << this->words.getWord() << endl;
    #endif
    //this->FirstLetterOutput = new Fl_Output(115, 75, 50, 50);
    //this->FirstLetterOutput = new Fl_Output(170, 75, 50, 50);
    //this->FirstLetterOutput = new Fl_Output(225, 75, 50, 50);
    //this->FirstLetterOutput = new Fl_Output(280, 75, 50, 50);
    //this->FirstLetterOutput = new Fl_Output(335, 75, 50, 50);
    //this->LetterOutputLabel->textsize(30);
    //this->LetterOutputLabel->value(" A");
    this->SetUpButtons();
    end();

    Fl::add_handler(keyhandler);
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
        Fl_Box *output = new Fl_Box(x, y, 50, 50);
        output->labelsize(30);
        output->box (FL_DOWN_BOX);
        output->color(FL_WHITE);
        values->push_back(output);
        x += 55;
    }

}

void WordleGameWindow::SetUpButtons()
{
    int x = 55;
    int y = 385;
    Fl_Button *button;
    buttons = new vector<Fl_Button*>();
    for (int i = 0; i < 28; i++)
    {
        this->keyboardButons = new string(this->keyValues[i]);
        if (i > 9 && i < 11)
        {
            y = 440;
            x = 75;
            button = new Fl_Button(x, y, 35, 50, this->keyboardButons->c_str());
            button->callback(keyboardButtonClicked, this);
            buttons->push_back(button);
            x += 40;
        }
        else if (i > 18 && i < 20)
        {
            y = 495;
            x = 55;
            button = new Fl_Button(x, y, 55, 50, this->keyboardButons->c_str());
            button->callback(EnterButtonClicked, this);
            buttons->push_back(button);
            x += 60;
        }
        else if (i == 27)
        {
            button = new Fl_Button(x, y, 55, 50, this->keyboardButons->c_str());
            button->callback(BackspaceButtonClicked, this);
            buttons->push_back(button);
        }
        else
        {
            button = new Fl_Button(x, y, 35, 50, this->keyboardButons->c_str());
            button->callback(keyboardButtonClicked, this);
            buttons->push_back(button);
            x += 40;
        }

    }
}

void WordleGameWindow::isValidWord() {
    Fl_Box* value5 = this->values->at(4);
    Fl_Box* value1 = this->values->at(0);
    Fl_Box* value2 = this->values->at(1);
    Fl_Box* value3 = this->values->at(2);
    Fl_Box* value4 = this->values->at(3);
    auto letter = value5->label();
    if (letter != nullptr){
        string guess = string("");
        guess += value1->label();
        guess += value2->label();
        guess += value3->label();
        guess += value4->label();
        guess += value5->label();
        for(auto& c : guess)
        {
        c = tolower(c);
        }
        cout << guess << endl;
        vector<string> gameWords = words.getWords();
    if(std::find(gameWords.begin(), gameWords.end(), guess) != gameWords.end()) {
    cout << "valid" <<endl;
    } else {
    cout << "invalid" <<endl;
    }


    }
}

void WordleGameWindow::validateGuess(int start)
{
    string guess = string("");
    int count = 0;
    Fl_Button* button = this->buttons->at(4);
    for (int i = start; i < start + 5; i++ ) {
        Fl_Box* value = this->values->at(i);
        Fl_Button* button;
        auto letter = value->label();
        string word = this->words.getWord();
        for(auto& c : word)
        {
        c = toupper(c);
        }
        if (letter != nullptr) {

        guess += letter;
         for (int i = 0; i < this->buttons->size(); i++ ) {
            button = this->buttons->at(i);
            const char* buttonLetter = button->label();
            if (buttonLetter == letter) {
                 button->color(FL_DARK2);
            }
            }
        if (word.find(letter) != string::npos) {
            value->color(FL_YELLOW);
            for (int i = 0; i < this->buttons->size(); i++ ) {
            button = this->buttons->at(i);
            const char* buttonLetter = button->label();
            if (buttonLetter == letter) {
                 button->color(FL_YELLOW);
            }
            }
        }
        if (*letter == word[count]) {
            value->color(FL_GREEN);
            for (int i = 0; i < this->buttons->size(); i++ ) {
            button = this->buttons->at(i);
            const char* buttonLetter = button->label();
            if (buttonLetter == letter) {
                 button->color(FL_GREEN);
            }
            }
        }

        }
        count++;
    }
    if(guess == this->words.getWord())  {
        cout << "YOU WON" << endl;
    }
}

int WordleGameWindow::keyhandler(int event) {

    if (event == FL_SHORTCUT) {

        if (Fl::event_key() == 'enter')
        {
            cout << Fl::event_text() << endl;
            keyboardPressed;

            return 1;
        }
        else if (Fl::event_key() == 'backspace')
        {
            cout << 'back' << endl;

        }
        else
        {
            cout << "back" << endl;
        }
    }
    return 0;
}

void WordleGameWindow::keyboardButtonClicked(Fl_Widget* widget, void* data)
{
    WordleGameWindow* window = (WordleGameWindow*)data;
    Fl_Button *button = (Fl_Button*) widget;
    window->SetBoxValue(button->label());
    window->currentBox += 1;
    //cout << button->label() << endl;
}

void WordleGameWindow::keyboardPressed(Fl_Widget* widget, void* data)
{
    WordleGameWindow* window = (WordleGameWindow*)data;
    //cout << "y" << endl;
    window->SetBoxValue("y");
}

void WordleGameWindow::EnterButtonClicked(Fl_Widget* widget, void* data)
{
    WordleGameWindow* window = (WordleGameWindow*)data;

}

void WordleGameWindow::BackspaceButtonClicked(Fl_Widget* widget, void* data)
{
    WordleGameWindow* window = (WordleGameWindow*)data;
    if (window->currentBox > 0)
    {
        window->currentBox -= 1;
    }
    window->values->at(window->currentBox)->label("");
}

void WordleGameWindow::SetBoxValue(const char* value)
{
    Fl_Box* box = this->values->at(this->currentBox);
    box->label(value);
    this->isValidWord();
    this->validateGuess(0);
    this->validateGuess(5);
    this->validateGuess(10);
    this->validateGuess(15);
    this->validateGuess(20);
    this->validateGuess(25);

}

}
