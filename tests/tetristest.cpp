#include <gtest/gtest.h> // To je knihovna, ktera se pouziva pro testovani
#include "/Users/dmr4eg/Folders/Codes/portfolio/tetris/tetrisgame/main.cpp" // To je main file, ve kterem se nachazi vsechny funkce hry, ktere chci testovat
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

#ifndef TESTING
#include <ncurses.h>
#endif


// Funkce pro simulaci pohybu doleva
void simulateMoveLeft() {
    currentPiece.x--;  // Simulace, kdyz uzivatel zmackne klavesu 'a'
}

// Funkce pro simulaci pohybu doprava
void simulateMoveRight() {
    currentPiece.x++;  // Simulace, kdyz uzivatel zmackne klavesu 'd'
}

// Funkce pro simulaci pohybu dolu
void simulateMoveDown() {
    currentPiece.y++;  // Simulace, kdyz uzivatel zmackne klavesu 's'
}

// Funkce pro simulaci ukonceni hry
void simulateQuit() {
    gameOver = true;  // Simulace, kdyz uzivatel zmackne klavesu 'q'
}

// Funkce pro simulaci behu hry
void simulateGameLoop() {
    for (int i = 0; i < 100; ++i) {
        std::cout << "i" << endl;
        if (gameOver) {
            break;
        }
        if (isValidMove(currentPiece, 0, 1)) {
            simulateMoveDown();
        } else {
            simulateQuit();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

// Funkce pro vytisknuti herniho pole
void printGameBoard() {
    for (const auto &row : board) {
        for (int cell : row) {
            std::cout << (cell ? "X" : ".") << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Score: " << score << std::endl;
}

// Funkce pro resetovani herniho stavu
void resetGameState() {
    gameOver = false;
    score = 0;
    currentPiece = Block(0, 0, Block::generateBlockForm(0));
    board = vector<vector<int>>(boardHeight, vector<int>(boardWidth, 0));
}

#ifndef TESTING
TEST(TetrisGame, BasicGameplay) {
    resetGameState();

    ASSERT_TRUE(isValidMove(currentPiece, 0, 1));
    simulateMoveDown();
    printGameBoard();
    ASSERT_TRUE(score == 0);

    simulateMoveLeft();
    simulateMoveRight();
    printGameBoard();
    ASSERT_TRUE(isValidMove(currentPiece, 1, 0));
    simulateMoveDown();
    printGameBoard();
    ASSERT_TRUE(score == 0);
    std::cout << "222" << std::endl;


    simulateMoveLeft();
    printGameBoard();
    ASSERT_TRUE(isValidMove(currentPiece, -1, 0));
    simulateQuit();
    simulateGameLoop();

    std::cout << "Test completed" << std::endl;
}
#endif