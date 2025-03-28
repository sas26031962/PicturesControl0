#ifndef FMVIEW_H
#define FMVIEW_H

#include <QDialog>
#include <QDebug>
#include <QStatusBar>

#include "cinifile.h"

namespace Ui {
class fmView;
}

class fmView : public QDialog
{
    Q_OBJECT

public:

    explicit fmView(QWidget *parent = 0);
    ~fmView();

private:
    Ui::fmView *ui;

    //Методы
    void scaleImage(QString);

private slots:

    void execDraw(QString s);
    void execShowExecStatus(QString s);

signals:
    void showExecStatus(QString s);

};

#endif // FMVIEW_H
