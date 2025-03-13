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

    ViewPicture = new fmView(this);
    //ViewPicture->setWindowFlags(Qt::Window);//3 flags
    ViewPicture->setWindowFlags(Qt::Drawer);//1 flag
    //ViewPicture->setWindowFlags(Qt::Sheet);//1 flag + ?
    //ViewPicture->setWindowFlags(Qt::Dialog);//1 flag + ?
    //ViewPicture->setWindowFlags(Qt::Popup);//no flags, immobil
    //ViewPicture->setWindowFlags(Qt::Tool);//1 flag, immobil
    //ViewPicture->setWindowFlags(Qt::ToolTip);//no flags, immobil
    //ViewPicture->setWindowFlags(Qt::SplashScreen);//no flags, immobil

    connect(this, SIGNAL(draw(QString)), ViewPicture, SLOT( execDraw(QString)));

    ViewPicture->show();

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
    QString qsPath = cIniFile::settings.value("path","noName").toString();
    QString qsName = cIniFile::settings.value("name", "noName").toString();
    QString qsError = cIniFile::settings.value("Error", "false").toString();
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
