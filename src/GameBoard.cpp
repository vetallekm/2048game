#include "GameBoard.hpp"
#include <QRandomGenerator>

GameBoard::GameBoard(QObject* parent) : QObject(parent), score(0), highScore(0)
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = 0;
        }
    }
    newGame();
}

void GameBoard::newGame()
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = 0;
        }
    }

    score = 0;

    addNewNumber();
    addNewNumber();

    emit gameStateChanged();
}

int GameBoard::getCell(int row, int col) const
{
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE) {
        return board[row][col];
    }
    return 0;
}

int GameBoard::getScore() const
{
    return score;
}

int GameBoard::getHighScore() const
{
    return highScore;
}

bool GameBoard::isGameOver() const
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }

    return !canMove();
}

bool GameBoard::isWin() const
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 2048) {
                return true;
            }
        }
    }
    return false;
}

void GameBoard::addNewNumber()
{
    QVector<QPair<int, int>> emptyCells;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                emptyCells.append(qMakePair(i, j));
            }
        }
    }

    if (!emptyCells.isEmpty()) {
        int index = QRandomGenerator::global()->bounded(emptyCells.size());
        int row = emptyCells[index].first;
        int col = emptyCells[index].second;

        board[row][col] = (QRandomGenerator::global()->bounded(10) == 0) ? 4 : 2;
    }
}

bool GameBoard::canMove() const
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int current = board[i][j];

            if (j + 1 < SIZE && board[i][j + 1] == current) {
                return true;
            }

            if (i + 1 < SIZE && board[i + 1][j] == current) {
                return true;
            }
        }
    }

    return false;
}

void GameBoard::moveLeft()
{
    bool moved = false;

    for (int i = 0; i < SIZE; i++) {
        int newRow[SIZE] = { 0 };
        int pos = 0;

        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != 0) {
                if (newRow[pos] == 0) {
                    newRow[pos] = board[i][j];
                }
                else if (newRow[pos] == board[i][j]) {
                    newRow[pos] *= 2;
                    score += newRow[pos];
                    pos++;
                }
                else {
                    pos++;
                    newRow[pos] = board[i][j];
                }
            }
        }

        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != newRow[j]) {
                moved = true;
            }
            board[i][j] = newRow[j];
        }
    }

    if (moved) {
        addNewNumber();
        if (score > highScore) {
            highScore = score;
        }
        emit gameStateChanged();
    }
}

void GameBoard::moveRight()
{
    bool moved = false;

    for (int i = 0; i < SIZE; i++) {
        int newRow[SIZE] = { 0 };
        int pos = SIZE - 1;

        for (int j = SIZE - 1; j >= 0; j--) {
            if (board[i][j] != 0) {
                if (newRow[pos] == 0) {
                    newRow[pos] = board[i][j];
                }
                else if (newRow[pos] == board[i][j]) {
                    newRow[pos] *= 2;
                    score += newRow[pos];
                    pos--;
                }
                else {
                    pos--;
                    newRow[pos] = board[i][j];
                }
            }
        }

        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != newRow[j]) {
                moved = true;
            }
            board[i][j] = newRow[j];
        }
    }

    if (moved) {
        addNewNumber();
        if (score > highScore) {
            highScore = score;
        }
        emit gameStateChanged();
    }
}

void GameBoard::moveUp()
{
    bool moved = false;

    for (int j = 0; j < SIZE; j++) {
        int newCol[SIZE] = { 0 };
        int pos = 0;

        for (int i = 0; i < SIZE; i++) {
            if (board[i][j] != 0) {
                if (newCol[pos] == 0) {
                    newCol[pos] = board[i][j];
                }
                else if (newCol[pos] == board[i][j]) {
                    newCol[pos] *= 2;
                    score += newCol[pos];
                    pos++;
                }
                else {
                    pos++;
                    newCol[pos] = board[i][j];
                }
            }
        }

        for (int i = 0; i < SIZE; i++) {
            if (board[i][j] != newCol[i]) {
                moved = true;
            }
            board[i][j] = newCol[i];
        }
    }

    if (moved) {
        addNewNumber();
        if (score > highScore) {
            highScore = score;
        }
        emit gameStateChanged();
    }
}

void GameBoard::moveDown()
{
    bool moved = false;

    for (int j = 0; j < SIZE; j++) {
        int newCol[SIZE] = { 0 };
        int pos = SIZE - 1;

        for (int i = SIZE - 1; i >= 0; i--) {
            if (board[i][j] != 0) {
                if (newCol[pos] == 0) {
                    newCol[pos] = board[i][j];
                }
                else if (newCol[pos] == board[i][j]) {
                    newCol[pos] *= 2;
                    score += newCol[pos];
                    pos--;
                }
                else {
                    pos--;
                    newCol[pos] = board[i][j];
                }
            }
        }

        for (int i = 0; i < SIZE; i++) {
            if (board[i][j] != newCol[i]) {
                moved = true;
            }
            board[i][j] = newCol[i];
        }
    }

    if (moved) {
        addNewNumber();
        if (score > highScore) {
            highScore = score;
        }
        emit gameStateChanged();
    }
}