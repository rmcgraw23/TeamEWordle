#include "WordleGameWindow.h"
#include <algorithm>
#include <stdlib.h>
#define Level_1

#include "../Datatier/FileReader.h"
using namespace Datatier;

namespace View
{
/**
*Constructor for the wordle game window
*/
WordleGameWindow::WordleGameWindow(int width, int height, const char* title) : Fl_Window(width, height, title)
{
    begin();
    this->words = Words();
    this->LabelBuffer = new Fl_Box(100, 20, 50, 50);
    values = new vector<Fl_Box*>();
    buttons = new vector<Fl_Button*>();
    Fl_Button* setting = new Fl_Button(400, 20, 100, 50, "Repeat on");
    setting->callback(repeatButtonClicked, this);
    this->SetUpLetters();
    this->reader = FileReader();
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
    string result = "";
    end();
    this->userList = new UserList();
    //Fl_Event_Handler event = new Fl_Event_Handler(keyhandler);
    //window = new WordleGameWindow(600, 500, "Wordle");
    this->GetWindow(this);
    Fl::add_handler(keyhandler);
    //this->buttons->at(19)->callback(EnterButtonClicked, this);
    //this->buttons->at(19)->when(FL_WHEN_ENTER_KEY_ALWAYS);
    this->user = NULL;
}

/**
*Destructor for the wordle game window
*/
WordleGameWindow::~WordleGameWindow()
{
    //dtor
}


void WordleGameWindow::SetUpUser(const string& name)
{

    for (int i = 0; i < this->userList->getUsers().size(); i++)
    {
        if (this->userList->getUsers()[i]->getName() == name)
        {
            this->user = this->userList->getUsers()[i];
        }
    }
    if (this->user == NULL)
    {
        this->user = new User(name);
        this->userList->addUser(this->user);
    }
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
bool WordleGameWindow::isValidWord()
{
    Fl_Box* value5 = this->values->at(4);
    Fl_Box* value1 = this->values->at(0);
    Fl_Box* value2 = this->values->at(1);
    Fl_Box* value3 = this->values->at(2);
    Fl_Box* value4 = this->values->at(3);
    auto letter = value5->label();
    if (letter != nullptr)
    {
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
        if(std::find(gameWords.begin(), gameWords.end(), guess) != gameWords.end())
        {
            return true;
        }
        else
        {
            return false;
        }


    }
}

void WordleGameWindow::validateGuess(int start)
{
    string guess = "";
    int count = 0;
    for (int i = start; i < start + 5; i++ )
    {
        Fl_Box* value = this->values->at(i);
        Fl_Button* button;
        auto letter = value->label();
        string word = this->words.getWord();
        for(auto& c : word)
        {
            c = toupper(c);
        }
        if (letter != nullptr)
        {

            guess += letter;
            changeButtonColor(FL_DARK2, letter);
            if (word.find(letter) != string::npos)
            {
                value->color(FL_YELLOW);
                this->changeButtonColor(FL_YELLOW, letter);

                value->label(letter);
            }
            if (*letter == word[count])
            {

                value->color(FL_GREEN);
                this->changeButtonColor(FL_GREEN, letter);
                value->label(letter);
            }

        }
        count++;
        redraw();
        /*if (guess == word)
        {
            switch ( fl_choice("You Won! Would you like to play again?", "No", "Yes", 0) )
            {
            case 0:
                exit(3);
            case 1:
                this->words.setRandomWord();
                this->resetBoard();
            }
        }
        else if (this->words.getGuessCount() == 5)
        {
            switch ( fl_choice("You Lost! Would you like to play again?", "No", "Yes", 0) )
            {
            case 0:
                exit(3);
            case 1:
                this->words.setRandomWord();
                this->resetBoard();
            }
        }*/

        this->word->setGuessCount(1);


        if (guess == word)
        {
            cout << "YOU WON" << endl;
            this->UpdateUserForWin(this->words.getGuessCount());
            cout << this->userList->getUsers().size() << endl;
            FileWriter writer = FileWriter("users.txt", this->userList->getUsers());
            UserProfileWindow* window = new UserProfileWindow(300, 200, "User Statistics", this->user);
            window->show();
            this->hide();
            //window->setUser(this->user);
        }
        else if (this->word->getGuessCount() == 6)
        {
            this->UpdateUserForloss();
            //FileWriter writer = FileWriter("users.txt", this->userList->getUsers());
            UserProfileWindow* window = new UserProfileWindow(300, 200, "User Statistics", this->user);
            window->show();
            this->hide();
            //window->setUser(this->user);
        }
    }
}

void WordleGameWindow::UpdateUserForWin(int position)
{
    this->user->setGamesPlayed(this->user->getGamesPlayed() + 1);
    this->user->setWinStreak(this->user->getWinStreak() + 1);
    if (this->user->getWinStreak() > this->user->getMaxWinStreak())
    {
        this->user->setMaxWinStreak(this->user->getWinStreak());
    }
    this->user->setOneGuessAmount(position, 1);
    double value = (float)this->user->getTotalGuesses() / this->user->getGamesPlayed();
    this->user->setWinPercentage(round(value * 100));

}

void WordleGameWindow::UpdateUserForloss()
{
    this->user->setGamesPlayed(this->user->getGamesPlayed() + 1);
    double value = (float)this->user->getTotalGuesses() / this->user->getGamesPlayed();
    this->user->setWinPercentage(round(value * 100);
    this->user->setWinStreak(0);
}

void WordleGameWindow::changeButtonColor(Fl_Color color, const char* letter)
{
    for (int i = 0; i < this->buttons->size(); i++ )
    {
        Fl_Button* button = this->buttons->at(i);
        const char* buttonLetter = button->label();
        if (buttonLetter == letter)
        {
            button->color(color);
        }
    }
}

void WordleGameWindow::GetWindow(WordleGameWindow* cwindow)
{
    window = cwindow;
}

int WordleGameWindow::keyhandler(int event)
{
    int result = 0;
    //WordleGameWindow window = WordleGameWindow(500, 600, "wordle");

    if (event == FL_KEYUP)
    {
        cout << "hi" << endl;
    }
    else if (event == FL_SHORTCUT)
    {

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

/**
*The callback for clicking the repeating letter button.
*
*@param widget the the callback is being called on
*@param data the window of the widget
*/
void WordleGameWindow::repeatButtonClicked(Fl_Widget* widget, void* data)
{
    WordleGameWindow* window = (WordleGameWindow*)data;
    Fl_Button *button = (Fl_Button*) widget;
    if (window->repeating)
    {
        window->repeating = false;
        vector<string> list = window->reader.readInText(false);
        button->label("Repeat off");
        button->redraw();
        window->words.setWords(list);
        window->words.setRandomWord();
        window->resetBoard();

#ifdef Level_1
        cout << window->words.getWord() << endl;
#endif
    }
    else
    {
        window->repeating = true;
        button->label("Repeat on");
        vector<string> list = window->reader.readInText(true);
        window->words.setWords(list);
        window->words.setRandomWord();
        window->resetBoard();

#ifdef Level_1
        cout << window->words.getWord() << endl;
#endif
    }
}


void WordleGameWindow::resetBoard()
{
    this->currentBox = 0;
    for (int i = 0; i < this->values->size(); i++ )
    {
        this->values->at(i)->label(nullptr);
        this->values->at(i)->color(FL_WHITE);
    }
    for (int i = 0; i < this->buttons->size(); i++)
    {
        this->buttons->at(i)->color(FL_GRAY);
    }
    this->redraw();
}

/**
*The callback for clicking a keyboard button.
*
*@param widget the the callback is being called on
*@param data the window of the widget
*/
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


/**
*The callback for pressing a keyboard press
*
*@param widget the the callback is being called on
*@param data the window of the widget
*/
void WordleGameWindow::keyboardPressed(Fl_Widget* widget, void* data)
{
    WordleGameWindow* window = (WordleGameWindow*)data;
    //cout << "y" << endl;
    window->SetBoxValue("y");
}

/**
*The callback for clicking the enter button.
*
*@param widget the the callback is being called on
*@param data the window of the widget
*/
void WordleGameWindow::EnterButtonClicked(Fl_Widget* widget, void* data)
{
    WordleGameWindow* window = (WordleGameWindow*)data;
    if (window->isValidWord())
    {
        window->validateGuess(0);
        window->validateGuess(5);
        window->validateGuess(10);
        window->validateGuess(15);
        window->validateGuess(20);
        window->validateGuess(25);
        window->words.setGuessCount(window->words.getGuessCount() + 1);
    }

}


/**
*The callback for clicking the Backspace button.
*
*@param widget the the callback is being called on
*@param data the window of the widget
*/
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
    window->values->at(window->currentBox)->label(nullptr);
}

/**
*Sets the current box value to the associated value
*
*@param value the value to set the box too
*
*/
void WordleGameWindow::SetBoxValue(const char* value)
{
    Fl_Box* box = values->at(this->currentBox);
    box->label(value);
    /*this->validateGuess(0);
    */

}

}
