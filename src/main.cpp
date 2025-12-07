#include <QApplication>
#include "GameWindow.hpp"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("2048 Game");
    GameWindow window;
    window.show();
    return app.exec();
}