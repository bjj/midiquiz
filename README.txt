MidiQuiz is a simple note flashcard program for Windows and Mac OSX.
The initial version presents a note (which can be randomized by hitting
any key) and waits for the user to match it on a Midi input.  A pulldown
menu lets you select the Midi device you want to use.

BUILDING

MidiQuiz was developed with Qt 4.5 under Visual Studio Express 2008.
Qt is built with "-platform win32-msvc2008" (NB NOT win32-msvc which
is for VC++6.0).  It should be compatible with the Qt runtime
distribution on Nokia's site.  Steps:

	qmake
	nmake

It has been compiled and run under Mac OSX 10.5.6 with Qt 4.5 and
XCode 3.0.  The Midi component has not been tested.  Steps:

	qmake
	xcodebuild

The Qt component should be portable to any other supported Qt platform,
but libmidi would need to be ported.

AUTHORS

MidiQuiz was written by Ben Jackson <ben@ben.com>
with libmidi code from the last open release of
Synthesia by Nicholas Piegdon <nicholas@synthesiagame.com>

