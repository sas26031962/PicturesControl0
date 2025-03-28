/********************************************************************************
** Form generated from reading UI file 'fmview.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FMVIEW_H
#define UI_FMVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
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
            fmView->setObjectName(QStringLiteral("fmView"));
        fmView->resize(830, 575);
        labelMain = new QLabel(fmView);
        labelMain->setObjectName(QStringLiteral("labelMain"));
        labelMain->setGeometry(QRect(5, 5, 821, 531));
        label = new QLabel(fmView);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 550, 811, 16));

        retranslateUi(fmView);

        QMetaObject::connectSlotsByName(fmView);
    } // setupUi

    void retranslateUi(QDialog *fmView)
    {
        fmView->setWindowTitle(QApplication::translate("fmView", "ViewPicture", 0));
        labelMain->setText(QString());
        label->setText(QApplication::translate("fmView", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class fmView: public Ui_fmView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FMVIEW_H
