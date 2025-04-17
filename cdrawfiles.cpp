#include "cdrawfiles.h"


qreal cDrawFiles::dx = INITIAL_SHIFT_X;
qreal cDrawFiles::dy = INITIAL_SHIFT_Y;

cDrawFiles::cDrawFiles()
{

}

//
// Поворот изображения
//
QString cDrawFiles::execRotate(int angle)
{
    //--- Читаем значения из INI-файла
    cIniFile::getCurrentImagePath();

    int x = cIniFile::currentImagePath.indexOf('.');
    QString qsRootOfName, qsExtOfName;
    if(x > 0)
    {
        qsRootOfName = cIniFile::currentImagePath.mid(0,x);
        qsExtOfName = cIniFile::currentImagePath.mid(x + 1);
    }
    else
    {
        qDebug() << "Wrong file format:" << cIniFile::currentImagePath;

        return cIniFile::currentRotatedImagePath;
    }
    qDebug() << "RootOfName=" << qsRootOfName << " ExtOfName=" << qsExtOfName;

    cIniFile::currentRotatedImagePath = qsRootOfName + "_1" + "." + qsExtOfName;


    QImage originalImage(cIniFile::currentImagePath);

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

    //rotatedImage.fill(Qt::transparent); // Заполняем прозрачным (фактически - чёрный)
    rotatedImage.fill(Qt::blue); // Заполняем голубым
    //---
    QPainter painter(&rotatedImage);
    painter.setRenderHint(QPainter::SmoothPixmapTransform); // Сглаживание для более качественного поворота

    // Центр поворота (по умолчанию центр изображения)
    QPoint center = originalImage.rect().center();

    // Создаем матрицу трансформации
    QTransform transform;
    transform.translate(center.x(), center.y());    // Перемещаем систему координат в центр изображения
    transform.rotate(angle);                        // Выполняем поворот
    transform.translate(-center.x(), -center.y());  // Возвращаем систему координат

    //qreal dx = 0;
    //qreal dy = VERTICAL_SHIFT_AFTER_ROtATION;//880

    painter.setTransform(transform);
    painter.drawImage(cDrawFiles::dy, cDrawFiles::dx, originalImage); // Рисуем исходное изображение на повернутом

    painter.end();
    //---
    rotatedImage.save(cIniFile::currentRotatedImagePath); // Сохраняем повернутое изображение

    qDebug() << "Image rotated successfully";

    return cIniFile::currentRotatedImagePath;

}//End of void cDrawFiles::execRotate(int Angle)

//
// Масштабирование изображения
//
void cDrawFiles::scaleImage(QString path, int width, int height)
{
    //int newSize = 582;
    int newWidth = width;
    int newHeight = height;

    QImage originalImage(path);

    QString status;

    if (originalImage.isNull())
    {
        qDebug() << "Error: Could not load image: " << path;
        return;
    }

    int oldWidth = originalImage.width();
    int oldHeight = originalImage.height();

    QString info = "Original:";
    info += " width=";
    info += QString::number(oldWidth);
    info += " height=";
    info += QString::number(oldHeight);
    info += " Scaled:";
    info += " width=";
    info += QString::number(newWidth);
    info += " height=";
    info += QString::number(newHeight);

    qDebug() << info;

    // Масштабирование изображения
    QImage scaledImage = originalImage.scaled(
        newWidth,
        newHeight,
        Qt::KeepAspectRatio, // Сохранять пропорции
        Qt::SmoothTransformation // Использовать сглаживание
    );
//--- Трансформирование изображения ---
//    QImage::Format format = scaledImage.format();
//    QSize transformSize = QSize(newWidth, newHeight);
//    QImage transformedImage(transformSize, format);

//    transformedImage.fill(Qt::transparent); // Заполняем прозрачным, если нужно

//    QPainter painter(&transformedImage);
//    painter.setRenderHint(QPainter::SmoothPixmapTransform); // Сглаживание
//    // Создаем матрицу трансформации
//    qreal dx = 10;//(width - newSize)/2;
//    qreal dy = 10;

//    QTransform transform;
//    transform.translate(dx, dy);
//    painter.setTransform(transform);
//    painter.drawImage(0, 0, scaledImage); // Рисуем масштабированное изображение на трансформированном
//    painter.end();

//---

    QString scaledImagePath = cIniFile::scaledImagePath;
    status = "Image scaling to file";
    status += scaledImagePath;
    if(scaledImagePath.count() > 0)
    {
        scaledImage.save(scaledImagePath);    // Сохраняем масштабированное изображение
        //transformedImage.save(scaledImagePath); // Сохраняем трансформированное изображение
        status += " sucsess!";
    }
    else
    {
        status += " fault";
    }

    //qDebug() << status;
}
