#ifndef NOTE_H
#define NOTE_H

#include <QtGlobal>

class MidiNote ;

class Note
{
public:
    typedef enum { Left, Right, Either } Hand;
    typedef enum { None, Natural, Sharp, Flat } Pitch;

    Note() :m_note('X'), m_octave(0), m_pitch(None), m_hand(Either) { }
    Note(char n, int o) :m_note(n), m_octave(o), m_pitch(None), m_hand(Either) { }
    Note(char n, int o, Pitch p) :m_note(n), m_octave(o), m_pitch(p), m_hand(Either) { }
    Note(char n, int o, Pitch p, Hand h) :m_note(n), m_octave(o), m_pitch(p), m_hand(h) { }
    Note(const MidiNote& mn);

    int octave() const { return m_octave; }
    char note() const { return m_note; }
    Pitch pitch() const { return m_pitch; }

    int noteIndex() const { int i = note() - 'C'; if (i < 0) i += 7; return i; }
    float staffOffset() const { return 0.5 * ((octave() - 4) * 7 + noteIndex()); }
    Hand pickHand() const {
            if (m_hand != Either) return m_hand;
            else return m_octave >= 4 ? Right : Left;
        }
    bool valid() const { return m_note >= 'A' && m_note <= 'G'; }
    static Note random(int octaves = 7);
    Note canonical() const;
    Note equivalentPitch(Pitch p) const;

private:
    char m_note;
    int m_octave;
    Pitch m_pitch;
    Hand m_hand;
};

class MidiNote
{
public:
    enum { MiddleC = 60, MaxNote = 127, InvalidNote = 128 };

    MidiNote() :value(InvalidNote) { }
    MidiNote(int n) : value(n) { }

    int octave() const { return value / 12 - 1; }
    char note() const {
        static const int notes[] = { 'C', 'C', 'D', 'D', 'E', 'F', 'F', 'G', 'G', 'A', 'A', 'B' };
        return notes[value % 12];
    }
    Note::Pitch pitch() const {
        static const int sharps[] = { 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0 };
        return sharps[value % 12] ? Note::Sharp : Note::None;
    }

private:
    unsigned int value;
};

inline Note::Note(const MidiNote& mn) :m_note(mn.note()), m_octave(mn.octave()), m_pitch(mn.pitch()), m_hand(Either) { }

#endif // NOTE_H
