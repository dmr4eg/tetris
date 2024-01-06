#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <thread>
#include <chrono>
#include <ncurses.h>

using namespace std;

const int boardWidth = 10;
const int boardHeight = 20;
bool gameOver = false;
int score = 0;

// Trida Block, ktera reprezentuje jednotlive kostky
class Block {
public:
    int x, y;
    vector<vector<int>> shape;

    Block(int startX, int startY, const vector<vector<int>> &blockShape)
            : x(startX), y(startY), shape(blockShape) {}

    Block(const Block &other)
            : x(other.x), y(other.y), shape(other.shape) {}

    // Metoda, ktera vraci vektor vektoru, ktery reprezentuje kostku
    static vector<vector<int>> generateBlockForm(int blockType) {
        vector<vector<vector<int>>> blockForms = {
                {{1, 1, 1, 1},
                 {0, 0, 0, 0},
                 {0, 0, 0, 0},
                 {0, 0, 0, 0}},
                {{1, 1, 1, 0},
                 {1, 0, 0, 0},
                 {0, 0, 0, 0},
                 {0, 0, 0, 0}},
                {{1, 1, 1, 0},
                 {0, 0, 1, 0},
                 {0, 0, 0, 0},
                 {0, 0, 0, 0}},
                {{1, 1, 0, 0},
                 {1, 1, 0, 0},
                 {0, 0, 0, 0},
                 {0, 0, 0, 0}},
                {{0, 1, 1, 0},
                 {1, 1, 0, 0},
                 {0, 0, 0, 0},
                 {0, 0, 0, 0}},
                {{1, 1, 0, 0},
                 {0, 1, 1, 0},
                 {0, 0, 0, 0},
                 {0, 0, 0, 0}},
                {{1, 0, 0, 0},
                 {1, 0, 0, 0},
                 {1, 0, 0, 0},
                 {1, 0, 0, 0}}
        };
        return blockForms[blockType];
    }
};

// Vektor vektoru, ktery reprezentuje herni plochu
vector<vector<int>> board(boardHeight, vector<int>(boardWidth, 0));
// Promenna, ktera reprezentuje aktualni kostku
Block currentPiece(0, 0, vector<vector<int>>(4, vector<int>(4, 0)));

// Metoda, ktera generuje nahodny typ kostky
int generateRandomBlockType() {
    return rand() % 7;
}

// Metoda, ktera vykresluje herni plochu
void drawBoard(const Block &piece) {
    clear();
    // Vykresleni herni plochy.
    for (int i = 0; i < boardHeight; ++i) {
        for (int j = 0; j < boardWidth; ++j) {
            if (board[i][j] == 0)
                printw(". ");
            else
                printw("XX");
        }
        printw("\n");
    }
    // Vykresleni aktualni kostky
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (piece.shape[i][j] != 0) {
                int x = piece.x + j;
                int y = piece.y + i;

                if (y >= 0) {
                    mvprintw(y, x * 2, "XX");
                }
            }
        }
    }
    refresh();
    printw("Score: %d\n", score);
    printw("\n");
}

// Metoda, ktera zjistuje, zda je mozne kostku posunout na pozici x, y
bool isValidMove(const Block &piece, int xOffset, int yOffset) {
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

// Metoda, ktera maze plne radky
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

// Metoda, ktera nastavuje ncurses knihovnu do noblock modu
void setNoBlockMode() {
    timeout(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    halfdelay(1);
}

// Metoda, ktera vykresluje herni plochu
void drawLoop() {
    currentPiece = Block(boardWidth / 2 - 1, 0, Block::generateBlockForm(generateRandomBlockType()));
    Block nextPiece = Block(boardWidth / 2 - 1, 0, Block::generateBlockForm(generateRandomBlockType()));
    while (!gameOver) {
        drawBoard(currentPiece);
        if (isValidMove(currentPiece, 0, 1)) {
            currentPiece.y++;
        } else {
            // Zkopirovani kostky do herni plochy
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    if (currentPiece.shape[i][j] != 0) {
                        int x = currentPiece.x + j;
                        int y = currentPiece.y + i;
                        board[y][x] = 1;
                    }
                }
            }
            clearLines();
            currentPiece = nextPiece;
            nextPiece = Block(boardWidth / 2 - 1, 0, Block::generateBlockForm(generateRandomBlockType()));
            if (!isValidMove(currentPiece, 0, 0)) {
                gameOver = true;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1200));
    }
}

// Metoda, ktera zpracovava vstup od uzivatele
void inputLoop() {
    int key;
    while (!gameOver) {
        key = getch();
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
                    if (isValidMove(currentPiece, 0, 3))
                        currentPiece.y++;
                    break;
                case 'q':
                    gameOver = true;
                    break;
            }
        }
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

// Metoda, ktera zpracovava cas
void timeLoop() {
    int counter = 0;
    while (!gameOver) {
        this_thread::sleep_for(chrono::seconds(1));
        counter++;
    }
}

int main() {
    srand(time(0));
    initscr();
    setNoBlockMode();

    thread drawThread(drawLoop);
    thread inputThread(inputLoop);
    thread timeThread(timeLoop);

    drawThread.join();
    inputThread.join();
    timeThread.join();

    endwin();

    cout << "Game Over! Your score: " << score << endl;
    return 0;
}
