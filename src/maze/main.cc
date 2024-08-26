#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ps::MazeModel maze_model;
    ps::Controller controller(&maze_model);
    MainWindow w(&controller);
//    MainWindow w;
    w.show();
    return a.exec();
}
