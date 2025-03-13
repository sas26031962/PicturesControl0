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
#include "fmview.h"

#define STATUS_BAR_DELAY 500

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    //Атрибуты
    bool IsError = false;

    QLabel * labelExecStatus;
    QLabel * labelFileName;
    QProgressBar * progressBarProcess;

    int CurrentIndex = 0;
    QStringList Groups;

    fmView * ViewPicture;

    QStringList * qslHashTagList;

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
    void execActionFormViewPicture();
    void execListWidgetViewItemClicked();

public slots:

signals:
    void draw(QString s);
};

#endif // MAINWINDOW_H
