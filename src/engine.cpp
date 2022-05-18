#include "board.cpp"
#include "drawable.cpp"

class Engine {
 public:
  Engine() {
      board = Board();
      board.initialize();
      
      game_over = false;
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
    board.add(Drawable(3, 3, '#'));

    board.add(Drawable(3, 7, '@'));
  }
  
  void redraw() {
    board.refresh();
  }

  bool isOver() {
    return game_over;
  }


 private:
  Board board;
  bool game_over;
};