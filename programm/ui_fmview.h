/********************************************************************************
** Form generated from reading UI file 'fmview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FMVIEW_H
#define UI_FMVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_fmView
{
public:
    QLabel *labelMain;
    QLabel *labelInfo;
    QSlider *horizontalSliderScale;
    QLineEdit *lineEditX;
    QLineEdit *lineEditY;
    QLabel *labelXCaption;
    QLabel *labelXCaption_2;

    void setupUi(QDialog *fmView)
    {
        if (fmView->objectName().isEmpty())
            fmView->setObjectName(QString::fromUtf8("fmView"));
        fmView->resize(830, 860);
        labelMain = new QLabel(fmView);
        labelMain->setObjectName(QString::fromUtf8("labelMain"));
        labelMain->setGeometry(QRect(5, 5, 821, 821));
        labelMain->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 246, 255);"));
        labelMain->setAlignment(Qt::AlignCenter);
        labelInfo = new QLabel(fmView);
        labelInfo->setObjectName(QString::fromUtf8("labelInfo"));
        labelInfo->setGeometry(QRect(10, 830, 621, 22));
        labelInfo->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 255, 250);"));
        horizontalSliderScale = new QSlider(fmView);
        horizontalSliderScale->setObjectName(QString::fromUtf8("horizontalSliderScale"));
        horizontalSliderScale->setGeometry(QRect(650, 830, 171, 22));
        horizontalSliderScale->setMinimum(410);
        horizontalSliderScale->setMaximum(1640);
        horizontalSliderScale->setValue(821);
        horizontalSliderScale->setOrientation(Qt::Horizontal);
        lineEditX = new QLineEdit(fmView);
        lineEditX->setObjectName(QString::fromUtf8("lineEditX"));
        lineEditX->setGeometry(QRect(40, 800, 81, 22));
        lineEditY = new QLineEdit(fmView);
        lineEditY->setObjectName(QString::fromUtf8("lineEditY"));
        lineEditY->setGeometry(QRect(170, 800, 81, 22));
        labelXCaption = new QLabel(fmView);
        labelXCaption->setObjectName(QString::fromUtf8("labelXCaption"));
        labelXCaption->setGeometry(QRect(20, 800, 21, 22));
        labelXCaption_2 = new QLabel(fmView);
        labelXCaption_2->setObjectName(QString::fromUtf8("labelXCaption_2"));
        labelXCaption_2->setGeometry(QRect(150, 800, 21, 22));

        retranslateUi(fmView);

        QMetaObject::connectSlotsByName(fmView);
    } // setupUi

    void retranslateUi(QDialog *fmView)
    {
        fmView->setWindowTitle(QCoreApplication::translate("fmView", "ViewPicture", nullptr));
        labelMain->setText(QString());
        labelInfo->setText(QCoreApplication::translate("fmView", "TextLabel", nullptr));
        lineEditX->setText(QCoreApplication::translate("fmView", "0", nullptr));
        lineEditY->setText(QCoreApplication::translate("fmView", "880", nullptr));
        labelXCaption->setText(QCoreApplication::translate("fmView", "X=", nullptr));
        labelXCaption_2->setText(QCoreApplication::translate("fmView", "Y=", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fmView: public Ui_fmView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FMVIEW_H
