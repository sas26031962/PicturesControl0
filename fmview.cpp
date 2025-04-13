#include "fmview.h"
#include "ui_fmview.h"

fmView::fmView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fmView)
{
    ui->setupUi(this);

    connect(this, SIGNAL(showExecStatus(QString)), this, SLOT( execShowExecStatus(QString)));
    connect(this->ui->horizontalSliderScale, SIGNAL(valueChanged(int)), this, SLOT( execHorizontalSliderValueChanged(int)));

}

fmView::~fmView()
{
    delete ui;
}

void fmView::execDraw(QString s)
{
    currentImagePath = s;
    emit showExecStatus(s + " Size=" + QString::number(iSize));
    cDrawFiles::scaleImage(s, iSize, iSize);
    QPixmap pmMain(cIniFile::scaledImagePath);//
    //QPixmap pmMain(s);//
    ui->labelMain->setPixmap(pmMain);
}

void fmView::execShowExecStatus(QString s)
{
    ui->labelInfo->setText(s);
}

void fmView::execHorizontalSliderValueChanged(int x)
{
    ui->labelInfo->setText("Picture size:" + QString::number(x));
    iSize = x;
    execDraw(currentImagePath);
}
