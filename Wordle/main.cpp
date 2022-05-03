#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

#include <stdio.h>
//#include <curses.h>
#include <iostream>
#include <unistd.h>
#include <termios.h>
using namespace std;

#include "WordleGameWindow.h"
#include "UserProfileWindow.h"
#include "WordleStartUpWindow.h"
using namespace View;

char getvalue() {
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");
        return (buf);
}

int main (int argc, char ** argv)
{
  Fl_Window *window;
  Fl_Box *box;

  WordleGameWindow mainWindow(500, 600, "Wordle by McGraw and Thompson");
  //mainWindow.show();

  WordleStartUpWindow startWindow(400, 300, "Main Menu");
  startWindow.show();

  window = new Fl_Window (300, 180);
  box = new Fl_Box (20, 40, 260, 100, "Hello World!");

  box->box (FL_UP_BOX);
  box->labelsize (36);
  box->labelfont (FL_BOLD+FL_ITALIC);
  box->labeltype (FL_SHADOW_LABEL);
  window->end ();
  //window->show (argc, argv);

  //char c = getvalue();
  //cout << "a" << c << "pressed" << endl;
  return(Fl::run());
}
