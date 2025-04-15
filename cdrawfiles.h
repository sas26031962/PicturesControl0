#ifndef CDRAWFILES_H
#define CDRAWFILES_H

#include <QString>
#include <QDebug>
#include <QImage>
#include <QPainter>

#include "cinifile.h"

#define VERTICAL_SHIFT_AFTER_ROTATION 880
#define INITIAL_SHIFT_X -200
#define INITIAL_SHIFT_Y -200

class cDrawFiles
{
public:
    static qreal dx;// = 0;
    static qreal dy;// = VERTICAL_SHIFT_AFTER_ROtATION;//880

    static QString execRotate(int angle);
    static void scaleImage(QString, int width, int height);

    cDrawFiles();
};

#endif // CDRAWFILES_H
