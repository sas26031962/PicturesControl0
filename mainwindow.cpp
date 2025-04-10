#include "mainwindow.h"
#include "ui_mainwindow.h"

//-----------------------------------------------------------------------------
//Глобальные переменные
//-----------------------------------------------------------------------------

std::atomic<int> iCurrentIndexGlobal(0); //Индекс для отображения


//-----------------------------------------------------------------------------
//Реализации элементов класса
//-----------------------------------------------------------------------------

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    cIniFile::Groups = new QStringList();

    qslDeletedSections.clear();

    ui->setupUi(this);

    progressBarNavigation = ui->progressBarNavigation;
    SpinBoxIndex = ui->spinBoxIndex;

    ui->pushButtonGotoIndex->setVisible(false);//РЕЖИМ АДМИНИСТРАТОРА
    ui->pushButtonLoad->setVisible(false);//РЕЖИМ АДМИНИСТРАТОРА

    connect(ui->actionViewPicture, SIGNAL(triggered()), this, SLOT( execActionFormViewPicture()));
    connect(ui->actionGotoIndex, SIGNAL(triggered()), this, SLOT( execActionGotoIndex()));
    connect(ui->actionSelectImageBegin, SIGNAL(triggered()), this, SLOT( execActionSelectImageBegin()));
    connect(ui->actionSelectImageNext, SIGNAL(triggered()), this, SLOT( execActionSelectImageNext()));
    connect(ui->actionSelectImagePrevious, SIGNAL(triggered()), this, SLOT( execActionSelectImagePrevious()));
    connect(ui->actionSelectImageEnd, SIGNAL(triggered()), this, SLOT( execActionSelectImageEnd()));

    connect(ui->actionRemoveMovie, SIGNAL(triggered()), this, SLOT( execActionRemoveMovie()));
    connect(ui->actionRemoveText, SIGNAL(triggered()), this, SLOT( execActionRemoveText()));
    connect(ui->actionRemoveTif, SIGNAL(triggered()), this, SLOT( execActionRemoveTif()));
    connect(ui->actionRemoveSection, SIGNAL(triggered()), this, SLOT( execActionRemoveSection()));

    connect(ui->actionRotateCW_2, SIGNAL(triggered()), this, SLOT( execActionRotateCW()));
    connect(ui->actionRotateCCW_2, SIGNAL(triggered()), this, SLOT( execActionRotateCCW()));
    connect(ui->actionRotateCW, SIGNAL(triggered()), this, SLOT( execActionRotateCW()));
    connect(ui->actionRotateCCW, SIGNAL(triggered()), this, SLOT( execActionRotateCCW()));

    connect(ui->pushButtonGotoIndex, SIGNAL(pressed()), this, SLOT( execActionGotoIndex()));

    connect(ui->pushButtonBegin, SIGNAL(pressed()), this, SLOT( execActionSelectImageBegin()));
    connect(ui->pushButtonNext, SIGNAL(pressed()), this, SLOT( execActionSelectImageNext()));
    connect(ui->pushButtonPrevious, SIGNAL(pressed()), this, SLOT( execActionSelectImagePrevious()));
    connect(ui->pushButtonEnd, SIGNAL(pressed()), this, SLOT( execActionSelectImageEnd()));
    connect(ui->pushButtonLoad, SIGNAL(pressed()), this, SLOT( execActionLoad()));
    connect(ui->pushButtonRotateCW, SIGNAL(pressed()), this, SLOT( execActionRotateCW()));
    connect(ui->pushButtonRotateCCW, SIGNAL(pressed()), this, SLOT( execActionRotateCCW()));
    connect(ui->pushButtonMemo, SIGNAL(pressed()), this, SLOT( execActionMemo()));
    connect(ui->spinBoxAngle, SIGNAL(valueChanged(int)), this, SLOT( execSpinBoxAngle(int)));

    connect(ui->actionImport, SIGNAL(triggered()), this, SLOT( execActionImportInitial()));

    connect(ui->actionGetGroupsList, SIGNAL(triggered()), this, SLOT( execActionGetGroupsList()));

    connect(ui->actionLoad, SIGNAL(triggered()), this, SLOT( execActionLoad()));
    //---Для удаления
    connect(ui->actionLoaadHashTagListSubject, SIGNAL(triggered()), this, SLOT( execActionLoadHashTagListSubject()));
    connect(ui->actionLoadHashTagListPlace, SIGNAL(triggered()), this, SLOT( execActionLoadHashTagListPlace()));
    connect(ui->actionLoadHashTagListProperty, SIGNAL(triggered()), this, SLOT( execActionLoadHashTagListProperty()));
    connect(ui->actionLoadHashTagListTheame, SIGNAL(triggered()), this, SLOT( execActionLoadHashTagListTheame()));
    //---

    connect(this, SIGNAL(showExecStatus(QString)), this, SLOT( execShowExecStatus(QString)));

    fmViewPicture = new fmView(this);
    fmViewPicture->setWindowFlags(Qt::Window);//3 flags
    //ViewPicture->setWindowFlags(Qt::Drawer);//1 flag
    //ViewPicture->setWindowFlags(Qt::Sheet);//1 flag + ?
    //ViewPicture->setWindowFlags(Qt::Dialog);//1 flag + ?
    //ViewPicture->setWindowFlags(Qt::Popup);//no flags, immobil
    //ViewPicture->setWindowFlags(Qt::Tool);//1 flag, immobil
    //ViewPicture->setWindowFlags(Qt::ToolTip);//no flags, immobil
    //ViewPicture->setWindowFlags(Qt::SplashScreen);//no flags, immobil

    connect(this, SIGNAL(draw(QString)), fmViewPicture, SLOT( execDraw(QString)));
    connect(fmViewPicture, SIGNAL(showExecStatus(QString)), this, SLOT( execShowExecStatus(QString)));

    ui->actionViewPicture->setChecked(false);
    //---Создание рабочего списка
    std::unique_ptr<QList<cRecord> > ptrRecordList(new QList<cRecord>());
    cRecord::RecordList = ptrRecordList.get();

    timerUpdate = new QTimer(this);
    connect(timerUpdate, SIGNAL(timeout()), this, SLOT( execTimerUpdate()));
    timerUpdate->start(100);

    labelRotator = new QLabel("|");
    ui->statusBar->addWidget(labelRotator);

    progressBarProcess = new QProgressBar();
    progressBarProcess->setOrientation(Qt::Horizontal);
    progressBarProcess->setRange(0, cImportFiles::MaxIndexValue);
    ui->statusBar->addWidget(progressBarProcess);

    labelExecStatus = new QLabel("ExecStatus");
    ui->statusBar->addWidget(labelExecStatus);

    labelFileName = new QLabel("LoadedFileName");
    ui->statusBar->addWidget(labelFileName);

    //std::unique_ptr<QStringList> ptrHashTagList(new QStringList());
    //qslHashTagList = ptrHashTagList.get();
    qslHashTagList = new QStringList();

    //Загрузка списка хеш-тегов Subject
    if(loadHashTagListSubject())
    {
        ui->listWidgetSubject->clear();
        ui->listWidgetSubject->addItems(*qslHashTagList);

        connect(ui->listWidgetSubject, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(execListWidgetSubjectItemClicked()));
    }

    //Загрузка списка хеш-тегов Propertyes
    if(loadHashTagListProperty())
    {
        ui->listWidgetPropertyes->clear();
        ui->listWidgetPropertyes->addItems(*qslHashTagList);

        connect(ui->listWidgetPropertyes, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(execListWidgetPropertyItemClicked()));
    }

    //Загрузка списка хеш-тегов Places
    if(loadHashTagListPlace())
    {
        ui->listWidgetPlaces->clear();
        ui->listWidgetPlaces->addItems(*qslHashTagList);

        connect(ui->listWidgetPlaces, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(execListWidgetPlaceItemClicked()));
    }

    //Загрузка списка хеш-тегов Theams
    if(loadHashTagListTheame())
    {
        ui->listWidgetTheams->clear();
        ui->listWidgetTheams->addItems(*qslHashTagList);

        connect(ui->listWidgetTheams, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(execListWidgetTheameItemClicked()));
    }

    //ui->labelMain->setText("Exec 'Load' option for get file name list");

    //execActionLoad();

    //execActionSelectImageBegin();

}//End of ctor

MainWindow::~MainWindow()
{
    cIniFile::settings.sync();
    timerUpdate->stop();

    saveRemovedSectionsList();

    delete progressBarProcess;
    delete labelExecStatus;
    delete labelFileName;
    delete labelRotator;

    delete fmViewPicture;

    delete qslHashTagList;

    if(cIniFile::Groups != nullptr) delete cIniFile::Groups;

    delete ui;
}

//=============================================================================

void MainWindow::keyPressEvent(QKeyEvent * e)
{
    switch(e->key())
    {
        case 16777249://Qt::CTRL:
            qDebug() << "CTRL pressed";
            KeyPressed.push(e->key());
        break;
        //Key_B
        case 1048:
        case 66:
            qDebug() << "B pressed";
            KeyPressed.push(e->key());
            if(KeyPressed.Previous == 16777249)
            {
                qDebug() << "CTRL+B pressed";
                emit ui->actionSelectImageBegin->triggered();// pushButtonBegin->pressed();
            }
        break;
        //Key_P
        case 1047:
        case 80:
            qDebug() << "P pressed";
            KeyPressed.push(e->key());
            if(KeyPressed.Previous == 16777249)
            {
                qDebug() << "CTRL+P pressed";
                emit ui->actionSelectImagePrevious->triggered();// pushButtonPrevious->pressed();
            }
        break;

        //Key_N
        case 1058:
        case 78:
            qDebug() << "N pressed";
            KeyPressed.push(e->key());
            if(KeyPressed.Previous == 16777249)
            {
                qDebug() << "CTRL+N pressed";
                emit ui->actionSelectImageNext->triggered();// pushButtonNext->pressed();
            }
        break;

        //Key_E
        case 1059:
        case 69:
            qDebug() << "E pressed";
            KeyPressed.push(e->key());
            if(KeyPressed.Previous == 16777249)
            {
                qDebug() << "CTRL+E pressed";
                emit ui->actionSelectImageEnd->triggered();// pushButtonEnd->pressed();
            }
        break;

       //Key_D
       case 1042:
       case 68:
            qDebug() << "D pressed";
            KeyPressed.push(e->key());
            if(KeyPressed.Previous == 16777249)
            {
                qDebug() << "CTRL+D pressed";
                emit ui->actionRemoveSection->triggered();// pushButtonEnd->pressed();
            }
            break;

        default:
            qDebug() << "Key press:" << e->key();
        break;
    }

}//End of void MainWindow::keyPressEvent(QKeyEvent * e)

//=============================================================================

void MainWindow::showCurrentIndexPicture()
{

    // Читаем значения из INI-файла
    int index = iCurrentIndexGlobal.load(std::memory_order_relaxed);
    if(index > (cIniFile::Groups->count() - 1))
    {
        qDebug() << "Loaded index out of range:" << index << " goto head of list";

        index = 0;
        iCurrentIndexGlobal.store(index, std::memory_order_relaxed);
    }
    int iGroupsCount = cIniFile::Groups->count();
    if(iGroupsCount > 0)
    {
        QString qsGroupName = cIniFile::Groups->at(index);
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
        cImportFiles::labelFileNameText = qsName;
        cImportFiles::IslabelFileNameTextChanged = true;

        //Сохранение текущего индекса
        int x = iCurrentIndexGlobal.load(std::memory_order_relaxed);
        cIniFile::settings.beginGroup("RecordList");
        cIniFile::settings.setValue("index", x);
        cIniFile::settings.endGroup();
    }
    else
    {
        QString s = "Groups is empty!";
        emit showExecStatus(s);

        //execActionImportInitial();//!!!
    }

}

//=============================================================================

//
// Запись QStringList в файл
//
bool MainWindow::saveStringListToFile(const QString& fileName, const QStringList& list)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream out(&file);
    out.setCodec("UTF-8"); // Установка кодировки

    for (const QString& str : list) {
        out << str << "\n";
    }

    file.close();
    return true;
}


//=============================================================================

QStringList MainWindow::loadStringListFromFile(const QString& fileName)
{
    QStringList list;
    QFile file(fileName);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        in.setCodec("UTF-8");

        while (!in.atEnd()) {
            list << in.readLine();
        }

        file.close();
    }
    return list;
}

//=============================================================================

void MainWindow::loadRemovedSectionsList()
{
    QString  filePathRemovedSectionList;
    #ifdef HOME_STORAGE
        filePathRemovedSectionList = "/home/andy/MyQtProjects/PicturesControl0/programm/data/RemovedSectionListPhotos.txt";// Прямой путь к файлу
        qDebug() << "loadRemovedSectionsList():"  << "HOME_STORAGE";
    #else
        filePathRemovedSectionList = "C:/WORK/PicturesControl0/programm/data/RemovedSectionListShips.txt";// Прямой путь к файлу
        qDebug() << "loadRemovedSectionsList():" << "WORK_STORAGE";
    #endif

    qslDeletedSections = loadStringListFromFile(filePathRemovedSectionList);

    ui->listWidgetOther->clear();
    ui->listWidgetOther->addItems(qslDeletedSections);

}//End of void MainWindow::loadRemovedSectionsList()

//=============================================================================

void MainWindow::saveRemovedSectionsList()
{
    QString  filePathRemovedSectionList;
    #ifdef HOME_STORAGE
        filePathRemovedSectionList = "/home/andy/MyQtProjects/PicturesControl0/programm/data/RemovedSectionListPhotos.txt";// Прямой путь к файлу
        qDebug() << "saveRemovedSectionsList():"  << "HOME_STORAGE";
    #else
        filePathRemovedSectionList = "C:/WORK/PicturesControl0/programm/data/RemovedSectionListShips.txt";// Прямой путь к файлу
        qDebug() << "saveRemovedSectionsList():"  << "WORK_STORAGE";
    #endif

    saveStringListToFile(filePathRemovedSectionList, qslDeletedSections);

}//End of void MainWindow::saveRemovedSectionsList()

//=============================================================================
void MainWindow::execActionGotoIndex()
{

    int index = SpinBoxIndex->value();

    // Модификация индекса
    iCurrentIndexGlobal.store(index, std::memory_order_relaxed);

    // Отобразить картинку
    showCurrentIndexPicture();

    progressBarNavigation->setValue(index);

    //---
    QString s = "execActionGotoIndex(), goto index:";
    s += QString::number(index);
    emit execShowExecStatus(s);
    //---

}

//=============================================================================

void MainWindow::execActionSelectImageBegin()
{
    // Модификация индекса
    iCurrentIndexGlobal.store(0, std::memory_order_relaxed);

    // Отобразить картинку
    showCurrentIndexPicture();

    int index = iCurrentIndexGlobal.load(std::memory_order_relaxed);
    progressBarNavigation->setValue(index);
    SpinBoxIndex->setValue(index);
    //---
    QString s = "execActionSelectImageBegin(), goto index:";
    s += QString::number(iCurrentIndexGlobal.load(std::memory_order_relaxed));
    emit execShowExecStatus(s);
    //---

}//End of void MainWindow::execActionSelectImageBegin()

//=============================================================================

void MainWindow::execActionSelectImageNext()
{
    if(iCurrentIndexGlobal.load(std::memory_order_relaxed) < cIniFile::Groups->count() - 1)
    {
        iCurrentIndexGlobal.fetch_add(1, std::memory_order_relaxed);
    }

    // Отобразить картинку
    showCurrentIndexPicture();
    int index = iCurrentIndexGlobal.load(std::memory_order_relaxed);
    progressBarNavigation->setValue(index);
    SpinBoxIndex->setValue(index);
    //---
    QString s = "execActionSelectImageNext(), goto index:";
    s += QString::number(iCurrentIndexGlobal.load(std::memory_order_relaxed));
    emit execShowExecStatus(s);
    //---

}

//=============================================================================

void MainWindow::execActionSelectImagePrevious()
{
    if(iCurrentIndexGlobal.load(std::memory_order_relaxed) > 0)
    {
        iCurrentIndexGlobal.fetch_sub(1, std::memory_order_relaxed);
    }

    // Отобразить картинку
    showCurrentIndexPicture();

    int index = iCurrentIndexGlobal.load(std::memory_order_relaxed);
    progressBarNavigation->setValue(index);
    SpinBoxIndex->setValue(index);
    //---
    QString s = "execActionSelectImagePrevious(), goto index:";
    s += QString::number(iCurrentIndexGlobal.load(std::memory_order_relaxed));
    emit execShowExecStatus(s);
    //---

}

//=============================================================================

void MainWindow::execActionSelectImageEnd()
{
    iCurrentIndexGlobal.store(cIniFile::Groups->count() - 1);

    // Отобразить картинку
    showCurrentIndexPicture();

    int index = iCurrentIndexGlobal.load(std::memory_order_relaxed);
    progressBarNavigation->setValue(index);
    SpinBoxIndex->setValue(index);
    //---
    QString s = "execActionSelectImageEnd(), goto index";
    s += QString::number(iCurrentIndexGlobal.load(std::memory_order_relaxed));
    emit execShowExecStatus(s);
    //---

}

//=============================================================================

void MainWindow::execActionImportInitial()
{
    //---
    QString s = "execActionImport()";
    emit execShowExecStatus(s);
    //---

    //---Создание рабочего списка
    std::unique_ptr<QList<cRecord> > ptrRecordList(new QList<cRecord>());
    cRecord::RecordList = ptrRecordList.get();

    //--- Очистка рабочего списка
    cRecord::RecordList->clear();

    //---Чтение содержимого каталога ---

    if(cRecord::readDirectory(cIniFile::IniFile.getDirectoryPah()) > 0)
    {
        //qDebug() << "Directory not found: " << directoryPath;
        IsError = true;
        return;
    }

    //--- Импорт данных в конфигурационный файл ---

    cImportFiles::execImport(progressBarProcess);

    emit execShowExecStatus("File import complete!");

    qslDeletedSections.clear();

    ui->listWidgetOther->clear();
    ui->listWidgetOther->addItems(qslDeletedSections);

    //execActionLoad();//Выполнить загрузку изображений

}//End of void MainWindow::execActionImport()

//=============================================================================

void MainWindow::execActionLoad()
{
    // Создаем объект QSettings с указанием формата INI и пути к файлу
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);

    std::unique_ptr<bool> ptrOk = std::make_unique<bool>(true);
    bool* Ok = ptrOk.get();

    // Читаем значения из INI-файла
    settings.beginGroup("RecordList");

    QString qsCurrentIndex = settings.value("index", "0").toString();
    int LoadedCurrentIndex = qsCurrentIndex.toInt(Ok);
    if(!*Ok)LoadedCurrentIndex = 0;

    qDebug() << "Loaded CurrentIndex:" << LoadedCurrentIndex;

    QString qsLength = settings.value("length", "0").toString();
    int iLength = qsLength.toInt(Ok);
    if(!*Ok)iLength = 0;
    settings.endGroup();

    *cIniFile::Groups = settings.childGroups();

    // Выводим значения
    qDebug() << "length: " << iLength;
    qDebug() << "childGroupsList length: " << cIniFile::Groups->count();
    qDebug() << "----------------------------";
    cImportFiles::MaxIndexValue = cIniFile::Groups->count();
    progressBarProcess->setRange(0, cIniFile::Groups->count());
    int iCount = 0;
    iCurrentIndexGlobal.store(0);
    QListIterator<QString> readIt(*cIniFile::Groups);
    while (readIt.hasNext())
    {
        iCurrentIndexGlobal.fetch_add(1, std::memory_order_relaxed);

        //---Отображение состояния загрузки
        int x = iCurrentIndexGlobal.load(std::memory_order_relaxed);
        progressBarProcess->setValue(x);

        switch (x % 4)
        {
            case 0: labelRotator->setText("-"); break;
            case 1: labelRotator->setText("\\"); break;
            case 2: labelRotator->setText("|"); break;
            case 3: labelRotator->setText("/"); break;
            default:  break;
        }
        //---

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

    iCurrentIndexGlobal.store(LoadedCurrentIndex);

    //Установка навигации
    progressBarNavigation->setRange(0, cImportFiles::MaxIndexValue);
    progressBarNavigation->setValue(LoadedCurrentIndex);

    SpinBoxIndex->setRange(0, cImportFiles::MaxIndexValue);
    SpinBoxIndex->setValue(LoadedCurrentIndex);

    execActionSelectImageNext();

    //---
    QString s = "execActionLoad(), goto index:";
    s += QString::number(iCurrentIndexGlobal.load(std::memory_order_relaxed));
    emit execShowExecStatus(s);
    //---

}//End of void MainWindow::execActionLoad()

//=============================================================================

void MainWindow::execActionFormViewPicture()
{
    if(ui->actionViewPicture->isChecked())
    {
        fmViewPicture->show();
    }
    else
    {
        fmViewPicture->hide();
    }
    //---
    QString s = "execActionFormViewPicture()";
    emit execShowExecStatus(s);
   //---
}

//=============================================================================

bool MainWindow::loadHashTagListSubject()
{

#ifdef HOME_STORAGE
    filePathSubject = "/home/andy/MyQtProjects/PicturesControl0/programm/data/HashTagListSubjectPhotos.txt";// Прямой путь к файлу
    qDebug() << "HOME_STORAGE";
#else
    filePathSubject = "C:/WORK/PicturesControl0/programm/data/HashTagListSubjectShips.txt";// Прямой путь к файлу
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

    qslHashTagList->clear();

    while (!in.atEnd())
    {
        QString line = in.readLine();
        qslHashTagList->append(line);
    }

    file.close();
    qDebug() << "Load " << qslHashTagList->count() << " strings";
    return true;
}

//=============================================================================

bool MainWindow::loadHashTagListPlace()
{

#ifdef HOME_STORAGE
    filePathSubject = "/home/andy/MyQtProjects/PicturesControl0/programm/data/HashTagListPlacesPhotos.txt";//Прямой путь к файлу
    qDebug() << "HOME_STORAGE";
#else
    filePathSubject = "C:/WORK/PicturesControl0/programm/data/HashTagListPlacesShips.txt";//Прямой путь к файлу
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

    qslHashTagList->clear();

    while (!in.atEnd())
    {
        QString line = in.readLine();
        qslHashTagList->append(line);
    }

    file.close();
    qDebug() << "Load " << qslHashTagList->count() << " strings";
    return true;
}

//=============================================================================
bool MainWindow::loadHashTagListTheame()
{

#ifdef HOME_STORAGE
    filePathSubject = "/home/andy/MyQtProjects/PicturesControl0//programm/data/HashTagListTheamsPhotos.txt";// Путь прямой
    qDebug() << "HOME_STORAGE";
#else
    filePathSubject = "C:/WORK/PicturesControl0/programm/data/HashTagListTheamsShips.txt";// Путь прямой
    qDebug() << "WORK_STORAGE";
#endif

    QFile file(filePathSubject);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Error: Could not open file: " << filePathSubject;
        return false;
    }
    else
    {
        qDebug() << "File: " << filePathSubject << " is loaded!";
    }

    QTextStream in(&file);
#ifndef HOME_STORAGE
    in.setCodec("Windows-1251");
#endif

    qslHashTagList->clear();

    while (!in.atEnd())
    {
        QString line = in.readLine();
        qslHashTagList->append(line);
    }

    file.close();
    qDebug() << "Load " << qslHashTagList->count() << " strings";
    return true;

}

bool MainWindow::loadHashTagListProperty()
{

#ifdef HOME_STORAGE
    filePathSubject = "/home/andy/MyQtProjects/PicturesControl0//programm/data/HashTagListPropertyesPhotos.txt";// Путь прямой
    qDebug() << "HOME_STORAGE";
#else
    filePathSubject = "C:/WORK/PicturesControl0/programm/data/HashTagListPropertyesShips.txt";// Путь прямой
    qDebug() << "WORK_STORAGE";
#endif

    QFile file(filePathSubject);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Error: Could not open file: " << filePathSubject;
        return false;
    }
    else
    {
        qDebug() << "File: " << filePathSubject << " is loaded!";
    }

    QTextStream in(&file);
#ifndef HOME_STORAGE
    in.setCodec("Windows-1251");
#endif

    qslHashTagList->clear();

    while (!in.atEnd())
    {
        QString line = in.readLine();
        qslHashTagList->append(line);
    }

    file.close();
    qDebug() << "Load " << qslHashTagList->count() << " strings";
    return true;
}

//=============================================================================

void MainWindow::execActionLoadHashTagListSubject()
{
    QString s = "ActionLoadHashTagListSubject()";
    if(loadHashTagListSubject())
    {
        qDebug() << s << ": loadHashTagListSubject is sucsess";
        ui->listWidgetSubject->clear();
        ui->listWidgetSubject->addItems(*qslHashTagList);

    }
    else
    {
        ui->listWidgetSubject->clear();
        qDebug() << s << ": loadHashTagListSubject is broken!!!";
    }
    //---
    emit execShowExecStatus(s);
    //---

}

//=============================================================================

void MainWindow::execActionLoadHashTagListPlace()
{
    QString s = "ActionLoadHashTagListPlace()";

    if(loadHashTagListPlace())
    {
        qDebug() << s << ": loadHashTagListPlace is sucsess";
        ui->listWidgetPlaces->clear();
        ui->listWidgetPlaces->addItems(*qslHashTagList);

    }
    else
    {
        ui->listWidgetPlaces->clear();
        qDebug() << s << ": loadHashTagListPlace is broken!!!";
    }
    //---
    emit execShowExecStatus(s);
    //---

}

//=============================================================================

void MainWindow::execActionLoadHashTagListProperty()
{
    QString s = "ActionLoadHashTagListProperty()";

    if(loadHashTagListProperty())
    {
        qDebug() << s << ": loadHashTagListProperty is sucsess";
        ui->listWidgetPropertyes->clear();
        ui->listWidgetPropertyes->addItems(*qslHashTagList);

    }
    else
    {
        ui->listWidgetPropertyes->clear();
        qDebug() << s << ": loadHashTagListPrperty is broken!!!";
    }
    //---
    emit execShowExecStatus(s);
    //---

}

//=============================================================================

void MainWindow::execActionLoadHashTagListTheame()
{

    QString s = "ActionLoadHashTagListTheame()";

    if(loadHashTagListTheame())
    {
        qDebug() << s << ": loadHashTagListTheame is sucsess";
        ui->listWidgetTheams->clear();
        ui->listWidgetTheams->addItems(*qslHashTagList);

    }
    else
    {
        ui->listWidgetTheams->clear();
        qDebug() << s << ": loadHashTagListTheame is broken!!!";
    }
    //---
    emit execShowExecStatus(s);
    //---

}

//=============================================================================

//
// Удалить секцию из ini файла
//
bool MainWindow::deleteSection(QString s)
{
    bool Error = false;

    cIniFile::settings.beginGroup(s);
    QList<QString> keys = cIniFile::settings.childKeys();
    int iKeysCount = keys.count();

    QString qsName = cIniFile::settings.value("name", "noName").toString();
    QString qsPath = cIniFile::settings.value("path", "noPath").toString();
    QString qsWay = qsPath + "/" + qsName;

    if(iKeysCount > 0)
    {
        // Перебор всей ключей в секции
        QListIterator<QString> readKeyIt(keys);
        while (readKeyIt.hasNext())
        {
            QString qsKey = readKeyIt.next();
            qDebug() << qsKey;
            cIniFile::settings.remove(qsKey);
        }
        qDebug() << "All keys in section " << s << " removed!";

    }
    else
    {
        qDebug() << "No keys in section " << s << " found!";
    }
    cIniFile::settings.endGroup();

    cIniFile::settings.remove(s);
    qDebug() << "Section " << s << " removed!";

    //Добавление секции в список - результат
    //qslDeletedSections.append(s);
    qslDeletedSections.append(qsWay);//#@

    return Error;
}

//=============================================================================

void MainWindow::execActionRemoveSection()
{
    QString s = "ActionRemoveSection()";

    // Читаем имя текущей секции
    QString qsGroupName = cIniFile::Groups->at(iCurrentIndexGlobal.load(std::memory_order_relaxed));

    bool x = deleteSection(qsGroupName);
    // Выводим значения удалённых секций
    if(!x)
    {
        cIniFile::Groups->removeAt(iCurrentIndexGlobal.load(std::memory_order_relaxed));

        ui->listWidgetOther->clear();
        ui->listWidgetOther->addItems(qslDeletedSections);
    }

    execActionSelectImagePrevious();//Перерисовка изображения

    //===
    emit execShowExecStatus(s);
   //===

}

//=============================================================================

void MainWindow::execActionRemoveText()
{
    QString s = "ActionRemoveText()";
    //===
    // Создаем объект QSettings с указанием формата INI и пути к файлу
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);

    QStringList GroupsLocal = settings.childGroups();

    // Выводим значения
    //ui->listWidgetOther->clear();
    //ui->listWidgetOther->addItems(GroupsLocal);

    qDebug() << "childGroupsList length: " << GroupsLocal.count();
    qDebug() << "----------------------------";
    //---

    int iCount = 0;

    QStringList GroupsResult;//Список - результат
    GroupsResult.clear();

    QListIterator<QString> readIt(GroupsLocal);
    while (readIt.hasNext())
    {
        QString qsSection = readIt.next();

        bool IsSign = false;

        settings.beginGroup(qsSection);
        QList<QString> keys = settings.childKeys();
        int iKeysCount = keys.count();

        QString qsName = settings.value("name", "noName").toString();
        QString qsPath = settings.value("path", "noPath").toString();
        QString qsWay = qsPath + "/" + qsName;

        if(qsName.toLower().indexOf(".txt") >= 0)
        {
            iCount++;

            IsSign = true;

            GroupsResult.append(qsSection);//Добавление секции в список - результат

            qDebug() << "Name=" << qsName << " iCount=" << iCount << " Keys count=" << iKeysCount;

            //--- Удаление ключей секции: начало ---
            // Перебор всей ключей в секции
            QListIterator<QString> readKeyIt(keys);
            while (readKeyIt.hasNext())
            {
                QString qsKey = readKeyIt.next();
                qDebug() << qsKey;
                settings.remove(qsKey);
            }
            qDebug() << "All keys in section " << qsSection << " removed!";
            //--- Удаление ключей секции: конец ---
        }

        settings.endGroup();

        //--- Удаление секции совсем ---
        if(IsSign)
        {
            settings.remove(qsSection);
            cIniFile::Groups->removeOne(qsSection);
            //qslDeletedSections.append(qsSection);
            qslDeletedSections.append(qsWay);//#@
            ui->listWidgetOther->clear();
            ui->listWidgetOther->addItems(qslDeletedSections);
            qDebug() << "Section " << qsSection << " removed!";
        }

    }//End of while (readIt.hasNext())

    // Выводим имена обрабатываемых файлов
    ui->listWidgetOther->clear();
    ui->listWidgetOther->addItems(GroupsResult);

    if(iCount > 0)
        qDebug() << "Extension 'txt' detected in " << iCount << " files";
    else
        qDebug() << "No 'txt' in file names detected, Ok!";

    //===
    emit execShowExecStatus(s);
   //===

}

//=============================================================================

void MainWindow::execActionRemoveTif()
{

    QString s = "ActionRemoveTif()";
    //===
    // Создаем объект QSettings с указанием формата INI и пути к файлу
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);

    QStringList GroupsLocal = settings.childGroups();

    // Выводим значения
    //ui->listWidgetOther->clear();
    //ui->listWidgetOther->addItems(GroupsLocal);

    qDebug() << "childGroupsList length: " << GroupsLocal.count();
    qDebug() << "----------------------------";
    //---

    int iCount = 0;

    QStringList GroupsResult;//Список - результат
    GroupsResult.clear();

    QListIterator<QString> readIt(GroupsLocal);
    while (readIt.hasNext())
    {
        QString qsSection = readIt.next();

        bool IsSign = false;

        settings.beginGroup(qsSection);
        QList<QString> keys = settings.childKeys();
        int iKeysCount = keys.count();

        QString qsName = settings.value("name", "noName").toString();
        QString qsPath = settings.value("path", "noPath").toString();
        QString qsWay = qsPath + "/" + qsName;

        if(qsName.toLower().indexOf(".tif") >= 0)
        {
            iCount++;

            IsSign = true;

            GroupsResult.append(qsSection);//Добавление секции в список - результат

            qDebug() << "Name=" << qsName << " iCount=" << iCount << " Keys count=" << iKeysCount;
            // Перебор всей ключей в секции
            QListIterator<QString> readKeyIt(keys);
            while (readKeyIt.hasNext())
            {
                QString qsKey = readKeyIt.next();
                qDebug() << qsKey;
                settings.remove(qsKey);
            }
            qDebug() << "All keys in section " << qsSection << " removed!";
        }

        settings.endGroup();

        //--- Удаление секции совсем ---
        if(IsSign)
        {
            settings.remove(qsSection);
            cIniFile::Groups->removeOne(qsSection);
            //qslDeletedSections.append(qsSection);
            qslDeletedSections.append(qsWay);//#@
            ui->listWidgetOther->clear();
            ui->listWidgetOther->addItems(qslDeletedSections);
            qDebug() << "Section " << qsSection << " removed!";
        }

    }//End of while (readIt.hasNext())

    // Выводим имена обрабатываемых файлов
    ui->listWidgetOther->clear();
    ui->listWidgetOther->addItems(GroupsResult);

    if(iCount > 0)
        qDebug() << "Extension 'tif' detected in " << iCount << " files";
    else
        qDebug() << "No 'tif' in file names detected, Ok!";

    //===
    emit execShowExecStatus(s);
   //===

}

//=============================================================================

void MainWindow::execActionRemoveMovie()
{
    QString s = "ActionRemoveMovie()";
    //===
    // Создаем объект QSettings с указанием формата INI и пути к файлу
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);

    QStringList GroupsLocal = settings.childGroups();

    // Выводим значения
    //ui->listWidgetOther->clear();
    //ui->listWidgetOther->addItems(GroupsLocal);

    qDebug() << "childGroupsList length: " << GroupsLocal.count();
    qDebug() << "----------------------------";
    //---

    int iCount = 0;

    QStringList GroupsResult;//Список - результат
    GroupsResult.clear();

    QListIterator<QString> readIt(GroupsLocal);
    while (readIt.hasNext())
    {
        QString qsSection = readIt.next();

        //---
        bool IsSign = false;

        settings.beginGroup(qsSection);
        QList<QString> keys = settings.childKeys();
        int iKeysCount = keys.count();

        QString qsName = settings.value("name", "noName").toString();
        QString qsPath = settings.value("path", "noPath").toString();
        QString qsWay = qsPath + "/" + qsName;

        if(qsName.toLower().indexOf(".mp4") >= 0)
        {
            iCount++;

            IsSign = true;

            GroupsResult.append(qsSection);//Добавление секции в список - результат

            qDebug() << "Name=" << qsName << " iCount=" << iCount << " Keys count=" << iKeysCount;
            // Перебор всей ключей в секции
            QListIterator<QString> readKeyIt(keys);
            while (readKeyIt.hasNext())
            {
                QString qsKey = readKeyIt.next();
                qDebug() << qsKey;

                settings.remove(qsKey);
            }
            qDebug() << "All keys in section " << qsSection << " removed!";
        }

        settings.endGroup();

        //--- Удаление секции совсем ---
        if(IsSign)
        {
            settings.remove(qsSection);
            cIniFile::Groups->removeOne(qsSection);
            //qslDeletedSections.append(qsSection);
            qslDeletedSections.append(qsWay);//#@
            ui->listWidgetOther->clear();
            ui->listWidgetOther->addItems(qslDeletedSections);
            qDebug() << "Section " << qsSection << " removed!";
        }
        //---
    }//End of while (readIt.hasNext())

    // Выводим имена обрабатываемых файлов
    ui->listWidgetOther->clear();
    ui->listWidgetOther->addItems(GroupsResult);

    if(iCount > 0)
        qDebug() << "Extension 'mp4' detected in " << iCount << " files";
    else
        qDebug() << "No 'mp4' in file names detected, Ok!";

    //===
    emit execShowExecStatus(s);
   //===

}

//=============================================================================

void MainWindow::execActionRotateCW()
{
    QString s = "ActionRotateCW()";

    iAngle = 90;

    cDrawFiles::execRotate(iAngle);

    emit draw(cIniFile::currentRotatedImagePath);

    //===
    emit execShowExecStatus(s);
    //===

}

//=============================================================================

void MainWindow::execActionRotateCCW()
{
    QString s = "ActionRotateCCW()";

    iAngle = 270;

    cDrawFiles::execRotate(iAngle);

    emit draw(cIniFile::currentRotatedImagePath);

    //===
    emit execShowExecStatus(s);
    //===

}

//=============================================================================

void MainWindow::execSpinBoxAngle(int angle)
{
    qDebug() << "Angle:" << angle;
    iAngle = angle;
    cDrawFiles::execRotate(iAngle);

    emit draw(cIniFile::currentRotatedImagePath);

}

//=============================================================================

void MainWindow::execTimerUpdate()
{
    //qDebug() << "CurrentIndex=" << CurrentIndex;
    iTimerUpdateCounter++;

    if(iTimerUpdateCounter == 1)
    {
        qDebug() << "CurrentIndex=" << iCurrentIndexGlobal.load(std::memory_order_relaxed) << " Action: open ViewPictureForm";
        int windowX = this->x();
        windowX = windowX + this->width();
        windowX = windowX + WINDOW_LEFT_MARGING;

        int windowY = this->y() + WINDOW_TOP_MARGING;

        int windowWidth = fmViewPicture->width();
        int windowHeight = fmViewPicture->height();

        QRect windowPlace = QRect(windowX, windowY, windowWidth, windowHeight);
        fmViewPicture->setGeometry(windowPlace);

        fmViewPicture->show();
        ui->actionViewPicture->setChecked(true);

        qDebug() << "CurrentIndex=" << iCurrentIndexGlobal.load(std::memory_order_relaxed);
        execActionLoad();

        loadRemovedSectionsList();

    }//End of if(iTimerUpdateCounter == 1)

//    progressBarProcess->setRange(0, cImportFiles::MaxIndexValue);
//    int x = iCurrentIndexGlobal.load(std::memory_order_relaxed);
//    progressBarProcess->setValue(x);

    if(cImportFiles::IslabelExecStatusTextChacnged)
    {
        labelExecStatus->setText(cImportFiles::labelExecStatusText);
        cImportFiles::IslabelExecStatusTextChacnged = false;
    }

    if(cImportFiles::IslabelFileNameTextChanged)
    {
        labelFileName->setText(cImportFiles::labelFileNameText);
        cImportFiles::IslabelFileNameTextChanged = false;
    }

}

//=============================================================================

void MainWindow::execShowExecStatus(QString s)
{
    cImportFiles::labelExecStatusText = s;
    cImportFiles::IslabelExecStatusTextChacnged = true;
}

//=============================================================================

void MainWindow::execActionGetGroupsList()
{
    QString s = "execActionGetGroupsList()";

    bool x = cImportFiles::getGroupsList();
    if(x)
    {
        s += ": error detected!";
    }
    else
    {
        s += ": sucsess!";

        ui->listWidgetOther->clear();
        ui->listWidgetOther->addItems(*cIniFile::Groups);
    }

    //---
    emit execShowExecStatus(s);
    //---
}

//=============================================================================

void MainWindow::execActionMemo()
{
    QString s;
    QString item = ui->lineEditMemo->text();
    if(item.length() > 0)
    {
        qDebug() << "execActionMemo():" << item;

        s = "execInsertMemoKeyValue()";

        // Сохранение параметра в INI-файле
        if(cIniFile::Groups->count() > 0)
        {
            QString qsGroupName = cIniFile::Groups->at(iCurrentIndexGlobal.load(std::memory_order_relaxed));
            //cIniFile::settings.beginGroup(qsGroupName);
            //cIniFile::settings.setValue("memo", item);
            cIniFile::settings.beginGroup(qsGroupName);
            QString key = "memo";
            QStringList list = cIniFile::settings.childKeys();
            if(list.contains(key))
            {
                qDebug() << qsGroupName << " contains " << key;
                cIniFile::settings.remove(key);
            }
            else
            {
                qDebug() << qsGroupName << " not contains " << key;
                cIniFile::settings.setValue(key, item);
            }
            cIniFile::settings.endGroup();

        }
        else
        {
            s = "List is empty, exec Load function!!!";
        }
        // Отобразить картинку
        showCurrentIndexPicture();
    }
    else
    {
        qDebug() << "execActionMemo(): nothing to do";

        s = "Memo is emtpy, nothing to do!";
    }
    //---
    emit execShowExecStatus(s);
    //---
}

//=============================================================================

void MainWindow::execListWidgetSubjectItemClicked()
{
    QString s = "execSubjectItemClicked()";
    QString item = ui->listWidgetSubject->currentItem()->text();
    qDebug() << "listWidgetSubject: item=" << item;

    // Сохранение параметра в INI-файле
    if(cIniFile::Groups->count() > 0)
    {
        QString qsGroupName = cIniFile::Groups->at(iCurrentIndexGlobal.load(std::memory_order_relaxed));
        //cIniFile::settings.beginGroup(qsGroupName);
        //cIniFile::settings.setValue(item, "true");
        cIniFile::settings.beginGroup(qsGroupName);
        QStringList list = cIniFile::settings.childKeys();
        if(list.contains(item))
        {
            qDebug() << qsGroupName << " contains " << item;
            cIniFile::settings.remove(item);
        }
        else
        {
            qDebug() << qsGroupName << " not contains " << item;
            cIniFile::settings.setValue(item, "true");
        }
        cIniFile::settings.endGroup();

    }
    else
    {
        s = "List is empty, exec Load function!!!";
    }
    // Отобразить картинку
    showCurrentIndexPicture();
    //---
    emit execShowExecStatus(s);
    //---
}

//=============================================================================

void MainWindow::execListWidgetPropertyItemClicked()
{
    QString s = "execPropertyItemClicked()";
    QString item = ui->listWidgetPropertyes->currentItem()->text();
    qDebug() << "listWidgetProperty: item=" << item;

    // Сохранение параметра в INI-файле
    if(cIniFile::Groups->count() > 0)
    {
        QString qsGroupName = cIniFile::Groups->at(iCurrentIndexGlobal.load(std::memory_order_relaxed));
        //cIniFile::settings.beginGroup(qsGroupName);
        //cIniFile::settings.setValue(item, "true");
        cIniFile::settings.beginGroup(qsGroupName);
        QStringList list = cIniFile::settings.childKeys();
        if(list.contains(item))
        {
            qDebug() << qsGroupName << " contains " << item;
            cIniFile::settings.remove(item);
        }
        else
        {
            qDebug() << qsGroupName << " not contains " << item;
            cIniFile::settings.setValue(item, "true");
        }
        cIniFile::settings.endGroup();

    }
    else
    {
        s = "List is empty, exec Load function!!!";
    }
    // Отобразить картинку
    showCurrentIndexPicture();
    //---
    emit execShowExecStatus(s);
    //---
}

//=============================================================================

void MainWindow::execListWidgetTheameItemClicked()
{
    QString s = "execTheameItemClicked()";
    QString item = ui->listWidgetTheams->currentItem()->text();
    qDebug() << "listWidgetTheame: item=" << item;

    // Сохранение параметра в INI-файле
    if(cIniFile::Groups->count() > 0)
    {
        QString qsGroupName = cIniFile::Groups->at(iCurrentIndexGlobal.load(std::memory_order_relaxed));
        //cIniFile::settings.beginGroup(qsGroupName);
        //cIniFile::settings.setValue(item, "true");
        cIniFile::settings.beginGroup(qsGroupName);
        QStringList list = cIniFile::settings.childKeys();
        if(list.contains(item))
        {
            qDebug() << qsGroupName << " contains " << item;
            cIniFile::settings.remove(item);
        }
        else
        {
            qDebug() << qsGroupName << " not contains " << item;
            cIniFile::settings.setValue(item, "true");
        }
        cIniFile::settings.endGroup();

    }
    else
    {
        s = "List is empty, exec Load function!!!";
    }
    // Отобразить картинку
    showCurrentIndexPicture();
    //---
    emit execShowExecStatus(s);
    //---
}

//=============================================================================

void MainWindow::execListWidgetPlaceItemClicked()
{
    QString s = "execPlaceItemClicked()";
    QString item = ui->listWidgetPlaces->currentItem()->text();
    qDebug() << "listWidgetPlace: item=" << item;

    // Сохранение параметра в INI-файле
    if(cIniFile::Groups->count() > 0)
    {
        QString qsGroupName = cIniFile::Groups->at(iCurrentIndexGlobal.load(std::memory_order_relaxed));
        cIniFile::settings.beginGroup(qsGroupName);
        QStringList list = cIniFile::settings.childKeys();
        if(list.contains(item))
        {
            qDebug() << qsGroupName << " contains " << item;
            cIniFile::settings.remove(item);
        }
        else
        {
            qDebug() << qsGroupName << " not contains " << item;
            cIniFile::settings.setValue(item, "true");
        }
        cIniFile::settings.endGroup();

    }
    else
    {
        s = "List is empty, exec Load function!!!";
    }
    // Отобразить картинку
    showCurrentIndexPicture();
    //---
    emit execShowExecStatus(s);
    //---
}

//=============================================================================


