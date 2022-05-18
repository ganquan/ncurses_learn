#pragma once

#include "drawable.cpp"

class Empty : public Drawable {
 public:
    Empty(int y, int x) {
        this->y = y;
        this->x = x;

        this->icon = DEFAULT_EMPTY;
    }
};