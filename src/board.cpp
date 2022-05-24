#pragma once
#include <ncurses.h>
#include <stdlib.h>
#include "drawable.cpp"

const int BOARD_DIM = 15;
const int BOARD_ROWS = BOARD_DIM;
const int BOARD_COLS  = int(BOARD_DIM * 2.5);

const int default_timeout = 200;
const int minimum_timeout = 50;

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

    chtype getInput() { return wgetch(board_win); }

    void getEmptyCoordinates(int &y, int &x) {
        while (mvwinch(board_win, y = rand() % board_height, x = rand() % board_width) != DEFAULT_EMPTY);
    }
    
    chtype getCharAt(int y, int x) {
        return mvwinch(board_win, y, x);
    }
    


    void clear() {
        wclear(board_win);
        addBorder();
    }

    void refresh() { wrefresh(board_win); }
    
    void setTimeout(int timeout) {
        wtimeout(board_win, timeout);
    }
    
    void setDefaultTimeout() {
        setTimeout(default_timeout);
    }
    
    int getStartRow() {
        return start_row;
    }
    
    int getStartCol() {
        return start_col;
    }

 private:
    void _board(int height, int width) {
        this->board_width = width;
        this->board_height = height;

        int scr_w, scr_h;
        getmaxyx(stdscr, scr_h, scr_w);

        start_col = (scr_w - this->board_width) / 2;
        start_row = (scr_h - this->board_height) / 2;

        board_win =
            newwin(this->board_height, this->board_width, start_row, start_col);
        
        

        setDefaultTimeout();
        keypad(board_win, true);
    }

    WINDOW *board_win;
    int board_width;
    int board_height;
    int start_row;
    int start_col;
};