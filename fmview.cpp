#include "fmview.h"
#include "ui_fmview.h"

fmView::fmView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fmView)
{
    ui->setupUi(this);
}

fmView::~fmView()
{
    delete ui;
}

void fmView::execDraw(QString s)
{
    //ui->labelMain->setText(s);
    //Вывод картинки на форму
    scaleImage(s);
    QPixmap pmMain(scaledImagePath);//
    //QPixmap pmMain(s);//
    ui->labelMain->setPixmap(pmMain);
}

void fmView::scaleImage(QString path)
{
    int newWidth = ui->labelMain->width();//960
    int newHeight = ui->labelMain->height();//540

    QImage originalImage(path);

    if (originalImage.isNull())
    {
        ui->labelMain->setText(path);
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
    scaledImage.save(scaledImagePath);
}

