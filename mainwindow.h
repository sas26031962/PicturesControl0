#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QImage>
#include <QProgressBar>
#include <QLabel>
#include <memory>
#include <QStringList>
#include <QTableView>
#include <QStandardItemModel>
#include <QStringListIterator>
#include <QFile>
#include <QTextStream>
#include <QPainter>
#include <QImage>
#include <QTransform>
#include <QTimer>

//#include <fstream>

#include "cinifile.h"
#include "fmview.h"

#define STATUS_BAR_DELAY 500
#define WINDOW_MARGING 20

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
    QTimer * timerUpdate;

    int CurrentIndex = 0;
    QString labelExecStatusText = "";
    bool IslabelExecStatusTextChacnged = false;

    QStringList Groups;

    fmView * ViewPicture;

    int iAngle = 90;

    QStringList * qslHashTagList;
    QString rotatedImagePath = "./img/tmp/rotated_image.png";
    //QString rotatedImagePath = ":/tmp_files/programm/img/tmp/rotated_image.png";

    //Методы
    void showCurrentIndexPicture();
    bool loadHashTagListSubject();
    bool loadHashTagListPlace();
    void execRotate(int angle);

public:
    //Атрибуты
    QString filePathSubject;
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
    void execListWidgetSuggestItemClicked();
    void execTimerUpdate();

    void execActionLoadHashTagListSubject();
    void execActionLoadHashTagListPlace();
    void execActionRemoveMovie();
    void execActionRotateCW();
    void execActionRotateCCW();
    void execSpinBoxAngle(int angle);

public slots:

signals:
    void draw(QString s);
};

#endif // MAINWINDOW_H
