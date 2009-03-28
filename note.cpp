#include "note.h"

Note Note::random(int octaves)
{
    int n1 = qrand() % (octaves * 12);
    int n2 = qrand() % (octaves * 12);
    int note = (n1 + n2) / 2; // slight gaussian
    return Note(note + MiddleC - (octaves / 2) * 12, Either);
}
