#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QtGui/QHBoxLayout>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include "scorearea.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    ScoreArea *scoreArea;
};

#endif // MAINWINDOW_H
