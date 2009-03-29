#include "mainwindow.h"
#include "libmidi/MidiComm.h"
using Synthesia::MidiCommIn;
using Synthesia::MidiCommDescription;
using Synthesia::MidiCommDescriptionList;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    MidiCommDescriptionList midis = MidiCommIn::GetDeviceList();
    QMenu *midimenu = menuBar()->addMenu("Midi In");
    MidiCommDescriptionList::const_iterator it = midis.begin();
    if (it != midis.end()) {
        for (; it != midis.end(); ++it) {
            midimenu->addAction(QString::fromStdWString(it->name));
        }
    } else {
        midimenu->addAction("None Found")->setDisabled(true);
    }
 
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
