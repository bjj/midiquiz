#ifndef NOTE_H
#define NOTE_H

#include <QtGlobal>

class Note
{
public:
    // From MIDI
    enum { MiddleC = 60, MaxMidiNote = 127, Invalid = 128 };
    typedef enum { Left, Right, Either } Hand;
    typedef enum { Scale, Natural, Sharp, Flat } Pitch;

    Note() :value(Invalid), pitch(Scale), hand(Either) { }
    Note(int n) : value(n), hand(Either) { pitch = isSemitone() ? Sharp : Scale; }
    Note(int n, Hand h) : value(n), hand(h) { pitch = isSemitone() ? Sharp : Scale; }
    int octave() const { return value / 12 - 1; }
    int note() const { return value % 12; }
    int noteIdx() const {
        static const int indexes[] = { 0, 0, 1, 1, 2, 3, 3, 4, 4, 5, 5, 6 };
        return indexes[note()];
    }
    bool isSemitone() const {
        static const bool semis[] = { 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0 };
        return semis[note()];
    }
    float staffOffset() const { return 0.5 * ((octave() - 4) * 7 + noteIdx()); }
    Hand pickHand() const {
            if (hand != Either) return hand;
            else return value >= 60 ? Right : Left;
        }
    bool valid() const { return value != Invalid; }
    static Note random(int octaves = 7);

private:
    unsigned int value;
    Hand hand;
    Pitch pitch;
};

#endif // NOTE_H
