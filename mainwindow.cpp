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
    connect(ui->actionRemoveMovie, SIGNAL(triggered()), this, SLOT( execActionRemoveMovie()));
    connect(ui->actionRotateCW, SIGNAL(triggered()), this, SLOT( execActionRotateCW()));
    connect(ui->actionRotateCCW, SIGNAL(triggered()), this, SLOT( execActionRotateCCW()));

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
    connect(ui->actionImportFiles, SIGNAL(triggered()), this, SLOT( execActionImportFiles()));

    connect(ui->actionLoad, SIGNAL(triggered()), this, SLOT( execActionLoad()));
    connect(ui->actionLoaadHashTagListSubject, SIGNAL(triggered()), this, SLOT( execActionLoadHashTagListSubject()));
    connect(ui->actionLoadHashTagListPlace, SIGNAL(triggered()), this, SLOT( execActionLoadHashTagListPlace()));
    connect(ui->actionLoadHashTagListProperty, SIGNAL(triggered()), this, SLOT( execActionLoadHashTagListProperty()));

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

    ui->actionViewPicture->setChecked(false);
    //ViewPicture->show();

    //this->setFocus();
    //this->raise();
    //this->activateWindow();
    //this->show();

    //---Создание рабочего списка
    std::unique_ptr<QList<cRecord> > ptrRecordList(new QList<cRecord>());
    cRecord::RecordList = ptrRecordList.get();

    timerUpdate = new QTimer(this);
    connect(timerUpdate, SIGNAL(timeout()), this, SLOT( execTimerUpdate()));
    timerUpdate->start(100);

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
    cIniFile::settings.sync();
    timerUpdate->stop();

    delete progressBarProcess;
    delete labelExecStatus;
    delete labelFileName;

    delete fmViewPicture;

    delete qslHashTagList;

    delete ui;
}

void MainWindow::showCurrentIndexPicture()
{

    // Читаем значения из INI-файла
    QString qsGroupName = Groups.at(cImportFiles::CurrentIndex);
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
      cIniFile::settings.beginGroup("RecordList");
      cIniFile::settings.setValue("index", cImportFiles::CurrentIndex);
      cIniFile::settings.endGroup();

      qDebug() << "Store CurrentIndex:" << cImportFiles::CurrentIndex;
}

void MainWindow::execActionSelectImageBegin()
{
    // Модификация индекса
    cImportFiles::CurrentIndex = 0;

    // Отобразить картинку
    showCurrentIndexPicture();

    //---
    QString s = "execActionSelectImageBegin(), goto index:";
    s += QString::number(cImportFiles::CurrentIndex);
    emit execShowExecStatus(s);
    //---

}//End of void MainWindow::execActionSelectImageBegin()

void MainWindow::execActionSelectImageNext()
{
    if(cImportFiles::CurrentIndex < Groups.count() - 1) cImportFiles::CurrentIndex++;

    // Отобразить картинку
    showCurrentIndexPicture();

    //---
    QString s = "execActionSelectImageNext(), goto index:";
    s += QString::number(cImportFiles::CurrentIndex);
    emit execShowExecStatus(s);
    //---

}

void MainWindow::execActionSelectImagePrevious()
{
    if(cImportFiles::CurrentIndex > 0) cImportFiles::CurrentIndex--;

    // Отобразить картинку
    showCurrentIndexPicture();

    //---
    QString s = "execActionSelectImagePrevious(), goto index:";
    s += QString::number(cImportFiles::CurrentIndex);
    emit execShowExecStatus(s);
    //---

}

void MainWindow::execActionSelectImageEnd()
{
    cImportFiles::CurrentIndex = Groups.count() - 1;

    // Отобразить картинку
    showCurrentIndexPicture();

    //---
    QString s = "execActionSelectImageEnd(), goto index";
    s += QString::number(cImportFiles::CurrentIndex);
    emit execShowExecStatus(s);
    //---

}

void MainWindow::execActionImportInitial()
{
    //---
    QString s = "execActionImport()";
    emit execShowExecStatus(s);
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
    cImportFiles::MaxIndexValue = cRecord::RecordList->count();
    cIniFile::IniFile.addInitalSection(cImportFiles::MaxIndexValue);
    //progressBarProcess->setRange(0, cImportFiles::MaxIndexValue);

    //---Добавление данных в файл конфигурации
    //cIniFile::IniFile.addRecordListData();

    for(QList<cRecord>::iterator it = cRecord::RecordList->begin(); it != cRecord::RecordList->end(); ++it)
     {
        cIniFile::IniFile.Id++;//Счётчик записей

        cImportFiles::CurrentIndex = cIniFile::IniFile.Id;

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

    emit execShowExecStatus("File import complete!");

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
    int LoadedCurrentIndex = qsCurrentIndex.toInt(Ok);
    if(!*Ok)LoadedCurrentIndex = 0;

    qDebug() << "Loaded CurrentIndex:" << LoadedCurrentIndex;

    QString qsLength = settings.value("length", "0").toString();
    int iLength = qsLength.toInt(Ok);
    if(!*Ok)iLength = 0;
    settings.endGroup();

    Groups = settings.childGroups();

    // Выводим значения
    qDebug() << "length: " << iLength;
    qDebug() << "childGroupsList length: " << Groups.count();
    qDebug() << "----------------------------";
    cImportFiles::MaxIndexValue = Groups.count();
    //progressBarProcess->setRange(0, Groups.count());
    int iCount = 0;
    cImportFiles::CurrentIndex = 0;
    QListIterator<QString> readIt(Groups);
    while (readIt.hasNext())
    {
        cImportFiles::CurrentIndex++;

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

    cImportFiles::CurrentIndex = LoadedCurrentIndex;

    execActionSelectImageNext();

    //---
    QString s = "execActionLoad(), goto index:";
    s += QString::number(cImportFiles::CurrentIndex);
    emit execShowExecStatus(s);
    //---

}//End of void MainWindow::execActionLoad()


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

void MainWindow::execListWidgetSuggestItemClicked()
{
    QString s = "execInsertNewKeyValue()";
    QString item = ui->listWidgetSuggest->currentItem()->text();
    qDebug() << "listWidgetSuggest: item=" << item;

    // Сохранение параметра в INI-файле
    if(Groups.count() > 0)
    {
        QString qsGroupName = Groups.at(cImportFiles::CurrentIndex);
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
    emit execShowExecStatus(s);
    //---
}

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


void MainWindow::execActionLoadHashTagListSubject()
{
    QString s = "ActionLoadHashTagListSubject()";
    if(loadHashTagListSubject())
    {
        qDebug() << s << ": loadHashTagListSubject is sucsess";
        ui->listWidgetSuggest->clear();
        ui->listWidgetSuggest->addItems(*qslHashTagList);

//        connect(ui->listWidgetSuggest, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(execListWidgetSuggestItemClicked()));
    }
    else
    {
        ui->listWidgetSuggest->clear();
        qDebug() << s << ": loadHashTagListSubject is broken!!!";
    }
    //---
    emit execShowExecStatus(s);
    //---

}

void MainWindow::execActionLoadHashTagListPlace()
{
    QString s = "ActionLoadHashTagListPlace()";

    if(loadHashTagListPlace())
    {
        qDebug() << s << ": loadHashTagListPlace is sucsess";
        ui->listWidgetSuggest->clear();
        ui->listWidgetSuggest->addItems(*qslHashTagList);

//        connect(ui->listWidgetSuggest, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(execListWidgetSuggestItemClicked()));
    }
    else
    {
        ui->listWidgetSuggest->clear();
        qDebug() << s << ": loadHashTagListPlace is broken!!!";
    }
    //---
    emit execShowExecStatus(s);
    //---

}

void MainWindow::execActionLoadHashTagListProperty()
{
    QString s = "ActionLoadHashTagListProperty()";

    if(loadHashTagListProperty())
    {
        qDebug() << s << ": loadHashTagListProperty is sucsess";
        ui->listWidgetSuggest->clear();
        ui->listWidgetSuggest->addItems(*qslHashTagList);

//        connect(ui->listWidgetSuggest, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(execListWidgetSuggestItemClicked()));
    }
    else
    {
        ui->listWidgetSuggest->clear();
        qDebug() << s << ": loadHashTagListPrperty is broken!!!";
    }
    //---
    emit execShowExecStatus(s);
    //---

}


void MainWindow::execActionRemoveMovie()
{
    QString s = "ActionRemoveMovie()";
    //===
    // Создаем объект QSettings с указанием формата INI и пути к файлу
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);

    QStringList GroupsLocal = settings.childGroups();

    // Выводим значения
    qDebug() << "childGroupsList length: " << GroupsLocal.count();
    qDebug() << "----------------------------";
    //---

    int iCount = 0;

    QListIterator<QString> readIt(GroupsLocal);
    while (readIt.hasNext())
    {
        QString qsSection = readIt.next();

        settings.beginGroup(qsSection);
        QList<QString> keys = settings.childKeys();
        int iKeysCount = keys.count();

        QString qsName = settings.value("name", "noName").toString();

        if(qsName.toLower().indexOf(".mp4") >= 0)
        {
            iCount++;
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
    }
    if(iCount > 0)
        qDebug() << "Extension 'mp4' detected in " << iCount << " files";
    else
        qDebug() << "No 'mp4' in file names detected, Ok!";

    //===
    emit execShowExecStatus(s);
   //===

}

void MainWindow::execActionRotateCW()
{
    QString s = "ActionRotateCW()";

    iAngle = 90;

    execRotate(iAngle);

    //===
    emit execShowExecStatus(s);
    //===

}

void MainWindow::execActionRotateCCW()
{
    QString s = "ActionRotateCCW()";

    iAngle = 270;

    execRotate(iAngle);

    //===
    emit execShowExecStatus(s);
    //===

}

void MainWindow::execSpinBoxAngle(int angle)
{
    qDebug() << "Angle:" << angle;
    iAngle = angle;
    execRotate(iAngle);
}

void MainWindow::execRotate(int angle)
{
    //--- Читаем значения из INI-файла
    QString qsGroupName = Groups.at(cImportFiles::CurrentIndex);

    cIniFile::settings.beginGroup(qsGroupName);

    QString qsPath = cIniFile::settings.value("path","").toString();
    QString qsName = cIniFile::settings.value("name","").toString();

    cIniFile::settings.endGroup();

    QString imagePath = qsPath + '/' + qsName;
    qDebug() << "Path:" << imagePath;
    //---

    QImage originalImage(imagePath);

    // Создаем новое изображение для хранения повернутого изображения
    QImage rotatedImage(originalImage.size(), originalImage.format());
    rotatedImage.fill(Qt::transparent); // Заполняем прозрачным, если нужно

    QPainter painter(&rotatedImage);
    painter.setRenderHint(QPainter::SmoothPixmapTransform); // Сглаживание для более качественного поворота

    // Центр поворота (по умолчанию центр изображения)
    QPoint center = originalImage.rect().center();

    // Создаем матрицу трансформации
    QTransform transform;
    transform.translate(center.x(), center.y());    // Перемещаем систему координат в центр изображения
    transform.rotate(angle);                        // Выполняем поворот
    transform.translate(-center.x(), -center.y());  // Возвращаем систему координат

    painter.setTransform(transform);
    painter.drawImage(0, 0, originalImage); // Рисуем исходное изображение на повернутом

    painter.end();

    rotatedImage.save(rotatedImagePath); // Сохраняем повернутое изображение

    emit draw(rotatedImagePath);//Отображаем повёрнутое изображение на форме

    qDebug() << "Image rotated successfully";

}

void MainWindow::execTimerUpdate()
{
    //qDebug() << "CurrentIndex=" << CurrentIndex;
    iTimerUpdateCounter++;
    if(iTimerUpdateCounter == 1)
    {
        qDebug() << "CurrentIndex=" << cImportFiles::CurrentIndex << " Action: open ViewPictureForm";
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

        qDebug() << "CurrentIndex=" << cImportFiles::CurrentIndex;// << " Action: Load";
        execActionLoad();
    }

    progressBarProcess->setRange(0, cImportFiles::MaxIndexValue);
    progressBarProcess->setValue(cImportFiles::CurrentIndex);

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
void MainWindow::execShowExecStatus(QString s)
{
    cImportFiles::labelExecStatusText = s;
    cImportFiles::IslabelExecStatusTextChacnged = true;
}

void MainWindow::execActionMemo()
{
    QString s;
    QString item = ui->lineEditMemo->text();
    if(item.length() > 0)
    {
        qDebug() << "execActionMemo():" << item;

        s = "execInsertMemoKeyValue()";

        // Сохранение параметра в INI-файле
        if(Groups.count() > 0)
        {
            QString qsGroupName = Groups.at(cImportFiles::CurrentIndex);
            cIniFile::settings.beginGroup(qsGroupName);
            cIniFile::settings.setValue("memo", item);
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

void MainWindow::execActionImportFiles()
{
    QString s = "execActionImportFiles()";

    if(cImportFiles::execImport()) s += ": Ok"; else s += ": Failure";

    //---
    emit execShowExecStatus(s);
    //---
}
