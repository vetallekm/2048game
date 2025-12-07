#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

#include <QObject>
#include <QVector>

class GameBoard : public QObject
{
    Q_OBJECT

public:
    explicit GameBoard(QObject* parent = nullptr);

    void newGame();
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

    int getCell(int row, int col) const;
    int getScore() const;
    int getHighScore() const;
    bool isGameOver() const;
    bool isWin() const;

signals:
    void gameStateChanged();

private:
    static const int SIZE = 4;
    int board[SIZE][SIZE];
    int score;
    int highScore;

    void addNewNumber();
    bool canMove() const;
};

#endif 