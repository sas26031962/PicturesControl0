#ifndef CDRAWFILES_H
#define CDRAWFILES_H

#include <QString>
#include <QDebug>
#include <QImage>
#include <QPainter>

class cDrawFiles
{
public:

    static QString execRotate(QString image_path, int angle);

    cDrawFiles();
};

#endif // CDRAWFILES_H
