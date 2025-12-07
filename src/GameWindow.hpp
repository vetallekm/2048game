#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QMessageBox>
#include "GameBoard.hpp"

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow(QWidget* parent=nullptr);

protected:
    void keyPressEvent(QKeyEvent* event) override;

private slots:
    void updateDisplay();
    void newGame();
    void checkGameStatus();

private:
    GameBoard* game;
    QLabel* scoreLabel;
    QLabel* highScoreLabel;
    QLabel* cells[4][4];
    QPushButton* newGameButton;
    bool gameOver;

    void setupUI();
    QColor getTileColor(int value);
    QColor getTextColor(int value);
};

#endif 