#ifndef CDRAWFILES_H
#define CDRAWFILES_H

#include <QString>
#include <QDebug>
#include <QImage>
#include <QPainter>

#include "cinifile.h"

#define VERTICAL_SHIFT_AFTER_ROtATION 880

class cDrawFiles
{
public:

    static QString execRotate(int angle);
    static void scaleImage(QString, int width, int height);

    cDrawFiles();
};

#endif // CDRAWFILES_H
