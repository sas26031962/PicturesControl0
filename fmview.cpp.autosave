#include "fmview.h"
#include "ui_fmview.h"

fmView::fmView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fmView)
{
    ui->setupUi(this);

    connect(this, SIGNAL(showExecStatus(QString)), this, SLOT( execShowExecStatus(QString)));

}

fmView::~fmView()
{
    delete ui;
}

void fmView::execDraw(QString s)
{
    scaleImage(s);
    QPixmap pmMain(cIniFile::scaledImagePath);//
    //QPixmap pmMain(s);//
    ui->labelMain->setPixmap(pmMain);
}

void fmView::scaleImage(QString path)
{
    int newWidth = ui->labelMain->width();//960
    int newHeight = ui->labelMain->height();//540

    QImage originalImage(path);

    QString status;

    if (originalImage.isNull())
    {
        ui->labelMain->setText(path);
        qDebug() << "Error: Could not load image: " << path;

        status = "Error: Could not load image: " + path;
        emit showExecStatus(status);
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
    scaledImage.save(cIniFile::scaledImagePath);

    status = "Image scaling sucsess!";
    emit showExecStatus(status);

}

void fmView::execShowExecStatus(QString s)
{
    ui->label->setText(s);
}
