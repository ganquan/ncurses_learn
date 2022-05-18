#include <ncurses.h>
#include <stdio.h>

#include <string>

#include "engine.cpp"

using namespace std;

int main() {
    initscr();
    refresh();
    noecho();

    Engine engine = Engine();
    engine.run();

    getch();
    endwin();

    return 0;
}