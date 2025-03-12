/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionSelectImageBegin;
    QAction *actionSelectImageNext;
    QAction *actionSelectImagePrevious;
    QAction *actionSelectImageEnd;
    QAction *actionImport;
    QAction *actionLoad;
    QWidget *centralWidget;
    QLabel *labelMain;
    QGroupBox *groupBoxControl;
    QPushButton *pushButtonBegin;
    QPushButton *pushButtonNext;
    QPushButton *pushButtonPrevious;
    QPushButton *pushButtonEnd;
    QPushButton *pushButtonLoad;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuSelect_image;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(696, 495);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionSelectImageBegin = new QAction(MainWindow);
        actionSelectImageBegin->setObjectName(QStringLiteral("actionSelectImageBegin"));
        actionSelectImageNext = new QAction(MainWindow);
        actionSelectImageNext->setObjectName(QStringLiteral("actionSelectImageNext"));
        actionSelectImagePrevious = new QAction(MainWindow);
        actionSelectImagePrevious->setObjectName(QStringLiteral("actionSelectImagePrevious"));
        actionSelectImageEnd = new QAction(MainWindow);
        actionSelectImageEnd->setObjectName(QStringLiteral("actionSelectImageEnd"));
        actionImport = new QAction(MainWindow);
        actionImport->setObjectName(QStringLiteral("actionImport"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        labelMain = new QLabel(centralWidget);
        labelMain->setObjectName(QStringLiteral("labelMain"));
        labelMain->setGeometry(QRect(26, 20, 661, 341));
        groupBoxControl = new QGroupBox(centralWidget);
        groupBoxControl->setObjectName(QStringLiteral("groupBoxControl"));
        groupBoxControl->setGeometry(QRect(10, 380, 221, 51));
        pushButtonBegin = new QPushButton(groupBoxControl);
        pushButtonBegin->setObjectName(QStringLiteral("pushButtonBegin"));
        pushButtonBegin->setGeometry(QRect(100, 20, 23, 23));
        pushButtonNext = new QPushButton(groupBoxControl);
        pushButtonNext->setObjectName(QStringLiteral("pushButtonNext"));
        pushButtonNext->setGeometry(QRect(130, 20, 23, 23));
        pushButtonPrevious = new QPushButton(groupBoxControl);
        pushButtonPrevious->setObjectName(QStringLiteral("pushButtonPrevious"));
        pushButtonPrevious->setGeometry(QRect(160, 20, 23, 23));
        pushButtonEnd = new QPushButton(groupBoxControl);
        pushButtonEnd->setObjectName(QStringLiteral("pushButtonEnd"));
        pushButtonEnd->setGeometry(QRect(190, 20, 23, 23));
        pushButtonLoad = new QPushButton(groupBoxControl);
        pushButtonLoad->setObjectName(QStringLiteral("pushButtonLoad"));
        pushButtonLoad->setGeometry(QRect(10, 20, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 696, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuSelect_image = new QMenu(menuBar);
        menuSelect_image->setObjectName(QStringLiteral("menuSelect_image"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSelect_image->menuAction());
        menuFile->addAction(actionImport);
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionExit);
        menuSelect_image->addAction(actionSelectImageBegin);
        menuSelect_image->addAction(actionSelectImageNext);
        menuSelect_image->addAction(actionSelectImagePrevious);
        menuSelect_image->addAction(actionSelectImageEnd);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionSelectImageBegin->setText(QApplication::translate("MainWindow", "Begin", 0));
        actionSelectImageNext->setText(QApplication::translate("MainWindow", "Next", 0));
        actionSelectImagePrevious->setText(QApplication::translate("MainWindow", "Previous", 0));
        actionSelectImageEnd->setText(QApplication::translate("MainWindow", "End", 0));
        actionImport->setText(QApplication::translate("MainWindow", "Import", 0));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", 0));
        labelMain->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        groupBoxControl->setTitle(QApplication::translate("MainWindow", "Navigation", 0));
        pushButtonBegin->setText(QApplication::translate("MainWindow", "|<", 0));
        pushButtonNext->setText(QApplication::translate("MainWindow", ">", 0));
        pushButtonPrevious->setText(QApplication::translate("MainWindow", "<", 0));
        pushButtonEnd->setText(QApplication::translate("MainWindow", ">|", 0));
        pushButtonLoad->setText(QApplication::translate("MainWindow", "Load", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuSelect_image->setTitle(QApplication::translate("MainWindow", "Select image", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
