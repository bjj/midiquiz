#include "mainwindow.h"

using Synthesia::MidiCommDescription;
using Synthesia::MidiCommDescriptionList;

void
MainWindow::midiMenuTriggered(QAction *action)
{
    std::wstring name = action->text().toStdWString();

    MidiCommDescriptionList midis = MidiCommIn::GetDeviceList();
    MidiCommDescriptionList::const_iterator it = midis.begin();
    for (; it != midis.end(); ++it) {
        if (it->name == name) {
            if (midiIn) {
                delete midiIn;
                midiIn = NULL;
            }
            midiIn = new MidiCommIn(it->id);
        }
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    midiIn = NULL;
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
    connect(midimenu, SIGNAL(triggered(QAction*)),
            this, SLOT(midiMenuTriggered(QAction*)));
 
    scoreArea = new ScoreArea;

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(scoreArea);
    QWidget *dummy = new QWidget;
    dummy->setLayout(layout);
    setCentralWidget(dummy);
}

MainWindow::~MainWindow()
{
    if (midiIn)
        delete midiIn;
}
