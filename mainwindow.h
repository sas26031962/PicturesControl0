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
#include <QKeyEvent>

#include "cinifile.h"
#include "fmview.h"
#include "cimportfiles.h"
#include "stvarmem.h"

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
    varMem <int> KeyPressed;

    bool IsError = false;

    QLabel * labelExecStatus;
    QLabel * labelFileName;
    QProgressBar * progressBarProcess;
    QProgressBar * progressBarNavigation;
    QLabel * labelRotator;

    QTimer * timerUpdate;
    int iTimerUpdateCounter = 0;

    QStringList Groups;

    fmView * fmViewPicture;

    int iAngle = 90;

    QStringList * qslHashTagList;

    QStringList qslDeletedSections;

    //QString rotatedImagePath = "./img/tmp/rotated_image.png";

    //Методы
    void showCurrentIndexPicture();
    bool loadHashTagListSubject();
    bool loadHashTagListPlace();
    bool loadHashTagListProperty();
    bool loadHashTagListTheame();
    void execRotate(int angle);
    bool deleteSection(QString s);

public:
    //Атрибуты
    QString filePathSubject;
    //Конструкторы, деструкторы
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

   //Методы
   void scaleImage(QString);

protected:
    void keyPressEvent(QKeyEvent * e) override;//keys

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
    void execTimerUpdate();

    void execListWidgetSubjectItemClicked();
    void execListWidgetPropertyItemClicked();
    void execListWidgetTheameItemClicked();
    void execListWidgetPlaceItemClicked();

    void execActionLoadHashTagListSubject();
    void execActionLoadHashTagListPlace();
    void execActionLoadHashTagListProperty();
    void execActionLoadHashTagListTheame();

    void execActionRemoveMovie();
    void execActionRemoveText();
    void execActionRemoveTif();
    void execActionRemoveSection();

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
