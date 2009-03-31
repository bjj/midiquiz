# -------------------------------------------------
# Project created by QtCreator 2009-03-24T21:18:12
# -------------------------------------------------
TARGET = MidiQuiz
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    scorearea.cpp \
    note.cpp \
    libmidi/SynthVolume.cpp \
    libmidi/MidiUtil.cpp \
    libmidi/MidiTrack.cpp \
    libmidi/MidiEvent.cpp \
    libmidi/MidiComm.cpp \
    libmidi/Midi.cpp
HEADERS += mainwindow.h \
    scorearea.h \
    note.h \
    libmidi/Note.h \
    libmidi/MidiUtil.h \
    libmidi/MidiTypes.h \
    libmidi/MidiTrack.h \
    libmidi/MidiEvent.h \
    libmidi/MidiComm.h \
    libmidi/Midi.h \
    libmidi/SynthVolume.h \
    libmidi/os.h
OTHER_FILES += libmidi/license.txt \
    .gitignore
win32 {
    CONFIG += embed_manifest_exe
    DEFINES += WIN32
    LIBS += -lwinmm
}
macx {
    LIBS += -framework CoreMidi
    LIBS += -framework CoreAudio
    LIBS += -framework AudioUnit
}
