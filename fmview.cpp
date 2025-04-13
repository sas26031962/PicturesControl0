#include "fmview.h"
#include "ui_fmview.h"

fmView::fmView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fmView)
{
    ui->setupUi(this);

    QIntValidator *validatorX = new QIntValidator(0, INT_VALIDATOR_VALUE, this);
    QIntValidator *validatorY = new QIntValidator(0, INT_VALIDATOR_VALUE, this);
    ui->lineEditX->setValidator(validatorX);
    ui->lineEditY->setValidator(validatorY);


    connect(this, SIGNAL(showExecStatus(QString)), this, SLOT( execShowExecStatus(QString)));
    connect(this->ui->horizontalSliderScale, SIGNAL(valueChanged(int)), this, SLOT( execHorizontalSliderValueChanged(int)));

    connect(this->ui->lineEditX, SIGNAL(editingFinished()), this, SLOT( exexXChanged()));
    connect(this->ui->lineEditX, SIGNAL(inputRejected()), this, SLOT( exexXRejected()));

    connect(this->ui->lineEditY, SIGNAL(editingFinished()), this, SLOT(exexYChanged()));
    connect(this->ui->lineEditY, SIGNAL(inputRejected()), this, SLOT( exexYRejected()));

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

void fmView::exexXChanged()
{
    QString s = ui->lineEditX->text();
    cDrawFiles::dx = s.toInt();
    qDebug() << "X=" << s << " Value=" << cDrawFiles::dx;
    execDraw(currentImagePath);
}

void fmView::exexYChanged()
{
    QString s = ui->lineEditY->text();
    cDrawFiles::dy = s.toInt();
    qDebug() << "Y=" << s << " Value=" << cDrawFiles::dy;
    execDraw(currentImagePath);
}

void fmView::exexXRejected()
{
    QString s = ui->lineEditX->text();
    qDebug() << "X value Rejected: " << s;
}

void fmView::exexYRejected()
{
    QString s = ui->lineEditY->text();
    qDebug() << "Y value Rejected: " << s;
}
