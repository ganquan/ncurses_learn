#pragma once

#include <time.h>
#include <stdlib.h>
#include "board.cpp"
#include "drawable.cpp"
#include "apple.cpp"
#include "empty.cpp"


class Engine {
 public:
  Engine() {
      board = Board();
      board.initialize();
      
      game_over = false;
      pApple = nullptr;

      srand(time(NULL));
  }
  
  ~Engine() {
    if (pApple != nullptr)
      delete pApple;
  }
  
  void run(){

    while (!isOver()) {
      
      processInput();

      updateState();

      redraw();
      
    }

  }

  void processInput() {
    chtype input = board.getInput();
  }
  
  void updateState() {
    
    int y, x;
    board.getEmptyCoordinates(y, x);

    if (pApple != nullptr) {
        board.add(Empty(this->pApple->getY(), this->pApple->getX()));
    }
    pApple = new Apple(y, x);
    board.add(*pApple);
  }
  
  void redraw() {
    board.refresh();
  }

  bool isOver() {
    return game_over;
  }


 private:
  Board board;
  Apple *pApple;
  bool game_over;
};