#pragma once
#include <ncurses.h>
#include <stdlib.h>
#include "drawable.cpp"

#define BOARD_DIM  20
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS BOARD_DIM * 2.5

class Board {
 public:
    Board() { _board(BOARD_ROWS, BOARD_COLS); }

    Board(int height, int width) {
      _board(height, width);
    }

    void initialize() {
        clear();
        refresh();
    }

    void addBorder() { box(board_win, 0, 0); }

    void add(Drawable drawable) {
        addAt(drawable.getY(), 
        drawable.getX(),
        drawable.getIcon());
    }

    void addAt(int y, int x, chtype ch) { mvwaddch(board_win, y, x, ch); }

    void getEmptyCoordinates(int &y, int &x) {
        while (mvwinch(board_win, y = rand() % board_height, x = rand() % board_width) != ' ');
    }
    
    chtype getInput() { return wgetch(board_win); }

    void clear() {
        wclear(board_win);
        addBorder();
    }

    void refresh() { wrefresh(board_win); }

 private:
    void _board(int height, int width) {
        this->board_width = width;
        this->board_height = height;

        int scr_w, scr_h;
        getmaxyx(stdscr, scr_h, scr_w);

        int board_x = (scr_w - this->board_width) / 2;
        int board_y = (scr_h - this->board_height) / 2;

        board_win =
            newwin(this->board_height, this->board_width, board_y, board_x);
    }

    WINDOW *board_win;
    int board_width;
    int board_height;
};