#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QImage>
#include <QProgressBar>
#include <QLabel>
#include <memory>
#include <QStringList>
#include "cinifile.h"

#define STATUS_BAR_DELAY 500

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    //Атрибуты
    QString scaledImagePath = "./img/tmp/scaled_image.png";
    bool IsError = false;

    QLabel * labelProgressBar;
    QLabel * labelFileName;
    QProgressBar * progressBarProcess;

    int CurrentIndex = 0;
    QStringList Groups;

    //Методы
    void showCurrentIndexPicture();

public:
    //Конструкторы, деструкторы
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

   //Методы
   void scaleImage(QString);

private:
    Ui::MainWindow *ui;

private slots:

    void execActionSelectImageBegin();
    void execActionSelectImageNext();
    void execActionSelectImagePrevious();
    void execActionSelectImageEnd();
    void execActionImport();
    void execActionLoad();

public slots:

signals:

};

#endif // MAINWINDOW_H
