#include "GameWindow.hpp"
#include <QTimer>

GameWindow::GameWindow(QWidget* parent)
    : QMainWindow(parent), gameOver(false)
{
    game = new GameBoard(this);
    setupUI();
    updateDisplay();

    connect(game, &GameBoard::gameStateChanged, this, &GameWindow::updateDisplay);
    connect(game, &GameBoard::gameStateChanged, this, &GameWindow::checkGameStatus);
}

void GameWindow::setupUI()
{
    QWidget* central = new QWidget(this);
    setCentralWidget(central);

    central->setFocusPolicy(Qt::StrongFocus);
    central->setFocus();

    QVBoxLayout* mainLayout = new QVBoxLayout(central);

    QHBoxLayout* scoreLayout = new QHBoxLayout();

    scoreLabel = new QLabel("Score: 0");
    scoreLabel->setStyleSheet("font-weight: bold; font-size: 16px;");

    highScoreLabel = new QLabel("Best: 0");
    highScoreLabel->setStyleSheet("font-weight: bold; font-size: 16px; color: #ff6b6b;");

    scoreLayout->addWidget(scoreLabel);
    scoreLayout->addStretch();
    scoreLayout->addWidget(highScoreLabel);

    newGameButton = new QPushButton("New Game");
    newGameButton->setStyleSheet(
        "QPushButton {"
        "background-color: #8f7a66;"
        "color: white;"
        "font-weight: bold;"
        "padding: 8px 16px;"
        "border-radius: 4px;"
        "}"
        "QPushButton:hover {"
        "background-color: #9f8a76;"
        "}"
    );
    connect(newGameButton, &QPushButton::clicked, this, &GameWindow::newGame);

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();
    buttonLayout->addWidget(newGameButton);

    QGridLayout* gridLayout = new QGridLayout();
    gridLayout->setSpacing(10);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cells[i][j] = new QLabel();
            cells[i][j]->setAlignment(Qt::AlignCenter);
            cells[i][j]->setMinimumSize(70, 70);
            cells[i][j]->setStyleSheet(
                "QLabel {"
                "background-color: #cdc1b4;"
                "border-radius: 5px;"
                "font-weight: bold;"
                "font-size: 24px;"
                "}"
            );
            gridLayout->addWidget(cells[i][j], i, j);
        }
    }

    mainLayout->addLayout(scoreLayout);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addLayout(gridLayout);
    mainLayout->addStretch();

    setWindowTitle("2048");
    setFixedSize(350, 450);
    setStyleSheet("background-color: #b8a066;");
}

void GameWindow::keyPressEvent(QKeyEvent* event)
{
    if (gameOver) {
        QMessageBox::information(this, "Game Over",
            "Game is over!\nClick 'New Game' to play again.");
        return;
    }

    switch (event->key()) {
    case Qt::Key_Left:
        game->moveLeft();
        break;
    case Qt::Key_Right:
        game->moveRight();
        break;
    case Qt::Key_Up:
        game->moveUp();
        break;
    case Qt::Key_Down:
        game->moveDown();
        break;
    default:
        QMainWindow::keyPressEvent(event);
    }
}

void GameWindow::updateDisplay()
{
    scoreLabel->setText("Score: " + QString::number(game->getScore()));
    highScoreLabel->setText("Best: " + QString::number(game->getHighScore()));

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int value = game->getCell(i, j);
            QLabel* cell = cells[i][j];

            if (value == 0) {
                cell->setText("");
                cell->setStyleSheet(
                    "QLabel {"
                    "background-color: #cdc1b4;"
                    "border-radius: 5px;"
                    "font-weight: bold;"
                    "font-size: 24px;"
                    "}"
                );
            }
            else {
                cell->setText(QString::number(value));
                QColor bgColor = getTileColor(value);
                QColor textColor = getTextColor(value);

                QString style = QString(
                    "QLabel {"
                    "background-color: %1;"
                    "color: %2;"
                    "border-radius: 5px;"
                    "font-weight: bold;"
                    "font-size: %3px;"
                    "}"
                ).arg(bgColor.name())
                    .arg(textColor.name())
                    .arg(value < 100 ? 24 : (value < 1000 ? 20 : 16));

                cell->setStyleSheet(style);
            }
        }
    }
}

void GameWindow::newGame()
{
    gameOver = false;
    setWindowTitle("2048");
    setStyleSheet("background-color: ##include "GameWindow.hpp"
#include <QTimer>

GameWindow::GameWindow(QWidget* parent)
    : QMainWindow(parent), gameOver(false)
{
    game = new GameBoard(this);
    setupUI();
    updateDisplay();

    connect(game, &GameBoard::gameStateChanged, this, &GameWindow::updateDisplay);
    connect(game, &GameBoard::gameStateChanged, this, &GameWindow::checkGameStatus);
}

void GameWindow::setupUI()
{
    QWidget* central = new QWidget(this);
    setCentralWidget(central);

    central->setFocusPolicy(Qt::StrongFocus);
    central->setFocus();

    QVBoxLayout* mainLayout = new QVBoxLayout(central);

    QHBoxLayout* scoreLayout = new QHBoxLayout();

    scoreLabel = new QLabel("Score: 0");
    scoreLabel->setStyleSheet("font-weight: bold; font-size: 16px;");

    highScoreLabel = new QLabel("Best: 0");
    highScoreLabel->setStyleSheet("font-weight: bold; font-size: 16px; color: #ff6b6b;");

    scoreLayout->addWidget(scoreLabel);
    scoreLayout->addStretch();
    scoreLayout->addWidget(highScoreLabel);

    newGameButton = new QPushButton("New Game");
    newGameButton->setStyleSheet(
        "QPushButton {"
        "background-color: #8f7a66;"
        "color: white;"
        "font-weight: bold;"
        "padding: 8px 16px;"
        "border-radius: 4px;"
        "}"
        "QPushButton:hover {"
        "background-color: #9f8a76;"
        "}"
    );
    connect(newGameButton, &QPushButton::clicked, this, &GameWindow::newGame);

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();
    buttonLayout->addWidget(newGameButton);

    QGridLayout* gridLayout = new QGridLayout();
    gridLayout->setSpacing(10);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cells[i][j] = new QLabel();
            cells[i][j]->setAlignment(Qt::AlignCenter);
            cells[i][j]->setMinimumSize(70, 70);
            cells[i][j]->setStyleSheet(
                "QLabel {"
                "background-color: #cdc1b4;"
                "border-radius: 5px;"
                "font-weight: bold;"
                "font-size: 24px;"
                "}"
            );
            gridLayout->addWidget(cells[i][j], i, j);
        }
    }

    mainLayout->addLayout(scoreLayout);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addLayout(gridLayout);
    mainLayout->addStretch();

    setWindowTitle("2048");
    setFixedSize(350, 450);
    setStyleSheet("background-color: #b8a066;");
}

void GameWindow::keyPressEvent(QKeyEvent* event)
{
    if (gameOver) {
        QMessageBox::information(this, "Game Over",
            "Game is over!\nClick 'New Game' to play again.");
        return;
    }

    switch (event->key()) {
    case Qt::Key_Left:
        game->moveLeft();
        break;
    case Qt::Key_Right:
        game->moveRight();
        break;
    case Qt::Key_Up:
        game->moveUp();
        break;
    case Qt::Key_Down:
        game->moveDown();
        break;
    default:
        QMainWindow::keyPressEvent(event);
    }
}

void GameWindow::updateDisplay()
{
    scoreLabel->setText("Score: " + QString::number(game->getScore()));
    highScoreLabel->setText("Best: " + QString::number(game->getHighScore()));

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int value = game->getCell(i, j);
            QLabel* cell = cells[i][j];

            if (value == 0) {
                cell->setText("");
                cell->setStyleSheet(
                    "QLabel {"
                    "background-color: #cdc1b4;"
                    "border-radius: 5px;"
                    "font-weight: bold;"
                    "font-size: 24px;"
                    "}"
                );
            }
            else {
                cell->setText(QString::number(value));
                QColor bgColor = getTileColor(value);
                QColor textColor = getTextColor(value);

                QString style = QString(
                    "QLabel {"
                    "background-color: %1;"
                    "color: %2;"
                    "border-radius: 5px;"
                    "font-weight: bold;"
                    "font-size: %3px;"
                    "}"
                ).arg(bgColor.name())
                    .arg(textColor.name())
                    .arg(value < 100 ? 24 : (value < 1000 ? 20 : 16));

                cell->setStyleSheet(style);
            }
        }
    }
}

void GameWindow::newGame()
{
    gameOver = false;
    setWindowTitle("2048");
    setStyleSheet("background-color: #b8a066;");
    game->newGame();
    updateDisplay();
}

void GameWindow::checkGameStatus()
{
    if (gameOver) return;

    if (game->isWin()) {
        gameOver = true;
     
        setWindowTitle("2048 - You Win! Score: " + QString::number(game->getScore()));

        setStyleSheet("background-color: #000000;");  
    }
    else if (game->isGameOver()) {
        gameOver = true;
     
        setWindowTitle("2048 - Game Over! Score: " + QString::number(game->getScore()));

     
        setStyleSheet("background-color: #000000;");
    }
}

QColor GameWindow::getTileColor(int value)
{
    switch (value) {
    case 2:    return QColor(238, 228, 218);
    case 4:    return QColor(237, 224, 200);
    case 8:    return QColor(242, 177, 121);
    case 16:   return QColor(245, 149, 99);
    case 32:   return QColor(246, 124, 95);
    case 64:   return QColor(246, 94, 59);
    case 128:  return QColor(237, 207, 114);
    case 256:  return QColor(237, 204, 97);
    case 512:  return QColor(237, 200, 80);
    case 1024: return QColor(237, 197, 63);
    case 2048: return QColor(237, 194, 46);
    default:   return QColor(60, 58, 50);
    }
}

QColor GameWindow::getTextColor(int value)
{
    return (value <= 4) ? QColor(119, 110, 101) : QColor(249, 246, 242);
}
;");
    game->newGame();
    updateDisplay();
}

void GameWindow::checkGameStatus()
{
    if (gameOver) return;

    if (game->isWin()) {
        gameOver = true;
     
        setWindowTitle("2048 - You Win! Score: " + QString::number(game->getScore()));

        setStyleSheet("background-color: #000000;");  
    }
    else if (game->isGameOver()) {
        gameOver = true;
     
        setWindowTitle("2048 - Game Over! Score: " + QString::number(game->getScore()));

     
        setStyleSheet("background-color: #000000;");
    }
}

QColor GameWindow::getTileColor(int value)
{
    switch (value) {
    case 2:    return QColor(238, 228, 218);
    case 4:    return QColor(237, 224, 200);
    case 8:    return QColor(242, 177, 121);
    case 16:   return QColor(245, 149, 99);
    case 32:   return QColor(246, 124, 95);
    case 64:   return QColor(246, 94, 59);
    case 128:  return QColor(237, 207, 114);
    case 256:  return QColor(237, 204, 97);
    case 512:  return QColor(237, 200, 80);
    case 1024: return QColor(237, 197, 63);
    case 2048: return QColor(237, 194, 46);
    default:   return QColor(60, 58, 50);
    }
}

QColor GameWindow::getTextColor(int value)
{
    return (value <= 4) ? QColor(119, 110, 101) : QColor(249, 246, 242);
}
