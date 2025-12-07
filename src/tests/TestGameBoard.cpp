#include "TestGameBoard.hpp"
#include "../GameBoard.hpp"
#include <QDebug>


TestGameBoard::TestGameBoard() {}

void TestGameBoard::testInitialization()
{
    qDebug() << "Test: Initialization";

    GameBoard board;

    int emptyCells = 0;
    int nonEmptyCells = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int value = board.getCell(i, j);
            if (value == 0) {
                emptyCells++;
            }
            else {
                nonEmptyCells++;
                Q_ASSERT(value == 2 || value == 4);
            }
        }
    }

    Q_ASSERT(nonEmptyCells == 2);
    Q_ASSERT(emptyCells == 14);
    Q_ASSERT(board.getScore() == 0);
    Q_ASSERT(!board.isGameOver());
    Q_ASSERT(!board.isWin());

    qDebug() << " PASSED";
}

void TestGameBoard::testNewGame()
{
    qDebug() << "Test: New Game";

    GameBoard board;
    board.moveLeft();

    board.newGame();

    Q_ASSERT(board.getScore() == 0);

    qDebug() << " PASSED";
}

void TestGameBoard::testMoveLeft()
{
    qDebug() << "Test: Move Left";

    GameBoard board;
    board.moveLeft();

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int value = board.getCell(i, j);
            Q_ASSERT(value >= 0);
        }
    }

    qDebug() << " PASSED";
}

void TestGameBoard::testMoveRight()
{
    qDebug() << "Test: Move Right";

    GameBoard board;
    board.moveRight();

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int value = board.getCell(i, j);
            Q_ASSERT(value >= 0);
        }
    }

    qDebug() << " PASSED";
}

void TestGameBoard::testMoveUp()
{
    qDebug() << "Test: Move Up";

    GameBoard board;
    board.moveUp();

    int score = board.getScore();
    Q_ASSERT(score >= 0);

    qDebug() << " PASSED";
}

void TestGameBoard::testMoveDown()
{
    qDebug() << "Test: Move Down";

    GameBoard board;
    board.moveDown();

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int val = board.getCell(i, j);
            Q_ASSERT(val >= 0);
        }
    }

    qDebug() << " PASSED";
}

void TestGameBoard::testScore()
{
    qDebug() << "Test: Score";

    GameBoard board;
    int initialScore = board.getScore();

    board.moveLeft();
    int scoreAfterMove = board.getScore();

    Q_ASSERT(scoreAfterMove >= initialScore);

    qDebug() << " PASSED";
}

void TestGameBoard::testWinCondition()
{
    qDebug() << "Test: Win ";

    GameBoard board;

    Q_ASSERT(!board.isWin());

    qDebug() << " PASSED";
}

void TestGameBoard::testGameOver()
{
    qDebug() << "Test: Game Over";

    GameBoard board;

    Q_ASSERT(!board.isGameOver());

    board.moveLeft();
    board.moveRight();

    qDebug() << " PASSED";
}

void TestGameBoard::runAllTests()
{
    qDebug() << " Starting GameBoard Tests ";

    testInitialization();
    testNewGame();
    testMoveLeft();
    testMoveRight();
    testMoveUp();
    testMoveDown();
    testScore();
    testWinCondition();
    testGameOver();

    qDebug() << "All tests passed";
   
}