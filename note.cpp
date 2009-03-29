#include "note.h"

Note Note::random(int octaves)
{
    char n = qrand() % ('G' - 'A' + 1) + 'A';
    int o = qrand() % octaves + (4 - octaves / 2);
    int p = qrand() % 3;
    Pitch pitches[] = { None, Sharp, Flat };
    return Note(n, o, pitches[p]).canonical();
}

Note Note::canonical()
{
    Note can = *this;
    if (m_pitch == Sharp && (m_note == 'B' || m_note == 'E')) {
        can.m_note++;
        can.m_pitch = None;
    } else if (m_pitch == Flat && (m_note == 'C' || m_note == 'F')) {
        can.m_note--;
        can.m_pitch = None;
    }
    return can;
}
