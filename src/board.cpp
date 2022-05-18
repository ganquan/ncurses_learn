#include <ncurses.h>

class Board {
 public:
  Board(int height, int width) {

    this->board_width = width;
    this->board_height = height;

    int scr_w, scr_h;
    getmaxyx(stdscr, scr_h, scr_w);

    int board_x = (scr_w - this->board_width) / 2;
    int board_y = (scr_h - this->board_height) / 2;

    board_win = newwin(this->board_height, this->board_width, board_y, board_x);
    
  }

  void initialize() {
      clear();
      refresh();
  }

  void addBorder() { box(board_win, 0, 0); }

  void addAt(int y, int x, chtype ch) { mvwaddch(board_win, y, x, ch); }

  void clear() {
    wclear(board_win);
    addBorder();
  }

  void refresh() { wrefresh(board_win); }

 private:
  WINDOW *board_win;
  int board_width;
  int board_height;
};