#include <ncurses.h>
#include <stdio.h>
#include <string>

#include "board.cpp"


#define BOARD_DIM 20
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS BOARD_DIM * 2.5


using namespace  std;

int main() {
  initscr();
  refresh();
  
  Board board = Board(BOARD_ROWS, BOARD_COLS);

  getch();
  endwin(); 
  
  return 0;
}