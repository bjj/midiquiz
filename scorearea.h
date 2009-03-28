#ifndef SCOREAREA_H
#define SCOREAREA_H

#include <QBrush>
#include <QPen>
#include <QWidget>
#include <QPainter>
#include <QMatrix>
#include "note.h"

class ScoreArea : public QWidget
{
public:
    ScoreArea();
    QSize minimumSizeHint() const;
    QSize sizeHint() const;

protected:
    Note blackNote;

    enum {
        staffWeight = 2,
        staffSpacing = 10,
        staffGap = 3
    };

    QPainterPath trebleClefPath,
        bassClefPath,
        quarterNotePath,
        ledgerLinePath;

    const QPainterPath& trebleClef();
    const QPainterPath& bassClef();
    const QPainterPath& quarterNote();
    const QPainterPath& ledgerLine();

    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);

};

#endif // SCOREAREA_H
