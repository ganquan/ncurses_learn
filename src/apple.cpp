#pragma once

#include "drawable.cpp"

class Apple : public Drawable {
 public:
    Apple(int y, int x) {
        this->y = y;
        this->x = x;

        this->icon = DEFAULT_APPLE; 
    }
};