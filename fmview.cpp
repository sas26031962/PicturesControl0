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
    //iSize = ui->horizontalSliderScale->value();
    //cDrawFiles::scaleImage(s, ui->labelMain->width(), ui->labelMain->height());
    cDrawFiles::scaleImage(s, iSize, iSize);
    QPixmap pmMain(cIniFile::scaledImagePath);//
    //QPixmap pmMain(s);//
    ui->labelMain->setPixmap(pmMain);
}

void fmView::execShowExecStatus(QString s)
{
    ui->label->setText(s);
}

void fmView::execHorizontalSliderValueChanged(int x)
{
    ui->label->setText("Picture size:" + QString::number(x));
    iSize = x;
    execDraw(currentImagePath);
}
