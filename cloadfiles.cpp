#include "cloadfiles.h"

cLoadFiles::cLoadFiles()
{

}

bool cLoadFiles::execLoadFiles()
{
    bool Result = true;

    //--- Начало функции загрузки

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

    //Загрузка списка групп
    *cIniFile::Groups = settings.childGroups();//20250415 ???
    //cImportFiles::getGroupsList();

    // Выводим значения
    qDebug() << "length: " << iLength;
    qDebug() << "childGroupsList length: " << cIniFile::Groups->count();
    qDebug() << "----------------------------";
    cImportFiles::MaxIndexValue = cIniFile::Groups->count();
    int iCount = 0;
    iCurrentIndexGlobal.store(0);

    QListIterator<QString> readIt(*cIniFile::Groups);
    while (readIt.hasNext())
    {
        iCurrentIndexGlobal.fetch_add(1, std::memory_order_relaxed);

        //---Отображение состояния загрузки
        //int x = iCurrentIndexGlobal.load(std::memory_order_relaxed);
        //progressBarProcess->setValue(x);
        //---

        QString qsSection = readIt.next();
        //qDebug() << qsSection;
        settings.beginGroup(qsSection);
        //===
        QString qsPath, qsName, qsError, qsId;

        QStringList keys = settings.childKeys();
        QListIterator<QString> readIt(keys);
        int iIndex = 0;
        while(readIt.hasNext())
        {
            QString key = readIt.next();
            QString value = settings.value(key,"0").toString();

            if(key == "Id") qsId = value;
            if(key == "path") qsPath = value;
            if(key == "name") qsName = value;
            if(key == "Eror") qsError = value;

            iIndex++;
            //qDebug() << "iterator:" << key << " index:" << iIndex;
        }

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
        //===
        settings.endGroup();
    }

    if(iCount > 0)
        qDebug() << "Space character in file name detected in " << iCount << " files";
    else
        qDebug() << "No errors in file names detected, Ok!";

    iCurrentIndexGlobal.store(LoadedCurrentIndex);

    //--- Окончание функции загрузки

    settings.sync();

    return Result;
}
