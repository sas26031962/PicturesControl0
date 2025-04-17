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

    // Служебная переменная для выполнения преобразований
//    std::unique_ptr<bool> ptrOk = std::make_unique<bool>(true);
//    bool* Ok = ptrOk.get();

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
}
