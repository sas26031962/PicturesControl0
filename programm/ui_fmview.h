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

QT_BEGIN_NAMESPACE

class Ui_fmView
{
public:
    QLabel *labelMain;
    QLabel *label;

    void setupUi(QDialog *fmView)
    {
        if (fmView->objectName().isEmpty())
            fmView->setObjectName(QString::fromUtf8("fmView"));
        fmView->resize(830, 575);
        labelMain = new QLabel(fmView);
        labelMain->setObjectName(QString::fromUtf8("labelMain"));
        labelMain->setGeometry(QRect(5, 5, 821, 531));
        label = new QLabel(fmView);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 550, 811, 16));

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
