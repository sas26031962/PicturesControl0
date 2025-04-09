#include "cdrawfiles.h"

cDrawFiles::cDrawFiles()
{

}

QString cDrawFiles::execRotate(QString image_path, int angle)
{
/*
    //--- Читаем значения из INI-файла
    QString qsGroupName = qslGroupsLocal.at(iCurrentIndexGlobal.load(std::memory_order_relaxed));

    cIniFile::settings.beginGroup(qsGroupName);

    QString qsPath = cIniFile::settings.value("path","").toString();
    QString qsName = cIniFile::settings.value("name","").toString();

    cIniFile::settings.endGroup();

    QString imagePath = qsPath + '/' + qsName;
    qDebug() << "OriginalPath:" << imagePath;

    int x = imagePath.indexOf('.');
    QString qsRootOfName, qsExtOfName;
    if(x > 0)
    {
        qsRootOfName = imagePath.mid(0,x);
        qsExtOfName = imagePath.mid(x + 1);
    }
    else
    {
        QString s = "Wrong image file name format";
        //---
        emit execShowExecStatus(s);
        //---
        return;
    }
    qDebug() << "RootOfName=" << qsRootOfName << " ExtOfName=" << qsExtOfName;

    cIniFile::rotatedImagePath = qsRootOfName + "_1" + "." + qsExtOfName;
    //---
*/
    QString rotatedImagePath  = "";

    int x = image_path.indexOf('.');
    QString qsRootOfName, qsExtOfName;
    if(x > 0)
    {
        qsRootOfName = image_path.mid(0,x);
        qsExtOfName = image_path.mid(x + 1);
    }
    else
    {
        qDebug() << "Wrong file format:" << image_path;

        return rotatedImagePath;
    }
    qDebug() << "RootOfName=" << qsRootOfName << " ExtOfName=" << qsExtOfName;

    rotatedImagePath = qsRootOfName + "_1" + "." + qsExtOfName;


    QImage originalImage(image_path);

    // Создаем новое изображение для хранения повернутого изображения
    QImage::Format format = originalImage.format();
    QSize size = originalImage.size();
    int iW = size.width();
    int iH = size.height();
    int iSize;
    if(iW > iH)iSize = iW; else iSize = iH;
    //QSize newSize = QSize(iH, iW);
    QSize newSize = QSize(iSize, iSize);

    //QImage rotatedImage(originalImage.size(), originalImage.format());
    QImage rotatedImage(newSize, format);
    //QImage rotatedImage(size, format);

    rotatedImage.fill(Qt::transparent); // Заполняем прозрачным, если нужно

    QPainter painter(&rotatedImage);
    painter.setRenderHint(QPainter::SmoothPixmapTransform); // Сглаживание для более качественного поворота

    // Центр поворота (по умолчанию центр изображения)
    QPoint center = originalImage.rect().center();

    // Создаем матрицу трансформации
    QTransform transform;
    transform.translate(center.x(), center.y());    // Перемещаем систему координат в центр изображения
    transform.rotate(angle);                        // Выполняем поворот
    transform.translate(-center.x(), -center.y());  // Возвращаем систему координат

    painter.setTransform(transform);
    painter.drawImage(0, 0, originalImage); // Рисуем исходное изображение на повернутом
    //painter.drawImage(0, 437, originalImage); // Рисуем исходное изображение на повернутом

    painter.end();

    rotatedImage.save(rotatedImagePath); // Сохраняем повернутое изображение

    qDebug() << "Image rotated successfully";

    return rotatedImagePath;

}//End of void cDrawFiles::execRotate(int Angle)
