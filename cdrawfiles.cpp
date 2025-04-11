#include "cdrawfiles.h"

cDrawFiles::cDrawFiles()
{

}

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

    rotatedImage.save(cIniFile::currentRotatedImagePath); // Сохраняем повернутое изображение

    qDebug() << "Image rotated successfully";

    return cIniFile::currentRotatedImagePath;

}//End of void cDrawFiles::execRotate(int Angle)

//
//
//
void cDrawFiles::scaleImage(QString path, int width, int height)
{
    int newWidth = width;//ui->labelMain->width();//960
    int newHeight = height;//ui->labelMain->height();//540

    QImage originalImage(path);

    QString status;

    if (originalImage.isNull())
    {
        qDebug() << "Error: Could not load image: " << path;
        return;
    }

    // Масштабирование изображения
    QImage scaledImage = originalImage.scaled(
        newWidth,
        newHeight,
        Qt::KeepAspectRatio, // Сохранять пропорции
        Qt::SmoothTransformation // Использовать сглаживание
    );

    // Сохранение масштабированного изображения

    QString scaledImagePath = cIniFile::scaledImagePath;
    status = "Image scaling to file";
    status += scaledImagePath;
    if(scaledImagePath.count() > 0)
    {
        scaledImage.save(scaledImagePath);
        status += " sucsess!";
    }
    else
    {
        status += " fault";
    }

    qDebug() << status;
}
