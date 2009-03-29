#ifndef SCOREAREA_H
#define SCOREAREA_H

#include <QBrush>
#include <QPen>
#include <QWidget>
#include <QPainter>
#include <QMatrix>
#include "note.h"

class StaffPaths
{
    QPainterPath trebleClefPath,
        bassClefPath,
        quarterNotePath,
        ledgerLinePath,
        sharpPath, naturalPath, flatPath;

public:
    const QPainterPath& trebleClef();
    const QPainterPath& bassClef();
    const QPainterPath& quarterNote();
    const QPainterPath& ledgerLine();
    const QPainterPath& sharp();
    const QPainterPath& natural();
    const QPainterPath& flat();
};

class ScoreArea : public QWidget
{
public:
    ScoreArea();
    QSize minimumSizeHint() const;
    QSize sizeHint() const;

    enum {
        staffWeight = 2,
        staffSpacing = 10,
        staffGap = 3
    };

protected:
    Note blackNote;

    void paintEvent(QPaintEvent *event);
    void paintLedgerLines(QPainter& painter, const Note& note);
    void keyPressEvent(QKeyEvent *event);

};

#endif // SCOREAREA_H
