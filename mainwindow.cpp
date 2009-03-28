#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    scoreArea = new ScoreArea;

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(scoreArea);
    QWidget *dummy = new QWidget;
    dummy->setLayout(layout);
    setCentralWidget(dummy);
}

MainWindow::~MainWindow()
{
}
