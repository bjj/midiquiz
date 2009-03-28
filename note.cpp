#include "note.h"

Note Note::random(int octaves)
{
    char n = qrand() % ('G' - 'A' + 1) + 'A';
    int o = qrand() % octaves + (4 - octaves / 2);
    return Note(n, o);
}
