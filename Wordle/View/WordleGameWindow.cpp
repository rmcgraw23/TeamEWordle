#include "WordleGameWindow.h"

namespace View {

WordleGameWindow::WordleGameWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    begin();
    this->words = Words();
    this->LabelBuffer = new Fl_Box(100, 20, 50, 50);
    values = new vector<Fl_Box*>();
    this->SetUpLetters();
    cout << this->words.getWord() << endl;
    //this->FirstLetterOutput = new Fl_Output(115, 75, 50, 50);
    //this->FirstLetterOutput = new Fl_Output(170, 75, 50, 50);
    //this->FirstLetterOutput = new Fl_Output(225, 75, 50, 50);
    //this->FirstLetterOutput = new Fl_Output(280, 75, 50, 50);
    //this->FirstLetterOutput = new Fl_Output(335, 75, 50, 50);
    //this->LetterOutputLabel->textsize(30);
    //this->LetterOutputLabel->value(" A");
    this->SetUpButtons();
    string result = "";
    end();
    this->word = new Words();
    //Fl_Event_Handler event = new Fl_Event_Handler(keyhandler);
    //window = new WordleGameWindow(600, 500, "Wordle");
    this->GetWindow(this);
    Fl::add_handler(keyhandler);
    //this->buttons->at(19)->callback(EnterButtonClicked, this);
    //this->buttons->at(19)->when(FL_WHEN_ENTER_KEY_ALWAYS);
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

void WordleGameWindow::validateGuess(int start)
{

    string guess = "";
    string word = this->words.getWord();
    int count = 0;
    for (int i = start; i < start + 5; i++ ) {

        Fl_Box *value = this->values->at(i);
        auto letter = value->label();



        for(auto& c : word)
        {
        c = toupper(c);
        }
        if (letter != nullptr) {
        guess += letter;
        if (word.find(letter) != string::npos) {
            value->color(FL_YELLOW);
            value->label(letter);
        }
        if (*letter == word[count]) {

            value->color(FL_GREEN);
            value->label(letter);
        }
        }
        count++;
    }
    //cout << word << endl;
    //cout << guess << endl;
    if (guess == word)  {
        cout << "YOU WON" << endl;
    }
}

void WordleGameWindow::GetWindow(WordleGameWindow* cwindow)
{
    window = cwindow;
}

int WordleGameWindow::keyhandler(int event) {
    int result = 0;
    //WordleGameWindow window = WordleGameWindow(500, 600, "wordle");

    if (event == FL_KEYUP)
    {
        cout << "hi" << endl;
    }
    else if (event == FL_SHORTCUT) {

        if (Fl::event_key() == 10)
        {
            cout << "enter" << endl;
            //keyboardPressed;
            result = 1;
        }
        if (Fl::event_key() == FL_BackSpace)
        {
            cout << "back" << endl;
            window->DeleteLetter(window);
        }
        else
        {
            string value = Fl::event_text();
            transform(value.begin(), value.end(), value.begin(), ::toupper);
            for (int i = 0; i < 29; i++)
            {
                if (window->keyValues[i] == value)
                {
                    window->values->at(window->currentBox)->label(window->keyValues[i].c_str());
                }
            }
            //const char* letter = value.c_str()[0];
            //

            //Fl_Box* box = window->values->at(window->currentBox + 1);
            //box->label("");
            window->currentBox += 1;
            cout << std::toupper(value[0]) << endl;
            return 1;
        }
    }
    //cout << Fl::event_key() << endl;
    return result;
}

void WordleGameWindow::keyboardButtonClicked(Fl_Widget* widget, void* data)
{
    WordleGameWindow* window = (WordleGameWindow*)data;
    Fl_Button *button = (Fl_Button*) widget;
    //string value = button->label();
    window->SetBoxValue(button->label());
    window->currentBox += 1;
    //window->validateGuess(0);
    cout << button->label() << endl;
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
    window->validateGuess(0);
    window->validateGuess(5);
    window->validateGuess(10);
    window->validateGuess(15);
    window->validateGuess(20);
    window->validateGuess(25);

}

void WordleGameWindow::BackspaceButtonClicked(Fl_Widget* widget, void* data)
{
    WordleGameWindow* window = (WordleGameWindow*)data;
    window->DeleteLetter(window);
}

void WordleGameWindow::DeleteLetter(WordleGameWindow* window)
{
    if (window->currentBox > 0)
    {
        window->currentBox -= 1;
    }
    window->values->at(window->currentBox)->label("");
}

void WordleGameWindow::SetBoxValue(const char* value)
{
    Fl_Box* box = values->at(this->currentBox);
    box->label(value);
    /*this->validateGuess(0);
    */

}

}
