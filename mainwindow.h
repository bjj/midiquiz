#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QtGui/QHBoxLayout>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include "scorearea.h"
#include "libmidi/MidiComm.h"
using Synthesia::MidiCommIn;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void midiMenuTriggered(QAction *action);
    void midiInputUpdate(void);

signals:
    void midiInputReady(void);

private:
    void tempMidi(void);

    ScoreArea *scoreArea;
    MidiCommIn *midiIn;
};

#endif // MAINWINDOW_H
