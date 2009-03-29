#include <QtGui/QApplication>
#include <QTime>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    MainWindow w;
    w.show();
    return a.exec();
}
