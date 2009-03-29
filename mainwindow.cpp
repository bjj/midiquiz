#include "mainwindow.h"
#include <QApplication>

using Synthesia::MidiCommDescription;
using Synthesia::MidiCommDescriptionList;
using Synthesia::MidiEvent;

void MainWindow::tempMidi()
{
    emit midiInputReady();
}

void MainWindow::midiInputUpdate()
{
    if (!midiIn)
        return;
    while (midiIn->KeepReading()) {
        MidiEvent ev = midiIn->Read();
        if (ev.Type() == Synthesia::MidiEventType_NoteOn)
            scoreArea->showNote(Note(MidiNote(ev.NoteNumber())));
    }
}

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
            Synthesia::MidiCommCallback<MainWindow> *cb =
                    new Synthesia::MidiCommCallback<MainWindow> (this, &MainWindow::tempMidi);
            midiIn->SetReadyCallback(cb);
        }
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    connect(this, SIGNAL(midiInputReady()),
            this, SLOT(midiInputUpdate()));

    midiIn = NULL;
    MidiCommDescriptionList midis = MidiCommIn::GetDeviceList();
    QMenu *midimenu = menuBar()->addMenu("Midi In");
    connect(midimenu, SIGNAL(triggered(QAction*)),
            this, SLOT(midiMenuTriggered(QAction*)));
    MidiCommDescriptionList::const_iterator it = midis.begin();
    if (it != midis.end()) {
        QAction *first = NULL;
        QActionGroup *radio = new QActionGroup(this);
        radio->setExclusive(true);
        for (; it != midis.end(); ++it) {
            QAction *act = midimenu->addAction(QString::fromStdWString(it->name));
            radio->addAction(act);
            act->setCheckable(true);
            if (first == NULL)
                first = act;
        }
        first->trigger();
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
    if (midiIn)
        delete midiIn;
}
