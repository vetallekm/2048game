#ifndef TESTGAMEBOARD_HPP
#define TESTGAMEBOARD_HPP

class TestGameBoard {
public:
    TestGameBoard();

    void testInitialization();
    void testNewGame();
    void testMoveLeft();
    void testMoveRight();
    void testMoveUp();
    void testMoveDown();
    void testScore();
    void testWinCondition();
    void testGameOver();

    void runAllTests();
};

#endif 