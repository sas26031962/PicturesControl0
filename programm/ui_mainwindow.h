/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
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
    QAction *actionViewPicture;
    QAction *actionLoaadHashTagListSubject;
    QAction *actionLoadHashTagListPlace;
    QAction *actionRemoveMovie;
    QWidget *centralWidget;
    QGroupBox *groupBoxControl;
    QPushButton *pushButtonBegin;
    QPushButton *pushButtonNext;
    QPushButton *pushButtonPrevious;
    QPushButton *pushButtonEnd;
    QPushButton *pushButtonLoad;
    QListWidget *listWidgetSuggest;
    QLabel *labelSuggestListCaption;
    QLabel *labelIncomingListCaption;
    QTableView *tableViewCurrent;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuSelect_image;
    QMenu *menuForms;
    QMenu *menuTags;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(481, 495);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionSelectImageBegin = new QAction(MainWindow);
        actionSelectImageBegin->setObjectName(QString::fromUtf8("actionSelectImageBegin"));
        actionSelectImageNext = new QAction(MainWindow);
        actionSelectImageNext->setObjectName(QString::fromUtf8("actionSelectImageNext"));
        actionSelectImagePrevious = new QAction(MainWindow);
        actionSelectImagePrevious->setObjectName(QString::fromUtf8("actionSelectImagePrevious"));
        actionSelectImageEnd = new QAction(MainWindow);
        actionSelectImageEnd->setObjectName(QString::fromUtf8("actionSelectImageEnd"));
        actionImport = new QAction(MainWindow);
        actionImport->setObjectName(QString::fromUtf8("actionImport"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionViewPicture = new QAction(MainWindow);
        actionViewPicture->setObjectName(QString::fromUtf8("actionViewPicture"));
        actionViewPicture->setCheckable(true);
        actionViewPicture->setChecked(true);
        actionLoaadHashTagListSubject = new QAction(MainWindow);
        actionLoaadHashTagListSubject->setObjectName(QString::fromUtf8("actionLoaadHashTagListSubject"));
        actionLoadHashTagListPlace = new QAction(MainWindow);
        actionLoadHashTagListPlace->setObjectName(QString::fromUtf8("actionLoadHashTagListPlace"));
        actionRemoveMovie = new QAction(MainWindow);
        actionRemoveMovie->setObjectName(QString::fromUtf8("actionRemoveMovie"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBoxControl = new QGroupBox(centralWidget);
        groupBoxControl->setObjectName(QString::fromUtf8("groupBoxControl"));
        groupBoxControl->setGeometry(QRect(10, 380, 221, 51));
        pushButtonBegin = new QPushButton(groupBoxControl);
        pushButtonBegin->setObjectName(QString::fromUtf8("pushButtonBegin"));
        pushButtonBegin->setGeometry(QRect(100, 20, 23, 23));
        pushButtonNext = new QPushButton(groupBoxControl);
        pushButtonNext->setObjectName(QString::fromUtf8("pushButtonNext"));
        pushButtonNext->setGeometry(QRect(130, 20, 23, 23));
        pushButtonPrevious = new QPushButton(groupBoxControl);
        pushButtonPrevious->setObjectName(QString::fromUtf8("pushButtonPrevious"));
        pushButtonPrevious->setGeometry(QRect(160, 20, 23, 23));
        pushButtonEnd = new QPushButton(groupBoxControl);
        pushButtonEnd->setObjectName(QString::fromUtf8("pushButtonEnd"));
        pushButtonEnd->setGeometry(QRect(190, 20, 23, 23));
        pushButtonLoad = new QPushButton(groupBoxControl);
        pushButtonLoad->setObjectName(QString::fromUtf8("pushButtonLoad"));
        pushButtonLoad->setGeometry(QRect(10, 20, 75, 23));
        listWidgetSuggest = new QListWidget(centralWidget);
        listWidgetSuggest->setObjectName(QString::fromUtf8("listWidgetSuggest"));
        listWidgetSuggest->setGeometry(QRect(250, 30, 221, 341));
        labelSuggestListCaption = new QLabel(centralWidget);
        labelSuggestListCaption->setObjectName(QString::fromUtf8("labelSuggestListCaption"));
        labelSuggestListCaption->setGeometry(QRect(250, 10, 221, 20));
        labelIncomingListCaption = new QLabel(centralWidget);
        labelIncomingListCaption->setObjectName(QString::fromUtf8("labelIncomingListCaption"));
        labelIncomingListCaption->setGeometry(QRect(10, 10, 221, 20));
        tableViewCurrent = new QTableView(centralWidget);
        tableViewCurrent->setObjectName(QString::fromUtf8("tableViewCurrent"));
        tableViewCurrent->setGeometry(QRect(10, 30, 231, 341));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 481, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuSelect_image = new QMenu(menuBar);
        menuSelect_image->setObjectName(QString::fromUtf8("menuSelect_image"));
        menuForms = new QMenu(menuBar);
        menuForms->setObjectName(QString::fromUtf8("menuForms"));
        menuTags = new QMenu(menuBar);
        menuTags->setObjectName(QString::fromUtf8("menuTags"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSelect_image->menuAction());
        menuBar->addAction(menuForms->menuAction());
        menuBar->addAction(menuTags->menuAction());
        menuFile->addAction(actionImport);
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionRemoveMovie);
        menuFile->addAction(actionExit);
        menuSelect_image->addAction(actionSelectImageBegin);
        menuSelect_image->addAction(actionSelectImageNext);
        menuSelect_image->addAction(actionSelectImagePrevious);
        menuSelect_image->addAction(actionSelectImageEnd);
        menuForms->addAction(actionViewPicture);
        menuTags->addAction(actionLoaadHashTagListSubject);
        menuTags->addAction(actionLoadHashTagListPlace);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionSelectImageBegin->setText(QCoreApplication::translate("MainWindow", "Begin", nullptr));
        actionSelectImageNext->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        actionSelectImagePrevious->setText(QCoreApplication::translate("MainWindow", "Previous", nullptr));
        actionSelectImageEnd->setText(QCoreApplication::translate("MainWindow", "End", nullptr));
        actionImport->setText(QCoreApplication::translate("MainWindow", "Import", nullptr));
        actionLoad->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        actionViewPicture->setText(QCoreApplication::translate("MainWindow", "ViewPicture", nullptr));
        actionLoaadHashTagListSubject->setText(QCoreApplication::translate("MainWindow", "Subject", nullptr));
        actionLoadHashTagListPlace->setText(QCoreApplication::translate("MainWindow", "Place", nullptr));
        actionRemoveMovie->setText(QCoreApplication::translate("MainWindow", "RemoveMovie", nullptr));
        groupBoxControl->setTitle(QCoreApplication::translate("MainWindow", "Navigation", nullptr));
        pushButtonBegin->setText(QCoreApplication::translate("MainWindow", "|<", nullptr));
        pushButtonNext->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        pushButtonPrevious->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        pushButtonEnd->setText(QCoreApplication::translate("MainWindow", ">|", nullptr));
        pushButtonLoad->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        labelSuggestListCaption->setText(QCoreApplication::translate("MainWindow", "Suggest tags", nullptr));
        labelIncomingListCaption->setText(QCoreApplication::translate("MainWindow", "Incoming tag", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuSelect_image->setTitle(QCoreApplication::translate("MainWindow", "Select image", nullptr));
        menuForms->setTitle(QCoreApplication::translate("MainWindow", "Forms", nullptr));
        menuTags->setTitle(QCoreApplication::translate("MainWindow", "Tags", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
