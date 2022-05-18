#pragma once

#include <time.h>
#include <stdlib.h>
#include "board.cpp"
#include "drawable.cpp"
#include "apple.cpp"
#include "empty.cpp"
#include "snake.cpp"


class Engine {
 public:
  Engine() {
      board = Board();

      pApple = nullptr;

      initialize();
  }
  
  ~Engine() {
    if (pApple != nullptr)
      delete pApple;
  }

  void initialize() {

      board.initialize();
      game_over = false;

      srand(time(NULL));
      

      snake.setDirection(right);

      SnakePiece next = SnakePiece(1, 1);
      board.add(next);
      snake.addPiece(next);
      
      next = snake.nextHead();
      board.add(next);
      snake.addPiece(next);

      next = snake.nextHead();
      board.add(next);
      snake.addPiece(next);

      snake.setDirection(right);

      next = snake.nextHead();
      board.add(next);
      snake.addPiece(next);
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
    
    if (pApple == nullptr) {
        int y, x;
        board.getEmptyCoordinates(y, x);
        pApple = new Apple(y, x);
        board.add(*pApple);
    }

    
    SnakePiece next = snake.nextHead();
    if (next.getX() != pApple->getX() && next.getY() != pApple->getY()) {
      int emptyRow = snake.tail().getY();
      int emptyCol = snake.tail().getX();
      board.add(Empty(emptyRow, emptyCol));
      snake.removePiece();
    }
    
    board.add(next);
    snake.addPiece(next);

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
  Snake snake;
};