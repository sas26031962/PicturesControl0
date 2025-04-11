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
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_fmView
{
public:
    QLabel *labelMain;
    QLabel *label;
    QSlider *horizontalSliderScale;

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
        label = new QLabel(fmView);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 830, 621, 22));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 255, 250);"));
        horizontalSliderScale = new QSlider(fmView);
        horizontalSliderScale->setObjectName(QString::fromUtf8("horizontalSliderScale"));
        horizontalSliderScale->setGeometry(QRect(640, 830, 181, 22));
        horizontalSliderScale->setMinimum(410);
        horizontalSliderScale->setMaximum(1640);
        horizontalSliderScale->setValue(821);
        horizontalSliderScale->setOrientation(Qt::Horizontal);

        retranslateUi(fmView);

        QMetaObject::connectSlotsByName(fmView);
    } // setupUi

    void retranslateUi(QDialog *fmView)
    {
        fmView->setWindowTitle(QCoreApplication::translate("fmView", "ViewPicture", nullptr));
        labelMain->setText(QString());
        label->setText(QCoreApplication::translate("fmView", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fmView: public Ui_fmView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FMVIEW_H
