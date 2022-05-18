#include <ncurses.h>
#include <stdio.h>

#include <string>

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

    return 0;
}