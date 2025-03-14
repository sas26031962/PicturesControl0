#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->actionViewPicture, SIGNAL(triggered()), this, SLOT( execActionFormViewPicture()));
    connect(ui->actionSelectImageBegin, SIGNAL(triggered()), this, SLOT( execActionSelectImageBegin()));
    connect(ui->actionSelectImageNext, SIGNAL(triggered()), this, SLOT( execActionSelectImageNext()));
    connect(ui->actionSelectImagePrevious, SIGNAL(triggered()), this, SLOT( execActionSelectImagePrevious()));
    connect(ui->actionSelectImageEnd, SIGNAL(triggered()), this, SLOT( execActionSelectImageEnd()));

    connect(ui->pushButtonBegin, SIGNAL(pressed()), this, SLOT( execActionSelectImageBegin()));
    connect(ui->pushButtonNext, SIGNAL(pressed()), this, SLOT( execActionSelectImageNext()));
    connect(ui->pushButtonPrevious, SIGNAL(pressed()), this, SLOT( execActionSelectImagePrevious()));
    connect(ui->pushButtonEnd, SIGNAL(pressed()), this, SLOT( execActionSelectImageEnd()));
    connect(ui->pushButtonLoad, SIGNAL(pressed()), this, SLOT( execActionLoad()));

    connect(ui->actionImport, SIGNAL(triggered()), this, SLOT( execActionImport()));
    connect(ui->actionLoad, SIGNAL(triggered()), this, SLOT( execActionLoad()));
    connect(ui->actionLoaadHashTagListSubject, SIGNAL(triggered()), this, SLOT( execActionLoadHashTagListSubject()));
    connect(ui->actionLoadHashTagListPlace, SIGNAL(triggered()), this, SLOT( execActionLoadHashTagListPlace()));

    ViewPicture = new fmView(this);
    ViewPicture->setWindowFlags(Qt::Window);//3 flags
    //ViewPicture->setWindowFlags(Qt::Drawer);//1 flag
    //ViewPicture->setWindowFlags(Qt::Sheet);//1 flag + ?
    //ViewPicture->setWindowFlags(Qt::Dialog);//1 flag + ?
    //ViewPicture->setWindowFlags(Qt::Popup);//no flags, immobil
    //ViewPicture->setWindowFlags(Qt::Tool);//1 flag, immobil
    //ViewPicture->setWindowFlags(Qt::ToolTip);//no flags, immobil
    //ViewPicture->setWindowFlags(Qt::SplashScreen);//no flags, immobil

    /*
    int windowX = this->x();
    windowX = windowX + this->width();
    windowX = windowX + WINDOW_MARGING;

    int windowY = this->y();

    int windowWidth = ViewPicture->width();
    int windowHeight = ViewPicture->height();

    QRect windowPlace = QRect(windowX, windowY, windowWidth, windowHeight);
    ViewPicture->setGeometry(windowPlace);
    */

    connect(this, SIGNAL(draw(QString)), ViewPicture, SLOT( execDraw(QString)));

    ui->actionViewPicture->setChecked(false);
    //ViewPicture->show();

    //this->setFocus();
    //this->raise();
    //this->activateWindow();
    //this->show();

    //---Создание рабочего списка
    std::unique_ptr<QList<cRecord> > ptrRecordList(new QList<cRecord>());
    cRecord::RecordList = ptrRecordList.get();

    progressBarProcess = new QProgressBar();
    progressBarProcess->setOrientation(Qt::Horizontal);
    progressBarProcess->setRange(0, 100);
    ui->statusBar->addWidget(progressBarProcess);

    labelExecStatus = new QLabel("ExecStatus");
    ui->statusBar->addWidget(labelExecStatus);

    labelFileName = new QLabel("LoadedFileName");
    ui->statusBar->addWidget(labelFileName);

    std::unique_ptr<QStringList> ptrHashTagList(new QStringList());
    qslHashTagList = ptrHashTagList.get();

    if(loadHashTagListSubject())
    {
        ui->listWidgetSuggest->clear();
        //ui->listWidgetSuggest->setSelectionMode(QAbstractItemView::MultiSelection);
        ui->listWidgetSuggest->addItems(*qslHashTagList);

        connect(ui->listWidgetSuggest, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(execListWidgetSuggestItemClicked()));
    }

    //ui->labelMain->setText("Exec 'Load' option for get file name list");

    //execActionLoad();

    //execActionSelectImageBegin();

}//End of ctor

MainWindow::~MainWindow()
{
    delete progressBarProcess;
    delete labelExecStatus;
    delete labelFileName;

    delete ViewPicture;

    delete ui;
}

void MainWindow::showCurrentIndexPicture()
{

    // Читаем значения из INI-файла
    QString qsGroupName = Groups.at(CurrentIndex);
    cIniFile::settings.beginGroup(qsGroupName);

    QString qsPath, qsName, qsError;

    QStringList keys = cIniFile::settings.childKeys();
    int iStrings = keys.count();

    QStandardItemModel * model= new QStandardItemModel(iStrings, 2);
    QListIterator<QString> readIt(keys);
    int iIndex = 0;
    while(readIt.hasNext())
    {
        QString key = readIt.next();
        QString value = cIniFile::settings.value(key,"0").toString();

        if(key == "path") qsPath = value;
        if(key == "name") qsName = value;
        if(key == "Eror") qsError = value;

        model->setItem(iIndex, 0, new QStandardItem(key));
        model->setItem(iIndex, 1, new QStandardItem(value));
        iIndex++;
        //qDebug() << "iterator:" << key << " index:" << iIndex;
    }
    model->setHeaderData(0, Qt::Horizontal, "Key");
    model->setHeaderData(1,Qt::Horizontal,"Value");
    ui->tableViewCurrent->setModel(model);

    cIniFile::settings.endGroup();

    QString imagePath = qsPath + '/' + qsName;

    if(qsError == "true")
    {
        qDebug() << "FullPath: " << imagePath << " Error:" << qsError;
        //ui->labelMain->setText(imagePath);
        return;
    }
    else
    {
        emit draw(imagePath);
    }
      labelFileName->setText(qsName);

      //Сохранение текущего индекса
      cIniFile::settings.beginGroup("RecordList");
      cIniFile::settings.setValue("index", CurrentIndex);
      cIniFile::settings.endGroup();

      qDebug() << "Store CurrentIndex:" << CurrentIndex;
}

void MainWindow::execActionSelectImageBegin()
{
    // Модификация индекса
    CurrentIndex = 0;
    progressBarProcess->setValue(CurrentIndex);

    // Отобразить картинку
    showCurrentIndexPicture();

    //---
    QString s = "execActionSelectImageBegin(), goto index:";
    s += QString::number(CurrentIndex);
    labelExecStatus->setText(s);
    //---

}//End of void MainWindow::execActionSelectImageBegin()

void MainWindow::execActionSelectImageNext()
{
    if(CurrentIndex < Groups.count() - 1) CurrentIndex++;
    progressBarProcess->setValue(CurrentIndex);

    // Отобразить картинку
    showCurrentIndexPicture();

    //---
    QString s = "execActionSelectImageNext(), goto index:";
    s += QString::number(CurrentIndex);
    labelExecStatus->setText(s);
    //---

}

void MainWindow::execActionSelectImagePrevious()
{
    if(CurrentIndex > 0) CurrentIndex--;
    progressBarProcess->setValue(CurrentIndex);

    // Отобразить картинку
    showCurrentIndexPicture();

    //---
    QString s = "execActionSelectImagePrevious(), goto index:";
    s += QString::number(CurrentIndex);
    labelExecStatus->setText(s);
    //---

}

void MainWindow::execActionSelectImageEnd()
{
    CurrentIndex = Groups.count() - 1;
    progressBarProcess->setValue(CurrentIndex);

    // Отобразить картинку
    showCurrentIndexPicture();

    //---
    QString s = "execActionSelectImageEnd(), goto index";
    s += QString::number(CurrentIndex);
    labelExecStatus->setText(s);
    //---

}

void MainWindow::execActionImport()
{
    //---
    QString s = "execActionImport()";
    labelExecStatus->setText(s);
    //---

    //---Создание рабочего списка
    std::unique_ptr<QList<cRecord> > ptrRecordList(new QList<cRecord>());
    cRecord::RecordList = ptrRecordList.get();

    //---Очистка рабочего списка
    cRecord::RecordList->clear();

    //---Чтение содержимого каталога ---

    if(cRecord::readDirectory(cIniFile::IniFile.getDirectoryPah()) > 0)
    {
        //qDebug() << "Directory not found: " << directoryPath;
        IsError = true;
        return;
    }

    //---Отображение даных
    //cRecord::showList();

    //---Добавление идентификационной секции
    cIniFile::IniFile.addInitalSection(cRecord::RecordList->count());
    progressBarProcess->setRange(0, cRecord::RecordList->count());

    //---Добавление данных в файл конфигурации
    //cIniFile::IniFile.addRecordListData();

    for(QList<cRecord>::iterator it = cRecord::RecordList->begin(); it != cRecord::RecordList->end(); ++it)
     {
        cIniFile::IniFile.Id++;//Счётчик записей

        progressBarProcess->setValue(cIniFile::IniFile.Id);

        const cRecord rec = *it;

        QString name = rec.qsName;
        int iDotPosition = name.indexOf('.');
        QString groupName = name.mid(0, iDotPosition);

        QString path = rec.qsPath;
        int iNamePosition = path.indexOf(name);
        QString PathWithoutName = path.mid(0, iNamePosition - 1);

        int size = rec.iSize;

        int iExtensionPosition = path.indexOf('.');
        QString qsExtension = path.mid(iExtensionPosition + 1);

        bool IsError = false;
        int width = 0;
        int height = 0;

        if(qsExtension.toLower() == "mp4")
        {
            qDebug() << "Id=" << cIniFile::IniFile.Id << "Extension: mp4";
            IsError = true;
        }
        else
        {
            //Фрагмент для обработки файлов изображений
            QImage image(path);//name
            if(image.isNull())
            {
                IsError = true;
            }
            else
            {
                width = image.width();
                height = image.height();
            }
        }

            cIniFile::settings.beginGroup(groupName);
            cIniFile::settings.setValue("Id", cIniFile::IniFile.Id);
            cIniFile::settings.setValue("name", name);
            cIniFile::settings.setValue("path", PathWithoutName);
            cIniFile::settings.setValue("size", size);
            if(IsError)
            {
                cIniFile::settings.setValue("error", true);
            }
            else
            {
                cIniFile::settings.setValue("width", width);
                cIniFile::settings.setValue("height", height);
            }
            cIniFile::settings.endGroup();

    }//End of for(QList<cRecord>::iterator it = cRecord::RecordList->begin(); it != cRecord::RecordList->end(); ++it)

    //qDebug() << "==================Task is done!!!=========================";
    labelExecStatus->setText("File import complete!");

    execActionLoad();//Выполнить загрузку изображений

}//End of void MainWindow::execActionImport()

void MainWindow::execActionLoad()
{
    // Создаем объект QSettings с указанием формата INI и пути к файлу
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);

    std::unique_ptr<bool> ptrOk = std::make_unique<bool>(true);
    bool* Ok = ptrOk.get();

    // Читаем значения из INI-файла
    settings.beginGroup("RecordList");

    QString qsCurrentIndex = settings.value("index", "0").toString();
    CurrentIndex = qsCurrentIndex.toInt(Ok);
    if(!*Ok)CurrentIndex = 0;

    qDebug() << "Load CurrentIndex:" << CurrentIndex;

    QString qsLength = settings.value("length", "0").toString();
    int iLength = qsLength.toInt(Ok);
    if(!*Ok)iLength = 0;
    settings.endGroup();

    Groups = settings.childGroups();

    // Выводим значения
    qDebug() << "length: " << iLength;
    qDebug() << "childGroupsList length: " << Groups.count();
    qDebug() << "----------------------------";
    progressBarProcess->setRange(0, Groups.count());
    int iCount = 0;
    int iProgress = 0;
    QListIterator<QString> readIt(Groups);
    while (readIt.hasNext())
    {
        iProgress++;
        progressBarProcess->setValue(iProgress);

        QString qsSection = readIt.next();
        //qDebug() << qsSection;
        settings.beginGroup(qsSection);
        QString qsPath = settings.value("path","noName").toString();
        QString qsName = settings.value("name", "noName").toString();
        QString qsId = settings.value("Id","0").toString();
        QString qsError = settings.value("Error", "false").toString();
        //int Error = qsError.toInt(Ok);

        int Id = qsId.toInt(Ok);
        if(!*Ok) Id = 0;

        //qDebug() << "Id=" << Id << "Error=" << qsError;

        if(qsName.indexOf(' ') >= 0)
        {
            iCount++;
            //qDebug() << "Section=" <<qsSection << "Id=" << Id << "Name=" <<qsName << " Path=" << qsPath << " iCount=" << iCount;
            QString s = qsPath;
            s += '/';
            s += qsName;
            qDebug() << "Id=" << Id << "Name=" << s << " iCount=" << iCount;
        }

        settings.endGroup();
    }
    if(iCount > 0)
        qDebug() << "Space character in file name detected in " << iCount << " files";
    else
        qDebug() << "No errors in file names detected, Ok!";

    execActionSelectImageNext();

    //---
    QString s = "execActionLoad(), goto index:";
    s += QString::number(CurrentIndex);
    labelExecStatus->setText(s);
    //---

}//End of void MainWindow::execActionLoad()


void MainWindow::execActionFormViewPicture()
{
    if(ui->actionViewPicture->isChecked())
    {
        ViewPicture->show();
    }
    else
    {
        ViewPicture->hide();
    }
    //---
    QString s = "execActionFormViewPicture()";
    labelExecStatus->setText(s);
    //---
}

void MainWindow::execListWidgetSuggestItemClicked()
{
    QString s = "execInsertNewKeyValue()";
    QString item = ui->listWidgetSuggest->currentItem()->text();
    qDebug() << "listWidgetSuggest: item=" << item;

    // Сохранение параметра в INI-файле
    if(Groups.count() > 0)
    {
        QString qsGroupName = Groups.at(CurrentIndex);
        cIniFile::settings.beginGroup(qsGroupName);
        cIniFile::settings.setValue(item, "true");
        cIniFile::settings.endGroup();

    }
    else
    {
        s = "List is empty, exec Load function!!!";
    }
    // Отобразить картинку
    showCurrentIndexPicture();
    //---
    labelExecStatus->setText(s);
    //---
}

bool MainWindow::loadHashTagListSubject()
{

#ifdef HOME_STORAGE
    filePathSubject = "/home/andy/MyQtProjects/PicturesControl0/programm/data/HashTagListPhotos.txt";
    qDebug() << "HOME_STORAGE";
#else
    filePathSubject = "C:/WORK/PicturesControl0/programm/data/HashTagListShips.txt";
    qDebug() << "WORK_STORAGE";
#endif

    QFile file(filePathSubject);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Error: Could not open file: " << filePathSubject;
        return false;
    }

    QTextStream in(&file);
#ifndef HOME_STORAGE
    in.setCodec("Windows-1251");
#endif

    while (!in.atEnd()) {
        QString line = in.readLine();
        qslHashTagList->append(line);
    }

    file.close();

    return true;
}

void MainWindow::execActionLoadHashTagListSubject()
{
    QString s = "ActionLoadHashTagListSubject()";
    if(loadHashTagListSubject())
    {
        ui->listWidgetSuggest->clear();
        ui->listWidgetSuggest->addItems(*qslHashTagList);

//        connect(ui->listWidgetSuggest, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(execListWidgetSuggestItemClicked()));
    }
    else
    {
        ui->listWidgetSuggest->clear();
    }
    //---
    labelExecStatus->setText(s);
    //---

}

void MainWindow::execActionLoadHashTagListPlace()
{
    QString s = "ActionLoadHashTagListPlace()";

    //---
    labelExecStatus->setText(s);
    //---

}
