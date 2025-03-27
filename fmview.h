#ifndef FMVIEW_H
#define FMVIEW_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class fmView;
}

class fmView : public QDialog
{
    Q_OBJECT

public:
    QString scaledImagePath = "./img/tmp/scaled_image.png";
    //QString scaledImagePath = ":/tmp_files/programm/img/tmp/scaled_image.png";

    explicit fmView(QWidget *parent = 0);
    ~fmView();

private:
    Ui::fmView *ui;

    //Методы
    void scaleImage(QString);

private slots:

    void execDraw(QString s);

signals:
    void showExecStatus(QString s);

};

#endif // FMVIEW_H
