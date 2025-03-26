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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
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
    QAction *actionRotateCW;
    QAction *actionRotateCCW;
    QAction *actionLoadHashTagListProperty;
    QAction *actionImportFiles;
    QWidget *centralWidget;
    QGroupBox *groupBoxControl;
    QPushButton *pushButtonBegin;
    QPushButton *pushButtonNext;
    QPushButton *pushButtonPrevious;
    QPushButton *pushButtonEnd;
    QListWidget *listWidgetSuggest;
    QLabel *labelSuggestListCaption;
    QLabel *labelIncomingListCaption;
    QTableView *tableViewCurrent;
    QGroupBox *groupBoxEdit;
    QPushButton *pushButtonLoad;
    QLineEdit *lineEditMemo;
    QPushButton *pushButtonMemo;
    QGroupBox *groupBoxRotate;
    QPushButton *pushButtonRotateCCW;
    QSpinBox *spinBoxAngle;
    QPushButton *pushButtonRotateCW;
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
        MainWindow->resize(481, 583);
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
        actionRotateCW = new QAction(MainWindow);
        actionRotateCW->setObjectName(QString::fromUtf8("actionRotateCW"));
        actionRotateCCW = new QAction(MainWindow);
        actionRotateCCW->setObjectName(QString::fromUtf8("actionRotateCCW"));
        actionLoadHashTagListProperty = new QAction(MainWindow);
        actionLoadHashTagListProperty->setObjectName(QString::fromUtf8("actionLoadHashTagListProperty"));
        actionImportFiles = new QAction(MainWindow);
        actionImportFiles->setObjectName(QString::fromUtf8("actionImportFiles"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBoxControl = new QGroupBox(centralWidget);
        groupBoxControl->setObjectName(QString::fromUtf8("groupBoxControl"));
        groupBoxControl->setGeometry(QRect(10, 380, 191, 51));
        pushButtonBegin = new QPushButton(groupBoxControl);
        pushButtonBegin->setObjectName(QString::fromUtf8("pushButtonBegin"));
        pushButtonBegin->setGeometry(QRect(20, 20, 23, 23));
        pushButtonNext = new QPushButton(groupBoxControl);
        pushButtonNext->setObjectName(QString::fromUtf8("pushButtonNext"));
        pushButtonNext->setGeometry(QRect(80, 20, 23, 23));
        pushButtonPrevious = new QPushButton(groupBoxControl);
        pushButtonPrevious->setObjectName(QString::fromUtf8("pushButtonPrevious"));
        pushButtonPrevious->setGeometry(QRect(50, 20, 23, 23));
        pushButtonEnd = new QPushButton(groupBoxControl);
        pushButtonEnd->setObjectName(QString::fromUtf8("pushButtonEnd"));
        pushButtonEnd->setGeometry(QRect(110, 20, 23, 23));
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
        groupBoxEdit = new QGroupBox(centralWidget);
        groupBoxEdit->setObjectName(QString::fromUtf8("groupBoxEdit"));
        groupBoxEdit->setGeometry(QRect(20, 430, 451, 51));
        pushButtonLoad = new QPushButton(groupBoxEdit);
        pushButtonLoad->setObjectName(QString::fromUtf8("pushButtonLoad"));
        pushButtonLoad->setGeometry(QRect(10, 20, 75, 23));
        lineEditMemo = new QLineEdit(groupBoxEdit);
        lineEditMemo->setObjectName(QString::fromUtf8("lineEditMemo"));
        lineEditMemo->setGeometry(QRect(90, 20, 301, 23));
        pushButtonMemo = new QPushButton(groupBoxEdit);
        pushButtonMemo->setObjectName(QString::fromUtf8("pushButtonMemo"));
        pushButtonMemo->setGeometry(QRect(400, 20, 31, 23));
        groupBoxRotate = new QGroupBox(centralWidget);
        groupBoxRotate->setObjectName(QString::fromUtf8("groupBoxRotate"));
        groupBoxRotate->setGeometry(QRect(210, 380, 261, 51));
        pushButtonRotateCCW = new QPushButton(groupBoxRotate);
        pushButtonRotateCCW->setObjectName(QString::fromUtf8("pushButtonRotateCCW"));
        pushButtonRotateCCW->setGeometry(QRect(93, 20, 75, 23));
        spinBoxAngle = new QSpinBox(groupBoxRotate);
        spinBoxAngle->setObjectName(QString::fromUtf8("spinBoxAngle"));
        spinBoxAngle->setGeometry(QRect(183, 20, 51, 22));
        spinBoxAngle->setMinimum(-90);
        spinBoxAngle->setMaximum(90);
        pushButtonRotateCW = new QPushButton(groupBoxRotate);
        pushButtonRotateCW->setObjectName(QString::fromUtf8("pushButtonRotateCW"));
        pushButtonRotateCW->setGeometry(QRect(10, 20, 75, 23));
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
        menuFile->addAction(actionRotateCW);
        menuFile->addAction(actionRotateCCW);
        menuFile->addAction(actionExit);
        menuFile->addAction(actionImportFiles);
        menuSelect_image->addAction(actionSelectImageBegin);
        menuSelect_image->addAction(actionSelectImageNext);
        menuSelect_image->addAction(actionSelectImagePrevious);
        menuSelect_image->addAction(actionSelectImageEnd);
        menuForms->addAction(actionViewPicture);
        menuTags->addAction(actionLoaadHashTagListSubject);
        menuTags->addAction(actionLoadHashTagListPlace);
        menuTags->addAction(actionLoadHashTagListProperty);

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
        actionImport->setText(QCoreApplication::translate("MainWindow", "ImportInitial", nullptr));
        actionLoad->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        actionViewPicture->setText(QCoreApplication::translate("MainWindow", "ViewPicture", nullptr));
        actionLoaadHashTagListSubject->setText(QCoreApplication::translate("MainWindow", "Subject", nullptr));
        actionLoadHashTagListPlace->setText(QCoreApplication::translate("MainWindow", "Place", nullptr));
        actionRemoveMovie->setText(QCoreApplication::translate("MainWindow", "RemoveMovie", nullptr));
        actionRotateCW->setText(QCoreApplication::translate("MainWindow", "RotateCW", nullptr));
        actionRotateCCW->setText(QCoreApplication::translate("MainWindow", "RotateCCW", nullptr));
        actionLoadHashTagListProperty->setText(QCoreApplication::translate("MainWindow", "Property", nullptr));
        actionImportFiles->setText(QCoreApplication::translate("MainWindow", "ImportFiles", nullptr));
        groupBoxControl->setTitle(QCoreApplication::translate("MainWindow", "Navigation", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonBegin->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButtonBegin->setText(QCoreApplication::translate("MainWindow", "|<", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonNext->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButtonNext->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonPrevious->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButtonPrevious->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonEnd->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButtonEnd->setText(QCoreApplication::translate("MainWindow", ">|", nullptr));
        labelSuggestListCaption->setText(QCoreApplication::translate("MainWindow", "Suggest tags", nullptr));
        labelIncomingListCaption->setText(QCoreApplication::translate("MainWindow", "Incoming tag", nullptr));
        groupBoxEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        pushButtonLoad->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonMemo->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButtonMemo->setText(QCoreApplication::translate("MainWindow", "M", nullptr));
        groupBoxRotate->setTitle(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonRotateCCW->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButtonRotateCCW->setText(QCoreApplication::translate("MainWindow", "Rotate CCW", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxAngle->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        pushButtonRotateCW->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButtonRotateCW->setText(QCoreApplication::translate("MainWindow", "Rotate CW", nullptr));
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
