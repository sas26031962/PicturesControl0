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
#include <atomic>

#include "cinifile.h"
#include "fmview.h"
#include "cimportfiles.h"

#define STATUS_BAR_DELAY 500
#define WINDOW_LEFT_MARGING 40
#define WINDOW_TOP_MARGING 65

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
    QLabel * labelRotator;

    QTimer * timerUpdate;
    int iTimerUpdateCounter = 0;

    QStringList Groups;

    fmView * fmViewPicture;

    int iAngle = 90;

    QStringList * qslHashTagList;
    //QString rotatedImagePath = "./img/tmp/rotated_image.png";

    //Методы
    void showCurrentIndexPicture();
    bool loadHashTagListSubject();
    bool loadHashTagListPlace();
    bool loadHashTagListProperty();
    bool loadHashTagListTheame();
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
    void execActionImportInitial();
    void execActionLoad();
    void execActionFormViewPicture();
    void execActionMemo();
    void execListWidgetSuggestItemClicked();
    void execTimerUpdate();

    void execActionLoadHashTagListSubject();
    void execActionLoadHashTagListPlace();
    void execActionLoadHashTagListProperty();
    void execActionLoadHashTagListTheame();

    void execActionRemoveMovie();
    void execActionRemoveText();
    void execActionRemoveTif();

    void execActionGetGroupsList();

    void execActionRotateCW();
    void execActionRotateCCW();
    void execSpinBoxAngle(int angle);
    void execShowExecStatus(QString s);

public slots:

signals:
    void draw(QString s);
    void showExecStatus(QString s);
};

#endif // MAINWINDOW_H
