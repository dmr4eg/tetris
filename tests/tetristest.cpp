#include <gtest/gtest.h> //to je knihovna, ktera umoznuje testovat
#include "/Users/dmr4eg/Folders/Codes/portfolio/tetris/tetrisgame/main.cpp" //to je main file, ve kterem se nachazi vsechny funkce hry, ktere chci testovat
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

#ifndef TESTING
#include <ncurses.h>
#endif



void simulateMoveLeft() {
    currentPiece.x--;
}

void simulateMoveRight() {
    currentPiece.x++;
}

void simulateMoveDown() {
    currentPiece.y++;
}

void simulateQuit() {
    gameOver = true;
}

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

void printGameBoard() {
    for (const auto &row : board) {
        for (int cell : row) {
            std::cout << (cell ? "X" : ".") << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Score: " << score << std::endl;
}

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