#ifndef FMVIEW_H
#define FMVIEW_H

#include <QDialog>
#include <QDebug>
#include <QStatusBar>
#include <QString>

#include "cinifile.h"
#include "cdrawfiles.h"

namespace Ui {
class fmView;
}

class fmView : public QDialog
{
    Q_OBJECT

public:
    int iSize = 821;
    QString currentImagePath;

    explicit fmView(QWidget *parent = 0);
    ~fmView();

private:
    Ui::fmView *ui;

    //Методы

private slots:

    void execDraw(QString s);
    void execShowExecStatus(QString s);
    void execHorizontalSliderValueChanged(int x);

signals:
    void showExecStatus(QString s);

};

#endif // FMVIEW_H
