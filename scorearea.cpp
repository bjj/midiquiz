#include "scorearea.h"
#include <math.h>

static StaffPaths paths;

// Create a QPainterPath representing a G Clef suitable for a staff
// with lines separated by 10 units.  0, 0 falls horizontally at the
// center and vertically on G.
//
// Converted from http://commons.wikimedia.org/wiki/File:Treble_clef.svg
// by carefully scaling/moving in Inkscape, exporting to PostScript and
// then replacing the 'eofill' with a 'pathforall' that outputs Qt
const QPainterPath& StaffPaths::trebleClef()
{
    QPainterPath& path = trebleClefPath;

    if (!path.isEmpty())
        return path;

    path.moveTo(-0.78, -5.32);
    path.cubicTo(-1.88, -5.02, -2.88, -4.33, -3.8, -3.29);
    path.cubicTo(-4.72, -2.22, -5.17, -1.05, -5.17, 0.21);
    path.cubicTo(-5.17, 1.01, -4.9, 1.91, -4.38, 2.86);
    path.cubicTo(-3.85, 3.84, -3.06, 4.54, -2.03, 4.99);
    path.cubicTo(-1.68, 5.06, -1.52, 5.24, -1.52, 5.5);
    path.cubicTo(-1.52, 5.59, -1.65, 5.68, -1.95, 5.75);
    path.cubicTo(-3.6, 5.33, -4.95, 4.45, -6.0, 3.13);
    path.cubicTo(-7.05, 1.8, -7.59, 0.29, -7.63, -1.45);
    path.cubicTo(-7.58, -3.3, -7.02, -5.03, -5.95, -6.62);
    path.cubicTo(-4.86, -8.23, -3.47, -9.36, -1.77, -10.03);
    path.lineTo(-3.02, -16.43);
    path.cubicTo(-5.8, -14.12, -8.06, -11.72, -9.82, -9.2);
    path.cubicTo(-11.57, -6.69, -12.47, -3.97, -12.55, -1.03);
    path.cubicTo(-12.51, 0.29, -12.24, 1.57, -11.73, 2.79);
    path.cubicTo(-11.23, 4.04, -10.47, 5.15, -9.46, 6.18);
    path.cubicTo(-7.41, 8.22, -4.76, 9.28, -1.52, 9.39);
    path.cubicTo(-0.42, 9.32, 0.76, 9.12, 2.02, 8.8);
    path.lineTo(-0.78, -5.32);
    path.closeSubpath();
    path.moveTo(0.52, -5.5);
    path.lineTo(3.34, 8.36);
    path.cubicTo(6.13, 7.25, 7.52, 4.81, 7.52, 1.1);
    path.cubicTo(7.36, -0.15, 6.99, -1.27, 6.38, -2.26);
    path.cubicTo(5.78, -3.27, 4.99, -4.06, 3.97, -4.64);
    path.cubicTo(2.96, -5.22, 1.82, -5.5, 0.52, -5.5);
    path.closeSubpath();
    path.moveTo(-3.18, -24.26);
    path.cubicTo(-2.59, -24.62, -1.9, -25.25, -1.16, -26.13);
    path.cubicTo(-0.42, -27.0, 0.31, -28.02, 0.99, -29.18);
    path.cubicTo(1.7, -30.35, 2.26, -31.54, 2.67, -32.75);
    path.cubicTo(3.09, -33.94, 3.29, -35.08, 3.29, -36.12);
    path.cubicTo(3.29, -36.57, 3.25, -37.02, 3.16, -37.42);
    path.cubicTo(3.09, -38.07, 2.89, -38.57, 2.55, -38.92);
    path.cubicTo(2.2, -39.24, 1.77, -39.42, 1.23, -39.42);
    path.cubicTo(0.14, -39.42, -0.83, -38.75, -1.7, -37.42);
    path.cubicTo(-2.37, -36.27, -2.93, -34.9, -3.33, -33.34);
    path.cubicTo(-3.74, -31.78, -3.98, -30.22, -4.01, -28.66);
    path.cubicTo(-3.92, -26.87, -3.64, -25.41, -3.18, -24.26);
    path.closeSubpath();
    path.moveTo(-4.32, -23.21);
    path.cubicTo(-5.13, -26.13, -5.59, -29.11, -5.68, -32.14);
    path.cubicTo(-5.66, -34.08, -5.46, -35.91, -5.08, -37.6);
    path.cubicTo(-4.72, -39.3, -4.2, -40.76, -3.51, -42.02);
    path.cubicTo(-2.84, -43.28, -2.06, -44.24, -1.19, -44.89);
    path.cubicTo(-0.42, -45.46, 0.14, -45.77, 0.45, -45.77);
    path.cubicTo(0.69, -45.77, 0.88, -45.68, 1.07, -45.52);
    path.cubicTo(1.25, -45.35, 1.48, -45.08, 1.77, -44.72);
    path.cubicTo(3.92, -41.68, 5.0, -38.0, 5.0, -33.71);
    path.cubicTo(5.0, -31.67, 4.73, -29.68, 4.19, -27.7);
    path.cubicTo(3.67, -25.73, 2.89, -23.86, 1.86, -22.11);
    path.cubicTo(0.81, -20.34, -0.42, -18.81, -1.85, -17.49);
    path.lineTo(-0.38, -10.39);
    path.cubicTo(0.41, -10.48, 0.96, -10.55, 1.26, -10.55);
    path.cubicTo(2.64, -10.55, 3.87, -10.26, 5.0, -9.69);
    path.cubicTo(6.14, -9.11, 7.12, -8.33, 7.92, -7.34);
    path.cubicTo(8.71, -6.37, 9.33, -5.25, 9.76, -3.99);
    path.cubicTo(10.18, -2.73, 10.41, -1.41, 10.41, -0.04);
    path.cubicTo(10.41, 2.09, 9.85, 4.04, 8.73, 5.79);
    path.cubicTo(7.61, 7.53, 5.93, 8.81, 3.67, 9.64);
    path.cubicTo(3.81, 10.53, 4.07, 11.81, 4.45, 13.45);
    path.cubicTo(4.81, 15.11, 5.08, 16.42, 5.26, 17.4);
    path.cubicTo(5.44, 18.37, 5.51, 19.31, 5.51, 20.23);
    path.cubicTo(5.51, 21.65, 5.17, 22.92, 4.48, 24.03);
    path.cubicTo(3.78, 25.15, 2.84, 26.02, 1.64, 26.63);
    path.cubicTo(0.47, 27.24, -0.83, 27.55, -2.24, 27.55);
    path.cubicTo(-4.23, 27.55, -5.97, 26.99, -7.45, 25.89);
    path.cubicTo(-8.93, 24.77, -9.73, 23.28, -9.8, 21.37);
    path.cubicTo(-9.74, 20.52, -9.54, 19.72, -9.18, 18.97);
    path.cubicTo(-8.82, 18.21, -8.33, 17.6, -7.7, 17.13);
    path.cubicTo(-7.09, 16.64, -6.35, 16.39, -5.5, 16.33);
    path.cubicTo(-4.79, 16.33, -4.12, 16.53, -3.49, 16.91);
    path.cubicTo(-2.88, 17.31, -2.37, 17.83, -1.99, 18.5);
    path.cubicTo(-1.63, 19.16, -1.43, 19.9, -1.43, 20.7);
    path.cubicTo(-1.43, 21.76, -1.79, 22.66, -2.51, 23.4);
    path.cubicTo(-3.24, 24.14, -4.16, 24.52, -5.26, 24.52);
    path.lineTo(-5.68, 24.52);
    path.cubicTo(-4.97, 25.6, -3.82, 26.16, -2.21, 26.16);
    path.cubicTo(-1.39, 26.16, -0.56, 25.98, 0.27, 25.66);
    path.cubicTo(1.12, 25.31, 1.82, 24.86, 2.42, 24.29);
    path.cubicTo(3.02, 23.71, 3.41, 23.1, 3.58, 22.45);
    path.cubicTo(3.89, 21.71, 4.03, 20.68, 4.03, 19.4);
    path.cubicTo(4.03, 18.53, 3.94, 17.67, 3.78, 16.8);
    path.cubicTo(3.61, 15.95, 3.36, 14.82, 3.02, 13.41);
    path.cubicTo(2.67, 12.02, 2.42, 10.94, 2.28, 10.2);
    path.cubicTo(1.19, 10.47, 0.07, 10.62, -1.1, 10.62);
    path.cubicTo(-3.07, 10.62, -4.94, 10.22, -6.69, 9.41);
    path.cubicTo(-8.44, 8.6, -9.98, 7.48, -11.32, 6.04);
    path.cubicTo(-12.64, 4.59, -13.67, 2.97, -14.41, 1.13);
    path.cubicTo(-15.13, -0.69, -15.51, -2.6, -15.53, -4.58);
    path.cubicTo(-15.46, -6.42, -15.11, -8.19, -14.46, -9.85);
    path.cubicTo(-13.81, -11.53, -12.98, -13.11, -11.95, -14.59);
    path.cubicTo(-10.92, -16.07, -9.85, -17.42, -8.75, -18.63);
    path.cubicTo(-7.63, -19.82, -6.17, -21.35, -4.32, -23.21);
    path.closeSubpath();

    return path;
}

// Create a QPainterPath representing an F Clef suitable for a staff
// with lines separated by 10 units.  0, 0 falls horizontally at the
// center and vertically on F.
//
// Converted from http://commons.wikimedia.org/wiki/File:Bass_clef.svg
// by carefully scaling/moving in Inkscape, exporting to PostScript and
// then replacing the 'eofill' with a 'pathforall' that outputs Qt
const QPainterPath& StaffPaths::bassClef()
{
    QPainterPath& path = bassClefPath;

    if (!path.isEmpty())
        return path;

    path.moveTo(-15.85, 24.54);
    path.cubicTo(-12.82, 22.5, -10.55, 20.95, -9.09, 19.88);
    path.cubicTo(-7.63, 18.83, -6.1, 17.51, -4.53, 15.94);
    path.cubicTo(-2.95, 14.37, -1.63, 12.59, -0.56, 10.62);
    path.cubicTo(0.29, 9.16, 1.02, 7.48, 1.61, 5.57);
    path.cubicTo(2.21, 3.67, 2.51, 1.83, 2.57, 0.09);
    path.cubicTo(2.57, -1.53, 2.36, -3.08, 1.92, -4.54);
    path.cubicTo(1.5, -6.01, 0.77, -7.22, -0.27, -8.19);
    path.cubicTo(-1.3, -9.15, -2.65, -9.63, -4.31, -9.63);
    path.cubicTo(-5.93, -9.63, -7.44, -9.3, -8.86, -8.67);
    path.cubicTo(-10.26, -8.02, -11.26, -6.98, -11.82, -5.53);
    path.cubicTo(-11.82, -5.4, -11.9, -5.22, -12.01, -4.98);
    path.cubicTo(-11.97, -4.67, -11.82, -4.44, -11.53, -4.27);
    path.cubicTo(-11.24, -4.1, -10.99, -4.02, -10.76, -4.02);
    path.cubicTo(-10.65, -4.02, -10.32, -4.08, -9.82, -4.19);
    path.cubicTo(-9.3, -4.31, -8.88, -4.38, -8.54, -4.38);
    path.cubicTo(-7.52, -4.38, -6.62, -4.02, -5.79, -3.31);
    path.cubicTo(-4.99, -2.6, -4.58, -1.74, -4.58, -0.73);
    path.cubicTo(-4.58, 0.0, -4.8, 0.69, -5.2, 1.32);
    path.cubicTo(-5.6, 1.95, -6.16, 2.47, -6.87, 2.83);
    path.cubicTo(-7.58, 3.21, -8.36, 3.38, -9.21, 3.38);
    path.cubicTo(-10.74, 3.38, -12.05, 2.93, -13.12, 1.99);
    path.cubicTo(-14.18, 1.03, -14.72, -0.17, -14.72, -1.68);
    path.cubicTo(-14.72, -3.62, -14.12, -5.28, -12.95, -6.7);
    path.cubicTo(-11.76, -8.11, -10.26, -9.17, -8.42, -9.87);
    path.cubicTo(-6.6, -10.6, -4.75, -10.95, -2.88, -10.95);
    path.cubicTo(-0.82, -10.95, 1.14, -10.43, 2.96, -9.38);
    path.cubicTo(4.8, -8.35, 6.24, -6.91, 7.31, -5.13);
    path.cubicTo(8.39, -3.33, 8.94, -1.42, 8.94, 0.65);
    path.cubicTo(8.94, 4.32, 7.72, 7.73, 5.26, 10.89);
    path.cubicTo(2.8, 14.04, -0.23, 16.78, -3.86, 19.11);
    path.cubicTo(-6.27, 20.7, -10.19, 22.84, -15.58, 25.54);
    path.lineTo(-15.85, 24.54);
    path.closeSubpath();
    path.moveTo(10.8, -5.06);
    path.cubicTo(10.8, -5.74, 11.05, -6.32, 11.56, -6.78);
    path.cubicTo(12.03, -7.25, 12.63, -7.48, 13.34, -7.48);
    path.cubicTo(13.95, -7.48, 14.53, -7.22, 15.05, -6.7);
    path.cubicTo(15.57, -6.2, 15.81, -5.61, 15.81, -4.96);
    path.cubicTo(15.81, -4.27, 15.55, -3.68, 15.05, -3.2);
    path.cubicTo(14.51, -2.74, 13.91, -2.51, 13.24, -2.51);
    path.cubicTo(12.53, -2.51, 11.96, -2.74, 11.5, -3.25);
    path.cubicTo(11.04, -3.75, 10.8, -4.35, 10.8, -5.06);
    path.closeSubpath();
    path.moveTo(10.8, 4.97);
    path.cubicTo(10.8, 4.28, 11.05, 3.69, 11.52, 3.23);
    path.cubicTo(12.0, 2.75, 12.59, 2.52, 13.34, 2.52);
    path.cubicTo(13.95, 2.52, 14.51, 2.77, 15.05, 3.29);
    path.cubicTo(15.55, 3.81, 15.81, 4.36, 15.81, 4.97);
    path.cubicTo(15.81, 5.72, 15.57, 6.31, 15.08, 6.79);
    path.cubicTo(14.59, 7.27, 14.01, 7.52, 13.34, 7.52);
    path.cubicTo(12.59, 7.52, 12.0, 7.27, 11.52, 6.81);
    path.cubicTo(11.05, 6.35, 10.8, 5.74, 10.8, 4.97);
    path.closeSubpath();

    return path;
}

const QPainterPath& StaffPaths::sharp()
{
    QPainterPath& path = sharpPath;

    if (!path.isEmpty())
        return path;

    path.moveTo(-3.22, -12.44);
path.lineTo(-3.22, -5.03);
path.lineTo(-4.98, -4.21);
path.lineTo(-4.98, -1.21);
path.lineTo(-3.22, -2.03);
path.lineTo(-3.22, 5.53);
path.lineTo(-4.98, 6.35);
path.lineTo(-4.98, 9.35);
path.lineTo(-3.22, 8.53);
path.lineTo(-3.22, 14.03);
path.lineTo(-1.63, 13.29);
path.lineTo(-1.63, 7.79);
path.lineTo(1.77, 6.2);
path.lineTo(1.77, 11.7);
path.lineTo(3.4, 10.94);
path.lineTo(3.4, 5.44);
path.lineTo(5.09, 4.66);
path.lineTo(5.09, 1.66);
path.lineTo(3.4, 2.44);
path.lineTo(3.4, -5.12);
path.lineTo(5.09, -5.91);
path.lineTo(5.09, -8.9);
path.lineTo(3.4, -8.12);
path.lineTo(3.4, -15.53);
path.lineTo(1.77, -14.77);
path.lineTo(1.77, -7.36);
path.lineTo(-1.63, -5.77);
path.lineTo(-1.63, -13.18);
path.lineTo(-3.22, -12.44);
path.closeSubpath();
path.moveTo(-1.63, -2.78);
path.lineTo(1.77, -4.36);
path.lineTo(1.77, 3.2);
path.lineTo(-1.63, 4.79);
path.lineTo(-1.63, -2.78);
path.closeSubpath();


    return path;
}

const QPainterPath& StaffPaths::natural()
{
    QPainterPath& path = naturalPath;

    if (!path.isEmpty())
        return path;

    path.moveTo(1.59, -8.49);
    path.cubicTo(1.59, -8.49, -1.43, -6.86, -1.43, -6.86);
    path.cubicTo(-1.43, -6.86, -1.43, -12.66, -1.43, -12.66);
    path.cubicTo(-1.43, -12.66, -2.89, -12.66, -2.89, -12.66);
    path.cubicTo(-2.89, -12.66, -2.89, -6.07, -2.89, -6.07);
    path.cubicTo(-2.89, -6.07, -2.89, -2.15, -2.89, -2.15);
    path.cubicTo(-2.89, -2.15, -2.89, 5.3, -2.89, 5.3);
    path.cubicTo(-2.89, 5.3, -2.89, 9.03, -2.89, 9.03);
    path.cubicTo(-2.89, 9.03, -1.43, 8.24, -1.43, 8.24);
    path.cubicTo(-1.43, 8.24, 1.59, 6.6, 1.59, 6.6);
    path.cubicTo(1.59, 6.6, 1.59, 12.53, 1.59, 12.53);
    path.cubicTo(1.59, 12.53, 3.05, 12.53, 3.05, 12.53);
    path.cubicTo(3.05, 12.53, 3.05, 5.81, 3.05, 5.81);
    path.cubicTo(3.05, 5.81, 3.05, 2.09, 3.05, 2.09);
    path.cubicTo(3.05, 2.09, 3.05, -5.37, 3.05, -5.37);
    path.cubicTo(3.05, -5.37, 3.05, -9.28, 3.05, -9.28);
    path.cubicTo(3.05, -9.28, 1.59, -8.49, 1.59, -8.49);
    path.closeSubpath();
    path.moveTo(1.59, -4.58);
    path.cubicTo(1.59, -4.58, 1.59, 2.88, 1.59, 2.88);
    path.cubicTo(1.59, 2.88, -1.43, 4.51, -1.43, 4.51);
    path.cubicTo(-1.43, 4.51, -1.43, -2.94, -1.43, -2.94);
    path.cubicTo(-1.43, -2.94, 1.59, -4.58, 1.59, -4.58);
    path.closeSubpath();

    return path;
}

const QPainterPath& StaffPaths::flat()
{
    QPainterPath& path = naturalPath;

    if (!path.isEmpty())
        return path;

path.moveTo(-2.47, -17.63);
path.lineTo(-2.26, 5.02);
path.lineTo(-0.97, 5.12);
path.cubicTo(-0.97, 5.12, 1.61, 3.8, 2.97, 2.23);
path.cubicTo(3.64, 1.46, 4.29, 0.57, 4.63, -0.42);
path.cubicTo(4.96, -1.41, 4.88, -3.2, 4.08, -4.25);
path.cubicTo(3.27, -5.31, 1.46, -5.03, -0.47, -4.61);
path.lineTo(-0.35, -17.63);
path.lineTo(-2.47, -17.63);
path.closeSubpath();
path.moveTo(-0.5, -3.22);
path.cubicTo(1.11, -3.49, 2.54, -3.48, 2.61, -2.05);
path.cubicTo(2.68, -0.62, 0.21, 2.32, -0.67, 3.14);
path.lineTo(-0.5, -3.22);
path.closeSubpath();




    return path;
}

// A quarter note suitable for a scale with lines spaced 10u apart
const QPainterPath& StaffPaths::quarterNote()
{
    QPainterPath& path = quarterNotePath;

    if (!path.isEmpty())
        return path;

    // Note head
    path.addEllipse(QPointF(0, 0), 4.5*3/2, 4.5);
    QMatrix twist;
    twist.rotate(-25);
    path = path * twist;

    // Stem (rotate initial position to ensure it lines up)
    QPointF stemRoot(7, 0);
    stemRoot = stemRoot * twist;
    QPainterPath stem;
    stem.addRect(stemRoot.rx(), stemRoot.ry(), -2, -33);
    path = path.united(stem);

    return path;
}

const QPainterPath& StaffPaths::ledgerLine()
{
    QPainterPath& path = ledgerLinePath;

    if (!path.isEmpty())
        return path;

    path.addRect(-10, -ScoreArea::staffWeight/2., 20, ScoreArea::staffWeight);
    return path;
}

ScoreArea::ScoreArea()
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFocusPolicy(Qt::ClickFocus);
}

QSize ScoreArea::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize ScoreArea::sizeHint() const
{
    return QSize(400, 200);
}

static int sign(int i)
{
    return (i == 0) ? 0 : (i < 0 ? -1 : 1);
}

void ScoreArea::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);
    painter.setPen(QPen(QColor(64,64,64), staffWeight, Qt::SolidLine));
    QBrush black(Qt::black, Qt::SolidPattern);

    bool antialiased = true;
    if (antialiased) {
        painter.setRenderHint(QPainter::Antialiasing, true);
        //painter.translate(+0.5, +0.5);
    }
    painter.translate(0, height() / 2);

    int offset;
    for (int y = 0; y < 5; ++y) {
        offset = staffSpacing * (y + staffGap);
        painter.drawLine(15, -offset, width()-15, -offset);
        painter.drawLine(15, offset, width()-15, offset);
    }
    painter.drawLine(15, -offset, 15, offset);
    painter.drawLine(width()-15, -offset, width()-15, offset);

    painter.save();
    painter.translate(38, -staffSpacing * (1 + staffGap));
    const QPainterPath& tpath = paths.trebleClef();
    painter.fillPath(tpath, black);
    painter.restore();

    painter.save();
    painter.translate(38, staffSpacing * (1 + staffGap));
    const QPainterPath& bpath = paths.bassClef();
    painter.fillPath(bpath, black);
    painter.restore();

    const Note& note = blackNote;
    if (note.valid()) {
        qreal y = note.staffOffset();
        Note::Hand h = note.pickHand();
        if (h == Note::Left)
            y = -y + (staffGap - 1);
        else
            y = -y - (staffGap - 1);

        painter.save();
        painter.translate(100, 0);

        painter.save();
        painter.translate(0, y * staffSpacing);

        painter.save();
        painter.translate(-14, 0);
        painter.fillPath(paths.sharp(), black);
        painter.restore();

        const QPainterPath& npath = paths.quarterNote();
        painter.fillPath(npath, black);
        painter.restore();

        int ledger, target, step;
        if (h == Note::Left) {
            target = staffGap;
            step = 1;
            ledger = ceil(y);
            if (y > target) {
                target = staffGap + 4;
                step = -1;
                ledger = floor(y);
            }
        } else {
            target = -staffGap;
            step = -1;
            ledger = floor(y);
            if (y < target) {
                target = -staffGap - 4;
                step = 1;
                ledger = ceil(y);
            }
        }
        painter.translate(0, ledger * staffSpacing);
        while (sign(target - ledger) == step) {
            const QPainterPath& lpath = paths.ledgerLine();
            painter.fillPath(lpath, black);
            painter.translate(0, step * staffSpacing);
            ledger += step;
        }
        painter.restore();
    }
}

void ScoreArea::keyPressEvent(QKeyEvent * /* event */)
{
    blackNote = Note::random(4);
    update();
}
