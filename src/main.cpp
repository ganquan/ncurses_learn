#include <ncurses.h>
#include <stdio.h>

#include <string>
#include <iostream>

#include "engine.cpp"

using namespace std;

int main() {
    initscr();
    refresh();
    noecho();
    
    curs_set(0);    /* turn off the cursor */

    Engine engine = Engine();
    engine.run();

    getch();
    endwin();

    cout << "You scored " << engine.getScore() << " Points!" << endl;
    return 0;
}