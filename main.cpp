#include <iostream>
#include <cstdlib>
#include <ncurses.h>

using namespace std;

const int boardWidth = 10;
const int boardHeight = 20;
bool gameOver = false;
int board[boardHeight][boardWidth] = {0};

struct Tetromino {
    int x, y;
    int shape[4][4];
};

Tetromino generateRandomTetromino() {
    Tetromino piece;
    piece.x = boardWidth / 2 - 1;
    piece.y = 0;
    static int tetrominoTypes[7][4][4] = {
            { {1, 1, 1, 1}, // I
                    {0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0} },
            { {1, 1, 1, 0}, // J
                    {1, 0, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0} },
            { {1, 1, 1, 0}, // L
                    {0, 0, 1, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0} },
            { {1, 1, 0, 0}, // O
                    {1, 1, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0} },
            { {0, 1, 1, 0}, // S
                    {1, 1, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0} },
            { {1, 1, 0, 0}, // T
                    {0, 1, 1, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0} },
            { {1, 1, 0, 0}, // Z
                    {0, 1, 1, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0} }
    };

    int type = rand() % 7;

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            piece.shape[i][j] = tetrominoTypes[type][i][j];

    return piece;
}

void drawBoard(){
    // TODO
}

