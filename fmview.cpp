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
    cDrawFiles::scaleImage(s, ui->labelMain->width(), ui->labelMain->height());
    QPixmap pmMain(cIniFile::scaledImagePath);//
    //QPixmap pmMain(s);//
    ui->labelMain->setPixmap(pmMain);
}

void fmView::execShowExecStatus(QString s)
{
    ui->label->setText(s);
}
