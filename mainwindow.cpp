#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionSelectImageBegin, SIGNAL(triggered()), this, SLOT( execActionSelectImageBegin()));
    connect(ui->actionSelectImageNext, SIGNAL(triggered()), this, SLOT( execActionSelectImageNext()));
    connect(ui->actionSelectImagePrevious, SIGNAL(triggered()), this, SLOT( execActionSelectImagePrevious()));
    connect(ui->actionSelectImageEnd, SIGNAL(triggered()), this, SLOT( execActionSelectImageEnd()));

    connect(ui->pushButtonBegin, SIGNAL(pressed()), this, SLOT( execActionSelectImageBegin()));
    connect(ui->pushButtonNext, SIGNAL(pressed()), this, SLOT( execActionSelectImageNext()));
    connect(ui->pushButtonPrevious, SIGNAL(pressed()), this, SLOT( execActionSelectImagePrevious()));
    connect(ui->pushButtonEnd, SIGNAL(pressed()), this, SLOT( execActionSelectImageEnd()));

    connect(ui->actionImport, SIGNAL(triggered()), this, SLOT( execActionImport()));
    connect(ui->actionLoad, SIGNAL(triggered()), this, SLOT( execActionLoad()));

    //---Создание рабочего списка
    std::unique_ptr<QList<cRecord> > ptrRecordList(new QList<cRecord>());
    cRecord::RecordList = ptrRecordList.get();

    progressBarProcess = new QProgressBar();
    progressBarProcess->setOrientation(Qt::Horizontal);
    progressBarProcess->setRange(0, 100);
    ui->statusBar->addWidget(progressBarProcess);

    labelProgressBar = new QLabel("ProgressBar");
    ui->statusBar->addWidget(labelProgressBar);

    //execActionLoad();

    //execActionSelectImageBegin();

}//End of ctor

MainWindow::~MainWindow()
{
    delete progressBarProcess;
    delete labelProgressBar;

    delete ui;
}

void MainWindow::scaleImage(QString path)
{
    int newWidth = ui->labelMain->width();//960
    int newHeight = ui->labelMain->height();//540

    QImage originalImage(path);

    if (originalImage.isNull())
    {
        qDebug() << "Error: Could not load image: " << path;
        return;
    }

    // Масштабирование изображения
    QImage scaledImage = originalImage.scaled(
        newWidth,
        newHeight,
        Qt::KeepAspectRatio, // Сохранять пропорции
        Qt::SmoothTransformation // Использовать сглаживание
    );
    // Сохранение масштабированного изображения
    scaledImage.save(scaledImagePath);
}

void MainWindow::showCurrentIndexPicture()
{

    // Создаем объект QSettings с указанием формата INI и пути к файлу
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);

    // Читаем значения из INI-файла
    QString qsGroupName = Groups.at(CurrentIndex);
    settings.beginGroup(qsGroupName);
    QString qsPath = settings.value("path","noName").toString();
    QString qsName = settings.value("name", "noName").toString();
    settings.endGroup();

    QString imagePath = qsPath + '/' + qsName;

    qDebug() << "FullPath: " << imagePath;

    //Вывод картинки на форму
    scaleImage(imagePath);
    QPixmap pmMain(scaledImagePath);//
    ui->labelMain->setPixmap(pmMain);

}

void MainWindow::execActionSelectImageBegin()
{
    //---
    QString s = "execActionSelectImageBegin()";
    qDebug() << s;
    labelProgressBar->setText(s);
    //---

    // Модификация индекса
    CurrentIndex = 0;
    progressBarProcess->setValue(CurrentIndex);

    // Отобразить картинку
    showCurrentIndexPicture();

}//End of void MainWindow::execActionSelectImageBegin()

void MainWindow::execActionSelectImageNext()
{
    //---
    QString s = "execActionSelectImageNext()";
    qDebug() << s;
    labelProgressBar->setText(s);
    //---

    if(CurrentIndex < Groups.count() - 1) CurrentIndex++;
    progressBarProcess->setValue(CurrentIndex);

    // Отобразить картинку
    showCurrentIndexPicture();

}

void MainWindow::execActionSelectImagePrevious()
{
    QString s = "execActionSelectImagePrevious()";
    qDebug() << s;
    //ui->statusBar->showMessage(s, STATUS_BAR_DELAY);
    labelProgressBar->setText(s);

    if(CurrentIndex > 0) CurrentIndex--;
    progressBarProcess->setValue(CurrentIndex);

    // Отобразить картинку
    showCurrentIndexPicture();

}

void MainWindow::execActionSelectImageEnd()
{
    QString s = "execActionSelectImageEnd()";
    qDebug() << s;
    //ui->statusBar->showMessage(s, STATUS_BAR_DELAY);
    labelProgressBar->setText(s);

    CurrentIndex = Groups.count() - 1;
    progressBarProcess->setValue(CurrentIndex);

    // Отобразить картинку
    showCurrentIndexPicture();

}

void MainWindow::execActionImport()
{
    QString s = "execActionImport()";
    qDebug() << s;
    //ui->statusBar->showMessage(s, STATUS_BAR_DELAY);
    labelProgressBar->setText(s);

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
            qDebug() << "Extension: mp4";
        }
        else
        {
            //Фрагмент для обработки файлов изображений
            QImage image(path);//name

            width = image.width();
            height = image.height();
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

    qDebug() << "==================Task is done!!!=========================";
    labelProgressBar->setText("File import complete!");

}//End of void MainWindow::execActionImport()

void MainWindow::execActionLoad()
{
    QString s = "execActionLoad()";
    qDebug() << s;
    //ui->statusBar->showMessage(s, STATUS_BAR_DELAY);
    labelProgressBar->setText(s);

    // Создаем объект QSettings с указанием формата INI и пути к файлу
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);

    // Читаем значения из INI-файла
    settings.beginGroup("RecordList");
    QString qsLength = settings.value("length", "0").toString();

    std::unique_ptr<bool> ptrOk = std::make_unique<bool>();
    bool* Ok = ptrOk.get();
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
        int Id = qsId.toInt(Ok);
        if(!*Ok)iLength = 0;

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

    CurrentIndex = 0;

}//End of void MainWindow::execActionLoad()

