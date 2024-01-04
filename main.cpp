#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <ncurses.h>

using namespace std;

const int boardWidth = 10;
const int boardHeight = 20;
bool gameOver = false;
int score = 0;
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

void drawBoard(const Tetromino& piece) {
    clear();
    for (int i = 0; i < boardHeight; ++i) {
        for (int j = 0; j < boardWidth; ++j) {
            if (board[i][j] == 0)
                printw(". ");
            else
                printw("##");
        }
        printw("\n");
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (piece.shape[i][j] != 0) {
                int x = piece.x + j;
                int y = piece.y + i;

                if (y >= 0) {
                    mvprintw(y, x * 2, "##");
                }
            }
        }
    }

    refresh();
//    printw("Score: %d\n", score);
    printw("\n");
}

bool isValidMove(const Tetromino& piece, int xOffset, int yOffset) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (piece.shape[i][j] != 0) {
                int newX = piece.x + j + xOffset;
                int newY = piece.y + i + yOffset;
                if (newX < 0 || newX >= boardWidth || newY >= boardHeight)
                    return false;
                if (newY >= 0 && board[newY][newX] != 0)
                    return false;
            }
        }
    }
    return true;
}

void mergePiece(const Tetromino& piece) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (piece.shape[i][j] != 0) {
                int x = piece.x + j;
                int y = piece.y + i;
                board[y][x] = 1;
            }
        }
    }
}

void clearLines() {
    for (int i = boardHeight - 1; i >= 0; --i) {
        bool lineFull = true;
        for (int j = 0; j < boardWidth; ++j) {
            if (board[i][j] == 0) {
                lineFull = false;
                break;
            }
        }
        if (lineFull) {
            for (int k = i; k > 0; --k) {
                for (int j = 0; j < boardWidth; ++j) {
                    board[k][j] = board[k - 1][j];
                }
            }
            for (int j = 0; j < boardWidth; ++j) {
                board[0][j] = 0;
            }
            score += 10;
            --i;
        }
    }
}

int main() {
    srand(time(0));
    initscr();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    Tetromino currentPiece = generateRandomTetromino();
    Tetromino nextPiece = generateRandomTetromino();
    while (!gameOver) {
        drawBoard(currentPiece);
        if (isValidMove(currentPiece, 0, 1)) {
            currentPiece.y++;
        } else {
            mergePiece(currentPiece);
            clearLines();
            currentPiece = nextPiece;
            nextPiece = generateRandomTetromino();
            if (!isValidMove(currentPiece, 0, 0)) {
                gameOver = true;
            }
        }
        int key = getch();
        if (key != ERR) {
            switch (key) {
                case 'a':
                    if (isValidMove(currentPiece, -1, 0))
                        currentPiece.x--;
                    break;
                case 'd':
                    if (isValidMove(currentPiece, 1, 0))
                        currentPiece.x++;
                    break;
                case 's':
                    if (isValidMove(currentPiece, 0, 1))
                        currentPiece.y++;
                    break;
                case 'q':
                    gameOver = true;
                    break;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    endwin();
    cout << "Game Over! Your score: " << score << endl;
    return 0;
}
