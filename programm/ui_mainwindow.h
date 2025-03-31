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
    QAction *actionRotateCW_2;
    QAction *actionRotateCCW_2;
    QAction *actionRemoveText;
    QAction *actionRemoveTif;
    QAction *actionGetGroupsList;
    QAction *actionLoadHashTagListTheame;
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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(481, 583);
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
        actionRotateCW = new QAction(MainWindow);
        actionRotateCW->setObjectName(QStringLiteral("actionRotateCW"));
        actionRotateCCW = new QAction(MainWindow);
        actionRotateCCW->setObjectName(QStringLiteral("actionRotateCCW"));
        actionLoadHashTagListProperty = new QAction(MainWindow);
        actionLoadHashTagListProperty->setObjectName(QStringLiteral("actionLoadHashTagListProperty"));
        actionImportFiles = new QAction(MainWindow);
        actionImportFiles->setObjectName(QStringLiteral("actionImportFiles"));
        actionRotateCW_2 = new QAction(MainWindow);
        actionRotateCW_2->setObjectName(QStringLiteral("actionRotateCW_2"));
        actionRotateCCW_2 = new QAction(MainWindow);
        actionRotateCCW_2->setObjectName(QStringLiteral("actionRotateCCW_2"));
        actionRemoveText = new QAction(MainWindow);
        actionRemoveText->setObjectName(QStringLiteral("actionRemoveText"));
        actionRemoveTif = new QAction(MainWindow);
        actionRemoveTif->setObjectName(QStringLiteral("actionRemoveTif"));
        actionGetGroupsList = new QAction(MainWindow);
        actionGetGroupsList->setObjectName(QStringLiteral("actionGetGroupsList"));
        actionLoadHashTagListTheame = new QAction(MainWindow);
        actionLoadHashTagListTheame->setObjectName(QStringLiteral("actionLoadHashTagListTheame"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBoxControl = new QGroupBox(centralWidget);
        groupBoxControl->setObjectName(QStringLiteral("groupBoxControl"));
        groupBoxControl->setGeometry(QRect(10, 380, 191, 51));
        pushButtonBegin = new QPushButton(groupBoxControl);
        pushButtonBegin->setObjectName(QStringLiteral("pushButtonBegin"));
        pushButtonBegin->setGeometry(QRect(20, 20, 23, 23));
        pushButtonNext = new QPushButton(groupBoxControl);
        pushButtonNext->setObjectName(QStringLiteral("pushButtonNext"));
        pushButtonNext->setGeometry(QRect(80, 20, 23, 23));
        pushButtonPrevious = new QPushButton(groupBoxControl);
        pushButtonPrevious->setObjectName(QStringLiteral("pushButtonPrevious"));
        pushButtonPrevious->setGeometry(QRect(50, 20, 23, 23));
        pushButtonEnd = new QPushButton(groupBoxControl);
        pushButtonEnd->setObjectName(QStringLiteral("pushButtonEnd"));
        pushButtonEnd->setGeometry(QRect(110, 20, 23, 23));
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
        groupBoxEdit = new QGroupBox(centralWidget);
        groupBoxEdit->setObjectName(QStringLiteral("groupBoxEdit"));
        groupBoxEdit->setGeometry(QRect(20, 430, 451, 51));
        pushButtonLoad = new QPushButton(groupBoxEdit);
        pushButtonLoad->setObjectName(QStringLiteral("pushButtonLoad"));
        pushButtonLoad->setGeometry(QRect(10, 20, 75, 23));
        lineEditMemo = new QLineEdit(groupBoxEdit);
        lineEditMemo->setObjectName(QStringLiteral("lineEditMemo"));
        lineEditMemo->setGeometry(QRect(90, 20, 301, 23));
        pushButtonMemo = new QPushButton(groupBoxEdit);
        pushButtonMemo->setObjectName(QStringLiteral("pushButtonMemo"));
        pushButtonMemo->setGeometry(QRect(400, 20, 31, 23));
        groupBoxRotate = new QGroupBox(centralWidget);
        groupBoxRotate->setObjectName(QStringLiteral("groupBoxRotate"));
        groupBoxRotate->setGeometry(QRect(210, 380, 261, 51));
        pushButtonRotateCCW = new QPushButton(groupBoxRotate);
        pushButtonRotateCCW->setObjectName(QStringLiteral("pushButtonRotateCCW"));
        pushButtonRotateCCW->setGeometry(QRect(93, 20, 75, 23));
        spinBoxAngle = new QSpinBox(groupBoxRotate);
        spinBoxAngle->setObjectName(QStringLiteral("spinBoxAngle"));
        spinBoxAngle->setGeometry(QRect(183, 20, 51, 22));
        spinBoxAngle->setMinimum(-90);
        spinBoxAngle->setMaximum(90);
        pushButtonRotateCW = new QPushButton(groupBoxRotate);
        pushButtonRotateCW->setObjectName(QStringLiteral("pushButtonRotateCW"));
        pushButtonRotateCW->setGeometry(QRect(10, 20, 75, 23));
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
        menuFile->addAction(actionRemoveText);
        menuFile->addAction(actionRemoveTif);
        menuFile->addAction(actionGetGroupsList);
        menuFile->addAction(actionExit);
        menuSelect_image->addAction(actionSelectImageBegin);
        menuSelect_image->addAction(actionSelectImageNext);
        menuSelect_image->addAction(actionSelectImagePrevious);
        menuSelect_image->addAction(actionSelectImageEnd);
        menuSelect_image->addAction(actionRotateCW_2);
        menuSelect_image->addAction(actionRotateCCW_2);
        menuForms->addAction(actionViewPicture);
        menuTags->addAction(actionLoaadHashTagListSubject);
        menuTags->addAction(actionLoadHashTagListPlace);
        menuTags->addAction(actionLoadHashTagListProperty);
        menuTags->addAction(actionLoadHashTagListTheame);

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
        actionRotateCW->setText(QApplication::translate("MainWindow", "RotateCW", 0));
        actionRotateCCW->setText(QApplication::translate("MainWindow", "RotateCCW", 0));
        actionLoadHashTagListProperty->setText(QApplication::translate("MainWindow", "Property", 0));
        actionImportFiles->setText(QApplication::translate("MainWindow", "ImportFiles", 0));
        actionRotateCW_2->setText(QApplication::translate("MainWindow", "RotateCW", 0));
        actionRotateCCW_2->setText(QApplication::translate("MainWindow", "RotateCCW", 0));
        actionRemoveText->setText(QApplication::translate("MainWindow", "RemoveText", 0));
        actionRemoveTif->setText(QApplication::translate("MainWindow", "RemoveTif", 0));
        actionGetGroupsList->setText(QApplication::translate("MainWindow", "GetGroupsList", 0));
        actionLoadHashTagListTheame->setText(QApplication::translate("MainWindow", "Theame", 0));
        groupBoxControl->setTitle(QApplication::translate("MainWindow", "Navigation", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonBegin->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButtonBegin->setText(QApplication::translate("MainWindow", "|<", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonNext->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButtonNext->setText(QApplication::translate("MainWindow", ">", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonPrevious->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButtonPrevious->setText(QApplication::translate("MainWindow", "<", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonEnd->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButtonEnd->setText(QApplication::translate("MainWindow", ">|", 0));
        labelSuggestListCaption->setText(QApplication::translate("MainWindow", "Suggest tags", 0));
        labelIncomingListCaption->setText(QApplication::translate("MainWindow", "Incoming tag", 0));
        groupBoxEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        pushButtonLoad->setText(QApplication::translate("MainWindow", "Load", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonMemo->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButtonMemo->setText(QApplication::translate("MainWindow", "M", 0));
        groupBoxRotate->setTitle(QApplication::translate("MainWindow", "Rotate", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonRotateCCW->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButtonRotateCCW->setText(QApplication::translate("MainWindow", "Rotate CCW", 0));
#ifndef QT_NO_TOOLTIP
        spinBoxAngle->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pushButtonRotateCW->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButtonRotateCW->setText(QApplication::translate("MainWindow", "Rotate CW", 0));
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
