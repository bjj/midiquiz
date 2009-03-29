#include "note.h"

Note Note::random(int octaves)
{
    char n = qrand() % ('G' - 'A' + 1) + 'A';
    int o = qrand() % octaves + (4 - octaves / 2);
    int p = qrand() % 3;
    Pitch pitches[] = { None, Sharp, Flat };
    return Note(n, o, pitches[p]).canonical();
}

Note Note::canonical() const
{
    Note can = *this;
    if (m_pitch == Sharp && (m_note == 'B' || m_note == 'E')) {
        can.m_note++;
        can.m_pitch = None;
    } else if (m_pitch == Flat && (m_note == 'C' || m_note == 'F')) {
        if (m_note == 'C')
            can.m_octave--;
        can.m_note--;
        can.m_pitch = None;
    }
    return can;
}

Note Note::equivalentPitch(Pitch p) const
{
    Note equiv = *this;
    if (p == Sharp && m_pitch == Flat) {
        if (--equiv.m_note < 'A')
            equiv.m_note = 'G';
        equiv.m_pitch = p;
    } else if (p == Flat && m_pitch == Sharp) {
        if (++equiv.m_note > 'G')
            equiv.m_note = 'A';
        equiv.m_pitch = p;
    }
    return equiv;
}
