#include <ncurses.h>

using namespace std;

int main(int argc, char** argv) {

    initscr();

    printw("hello ncurses!");

    refresh();

    getch();

    endwin();

    return 0;
}