#include "cloadfiles.h"

cLoadFiles::cLoadFiles()
{

}
//
// Функция отбора файлов из общего списка по условию
//
bool cLoadFiles::execLoadFiles()
{
    bool Result = true;

    //--- Начало функции загрузки

    // Создаем объект QSettings с указанием формата INI и пути к файлу
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);

    // Читаем значения из INI-файла

    QStringList TotalGroups = settings.childGroups();//Загрузка полного списка групп
    cIniFile::Groups->clear();//Очистка результата

    // Выводим значения
    qDebug() << "TotalGroups length: " << TotalGroups.count();
    qDebug() << "----------------------------";

    int iCount = 0;// Очистка счётчика найденных объектов

    QListIterator<QString> readIt(TotalGroups);
    while (readIt.hasNext())
    {
        QString qsSection = readIt.next();
        //qDebug() << qsSection;
        settings.beginGroup(qsSection);
        //===
        QString qsIsRotated;

        QStringList keys = settings.childKeys();
        QListIterator<QString> readIt(keys);
        while(readIt.hasNext())
        {
            QString key = readIt.next();
            QString value = settings.value(key,"0").toString();

            if(key == "IsRotated")
            {
                qsIsRotated = value;
                iCount++;
                cIniFile::Groups->append(qsSection);
                qDebug() << "iterator: section=" << qsSection << " key=" << key << " count=" << iCount;
            }
        }
        //===
        settings.endGroup();
    }

    if(iCount > 0)
        qDebug() << "IsRotated key detected in " << iCount << " files";
    else
        qDebug() << "No IsRotated key detected";

    //--- Окончание функции загрузки

    settings.sync();

    return Result;
}//End of bool cLoadFiles::execLoadFiles()


bool cLoadFiles::execLoadFilesByConditionOrYes(QStringList yes)
{
    bool Result = true;

    //--- Начало функции загрузки

    // Создаем объект QSettings с указанием формата INI и пути к файлу
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);

    // Читаем значения из INI-файла

    QStringList TotalGroups = settings.childGroups();//Загрузка полного списка групп
    cIniFile::Groups->clear();//Очистка результата

    // Выводим значения
    qDebug() << "TotalGroups length: " << TotalGroups.count();
    qDebug() << "----------------------------";

    int iCount = 0;// Очистка счётчика найденных объектов

    QListIterator<QString> readIt(TotalGroups);
    while (readIt.hasNext())
    {
        QString qsSection = readIt.next();
        //qDebug() << qsSection;
        settings.beginGroup(qsSection);
        //===
        QString qsIsRotated;

        QStringList keys = settings.childKeys();
        QListIterator<QString> readIt(keys);

        while(readIt.hasNext())
        {
            QString key = readIt.next();
            QString value = settings.value(key,"0").toString();

            QListIterator<QString> readItYes(yes);

            while (readItYes.hasNext())
            {
                QString key_yes = readItYes.next();
                //qDebug() << "iteratorYes: key=" << key_yes;// << " count=" << iCount;
                QString value_yes = settings.value(key_yes,"0").toString();
                if(key == key_yes)
                {
                    qsIsRotated = value_yes;
                    iCount++;
                    cIniFile::Groups->append(qsSection);
                    qDebug() << "iterator: section=" << qsSection << " key=" << key << " count=" << iCount;
                }
            }
        }
        //===
        settings.endGroup();
    }

    if(iCount > 0)
        qDebug() << "IsRotated key detected in " << iCount << " files";
    else
        qDebug() << "No IsRotated key detected";

    //--- Окончание функции загрузки

    settings.sync();

    return Result;
}
