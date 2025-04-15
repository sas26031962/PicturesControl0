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

    connect(this->ui->lineEditX, SIGNAL(editingFinished()), this, SLOT( execXChanged()));
    //connect(this->ui->lineEditX, SIGNAL(inputRejected()), this, SLOT( execXRejected()));

    connect(this->ui->lineEditY, SIGNAL(editingFinished()), this, SLOT(execYChanged()));
    //connect(this->ui->lineEditY, SIGNAL(inputRejected()), this, SLOT( execYRejected()));

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

void fmView::execXChanged()
{
    QString s = ui->lineEditX->text();
    cDrawFiles::dx = INITIAL_SHIFT_X;
    cDrawFiles::dx += s.toInt();
    qDebug() << "X=" << s << " Value=" << cDrawFiles::dx;
    emit shiftXValueChanged();
    //execDraw(cIniFile::currentRotatedImagePath);
}

void fmView::execYChanged()
{
    QString s = ui->lineEditY->text();
    cDrawFiles::dy = INITIAL_SHIFT_Y;
    cDrawFiles::dy += s.toInt();
    qDebug() << "Y=" << s << " Value=" << cDrawFiles::dy;
    emit shiftYValueChanged();
    //execDraw(cIniFile::currentRotatedImagePath);
}

void fmView::execXRejected()
{
    QString s = ui->lineEditX->text();
    qDebug() << "X value Rejected: " << s;
}

void fmView::execYRejected()
{
    QString s = ui->lineEditY->text();
    qDebug() << "Y value Rejected: " << s;
}
