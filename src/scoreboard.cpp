
#pragma once
#include <ncurses.h>

class ScoreBoard {
    WINDOW *score_win;
    public:
        ScoreBoard() {
            
        }
        
        ScoreBoard(int width, int y, int x) {
            score_win = newwin(1, width, y, x);
        }
        
        void initialize(int init_score) {

            clear();
            mvwprintw(score_win, 0, 0, "Score:");
            updateScore(init_score);
            
            refresh();
        }

        void updateScore(int score) {
            mvwprintw(score_win, 0, score_win->_maxx - 10, "%11d", score);
        }

        void clear() {
            wclear(score_win);
        }
        
        void refresh() {
            wrefresh(score_win);
        }
    
};