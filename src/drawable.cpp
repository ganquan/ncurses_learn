#pragma once
#include <ncurses.h>

const chtype DEFAULT_ICON = ' ';
const chtype DEFAULT_EMPTY = ' ';
const chtype DEFAULT_APPLE = '@';
const chtype DEFAULT_SNAKE = '#';
class Drawable {
 public:
    Drawable() {
        y = x = 0;
        icon = DEFAULT_ICON;
    }

    Drawable(int y, int x, chtype ch) {
        this->y = y;
        this->x = x;
        this->icon = ch;
    }

    int getX() { return x; }

    int getY() { return y; }

    chtype getIcon() { return icon; }

 protected:
    int y, x;
    chtype icon;
};