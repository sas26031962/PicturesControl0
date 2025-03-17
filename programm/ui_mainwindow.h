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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(481, 495);
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
        actionViewPicture = new QAction(MainWindow);
        actionViewPicture->setObjectName(QStringLiteral("actionViewPicture"));
        actionViewPicture->setCheckable(true);
        actionViewPicture->setChecked(true);
        actionLoaadHashTagListSubject = new QAction(MainWindow);
        actionLoaadHashTagListSubject->setObjectName(QStringLiteral("actionLoaadHashTagListSubject"));
        actionLoadHashTagListPlace = new QAction(MainWindow);
        actionLoadHashTagListPlace->setObjectName(QStringLiteral("actionLoadHashTagListPlace"));
        actionRemoveMovie = new QAction(MainWindow);
        actionRemoveMovie->setObjectName(QStringLiteral("actionRemoveMovie"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
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
        listWidgetSuggest = new QListWidget(centralWidget);
        listWidgetSuggest->setObjectName(QStringLiteral("listWidgetSuggest"));
        listWidgetSuggest->setGeometry(QRect(250, 30, 221, 341));
        labelSuggestListCaption = new QLabel(centralWidget);
        labelSuggestListCaption->setObjectName(QStringLiteral("labelSuggestListCaption"));
        labelSuggestListCaption->setGeometry(QRect(250, 10, 221, 20));
        labelIncomingListCaption = new QLabel(centralWidget);
        labelIncomingListCaption->setObjectName(QStringLiteral("labelIncomingListCaption"));
        labelIncomingListCaption->setGeometry(QRect(10, 10, 221, 20));
        tableViewCurrent = new QTableView(centralWidget);
        tableViewCurrent->setObjectName(QStringLiteral("tableViewCurrent"));
        tableViewCurrent->setGeometry(QRect(10, 30, 231, 341));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 481, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuSelect_image = new QMenu(menuBar);
        menuSelect_image->setObjectName(QStringLiteral("menuSelect_image"));
        menuForms = new QMenu(menuBar);
        menuForms->setObjectName(QStringLiteral("menuForms"));
        menuTags = new QMenu(menuBar);
        menuTags->setObjectName(QStringLiteral("menuTags"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionSelectImageBegin->setText(QApplication::translate("MainWindow", "Begin", 0));
        actionSelectImageNext->setText(QApplication::translate("MainWindow", "Next", 0));
        actionSelectImagePrevious->setText(QApplication::translate("MainWindow", "Previous", 0));
        actionSelectImageEnd->setText(QApplication::translate("MainWindow", "End", 0));
        actionImport->setText(QApplication::translate("MainWindow", "Import", 0));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", 0));
        actionViewPicture->setText(QApplication::translate("MainWindow", "ViewPicture", 0));
        actionLoaadHashTagListSubject->setText(QApplication::translate("MainWindow", "Subject", 0));
        actionLoadHashTagListPlace->setText(QApplication::translate("MainWindow", "Place", 0));
        actionRemoveMovie->setText(QApplication::translate("MainWindow", "RemoveMovie", 0));
        groupBoxControl->setTitle(QApplication::translate("MainWindow", "Navigation", 0));
        pushButtonBegin->setText(QApplication::translate("MainWindow", "|<", 0));
        pushButtonNext->setText(QApplication::translate("MainWindow", ">", 0));
        pushButtonPrevious->setText(QApplication::translate("MainWindow", "<", 0));
        pushButtonEnd->setText(QApplication::translate("MainWindow", ">|", 0));
        pushButtonLoad->setText(QApplication::translate("MainWindow", "Load", 0));
        labelSuggestListCaption->setText(QApplication::translate("MainWindow", "Suggest tags", 0));
        labelIncomingListCaption->setText(QApplication::translate("MainWindow", "Incoming tag", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuSelect_image->setTitle(QApplication::translate("MainWindow", "Select image", 0));
        menuForms->setTitle(QApplication::translate("MainWindow", "Forms", 0));
        menuTags->setTitle(QApplication::translate("MainWindow", "Tags", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
