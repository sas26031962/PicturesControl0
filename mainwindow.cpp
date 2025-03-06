#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionSelectImageBegin, SIGNAL(triggered()), this, SLOT( execActionSelectImageBegin()));
    connect(ui->actionSelectImageNext, SIGNAL(triggered()), this, SLOT( execActionSelectImageNext()));
    connect(ui->actionSelectImagePrevious, SIGNAL(triggered()), this, SLOT( execActionSelectImagePrevious()));
    connect(ui->actionSelectImageEnd, SIGNAL(triggered()), this, SLOT( execActionSelectImageEnd()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::scaleImage(QString path)
{
    int newWidth = ui->labelMain->width();//960
    int newHeight = ui->labelMain->height();//540

    QImage originalImage(path);

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
    scaledImage.save(scaledImagePath);
}

void MainWindow::execActionSelectImageBegin()
{
    QString s = "execActionSelectImageBegin()";
    qDebug() << s;
    ui->statusBar->showMessage(s, STATUS_BAR_DELAY);

    QString imagePath = "./img/Ships/Cruiser_Moscow.png"; // Путь к вашему изображению

    scaleImage(imagePath);
/*
    int newWidth = ui->labelMain->width();//960
    int newHeight = ui->labelMain->height();//540

    QImage originalImage(imagePath);

    if (originalImage.isNull())
    {
        qDebug() << "Error: Could not load image: " << imagePath;
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
*/
    QPixmap pmMain(scaledImagePath);//
    ui->labelMain->setPixmap(pmMain);
}

void MainWindow::execActionSelectImageNext()
{
    QString s = "execActionSelectImageNext()";
    qDebug() << s;
    ui->statusBar->showMessage(s, STATUS_BAR_DELAY);
}

void MainWindow::execActionSelectImagePrevious()
{
    QString s = "execActionSelectImagePrevious()";
    qDebug() << s;
    ui->statusBar->showMessage(s, STATUS_BAR_DELAY);
}

void MainWindow::execActionSelectImageEnd()
{
    QString s = "execActionSelectImageEmd()";
    qDebug() << s;
    ui->statusBar->showMessage(s, STATUS_BAR_DELAY);
}
