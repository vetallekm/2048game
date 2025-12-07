#include "TestGameBoard.hpp"
#include <QCoreApplication>
#include <QDebug>

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

    TestGameBoard test;
    test.runAllTests();

    qDebug() << "Tests completed. Exiting.";

    return 0;
}