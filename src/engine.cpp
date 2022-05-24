#pragma once

#include <stdlib.h>
#include <time.h>

#include "apple.cpp"
#include "board.cpp"
#include "drawable.cpp"
#include "empty.cpp"
#include "scoreboard.cpp"
#include "snake.cpp"

class Engine {
 public:
    Engine() {
        board = Board();
        scoreboard =
            ScoreBoard(BOARD_COLS, 
            board.getStartRow() + BOARD_ROWS,
             board.getStartCol());

        pApple = nullptr;

        initialize();
    }

    ~Engine() {
        if (pApple != nullptr)
            delete pApple;
    }

    void initialize() {
        board.initialize();

        score = 0;
        scoreboard.initialize(score);

        game_over = false;

        srand(time(NULL));

        snake.setDirection(right);

        handleNextPiece(SnakePiece(1, 1));
        handleNextPiece(snake.nextHead());
        handleNextPiece(snake.nextHead());
        snake.setDirection(right);
        handleNextPiece(snake.nextHead());

        if (pApple == nullptr) {
            createApple();
        }
    }

    void run() {
        while (!isOver()) {
            processInput();

            updateState();

            redraw();
        }
    }

    void createApple() {
        int y, x;
        board.getEmptyCoordinates(y, x);
        pApple = new Apple(y, x);
        board.add(*pApple);
    }

    void eatApple() {
        delete pApple;
        pApple = nullptr;

    }
    
    void increaseScore() {
        score++;
        scoreboard.updateScore(score);
    }
    
    void speedup() {
        auto speedup_step = 10;
        auto timeout = std::max(default_timeout - score * speedup_step, minimum_timeout);
        board.setTimeout(timeout);
    }

    void handleNextPiece(SnakePiece next) {
        if (pApple != nullptr) {
            switch (board.getCharAt(next.getY(), next.getX())) {
                case DEFAULT_APPLE:
                    eatApple();
                    increaseScore();
                    speedup();
                    break;

                case DEFAULT_EMPTY: {
                    int emptyRow = snake.tail().getY();
                    int emptyCol = snake.tail().getX();
                    board.add(Empty(emptyRow, emptyCol));
                    snake.removePiece();

                    break;
                }

                default:

                    game_over = true;
                    break;
            }
        }

        board.add(next);
        snake.addPiece(next);
    }

    void processInput() {
        chtype input = board.getInput();

        switch (input) {
            case KEY_UP:
            case 'w':
                snake.setDirection(up);
                break;
            case KEY_DOWN:
            case 's':
                snake.setDirection(down);
                break;
            case KEY_RIGHT:
            case 'd':
                snake.setDirection(right);
                break;
            case KEY_LEFT:
            case 'a':
                snake.setDirection(left);
                break;

            case 'p':
                board.setTimeout(-1); /* blocking, wait for key */
                while (board.getInput() != 'p')
                    ;

                board.setDefaultTimeout();
                break;

            default:
                break;
        }
    }

    void updateState() {
        SnakePiece next = snake.nextHead();
        handleNextPiece(next);

        if (pApple == nullptr) {
            createApple();
        }
    }

    void redraw() {
        board.refresh();
        scoreboard.refresh();
    }

    bool isOver() { return game_over; }

    int getScore() { return score; }

 private:
    ScoreBoard scoreboard;
    int score;

    Board board;
    Apple *pApple;
    bool game_over;
    Snake snake;
};