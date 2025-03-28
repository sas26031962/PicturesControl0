#include "cimportfiles.h"

int cImportFiles::CurrentIndex = 0;
int cImportFiles::MaxIndexValue = MAX_INDEX_DEFAULT_VALUE;
QStringList * cImportFiles::Groups = nullptr;

QString cImportFiles::labelExecStatusText = "";
bool cImportFiles::IslabelExecStatusTextChacnged = false;

QString cImportFiles::labelFileNameText = "";
bool cImportFiles::IslabelFileNameTextChanged = false;


cImportFiles::cImportFiles()
{

}

/******************************************************************************
 * Статическая функция bool cImportFiles::execImport() выполняет чтение
 * каталога - источника. Путь к каталогу задаётся при компиляции программы
 * и определяется исходя из состояния определения параметра HOME_STORAGE,
 * заданного в файле cinifile.h.
 * Целевым файлом функции является ini файл, имя которого задаётся при компиляции
 * программы и определяется исходя из состояния определения параметра HOME_STORAGE,
 * заданного в файле cinifile.h.
 * Удалять файлы из каталога - источника запрещается!
 * Удалять секции из целевого ini файла запрещается!
 * Приведённая ниже функция производит добавление секций в целевой ini файл
 * СОДЕРЖИМОЕ КОНФИГУРАЦИОННОГО ФАЙЛА ОБНОВЛЯЕТСЯ, НО НЕ ПЕРЕЗАПИСЫВАЕТСЯ
 * Файлы с расширениями "mp4", "tif", "txt" в конфигурационный файл не добавляются
 *****************************************************************************/
void cImportFiles::execImport()
{
    //---Добавление идентификационной секции
    cImportFiles::MaxIndexValue = cRecord::RecordList->count();
    cIniFile::IniFile.addInitalSection(cImportFiles::MaxIndexValue);

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
        else if(qsExtension.toLower() == "tif")
        {
            qDebug() << "Id=" << cIniFile::IniFile.Id << "Extension: tif";
            IsError = true;
        }
        else if(qsExtension.toLower() == "txt")
        {
            qDebug() << "Id=" << cIniFile::IniFile.Id << "Extension: txt";
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

}//End of bool cImportFiles::execImport()


//-------------------------------------------------------------------------
// Получить список групп
//-------------------------------------------------------------------------
bool cImportFiles::getGroupsList()
{
    bool IsError = false;
    cImportFiles::Groups->clear();
    QFile file(cIniFile::iniFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Не удалось открыть файл для чтения: " << cIniFile::iniFilePath;
        IsError = true;
        return IsError; // Возвращаем флаг ошибки
    }

    qDebug() << "###getGroupsList from " << cIniFile::iniFilePath << " begin";
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed(); // Читаем строку и убираем пробелы в начале и конце
        if (line.startsWith("[") && line.endsWith("]"))
        {
            QString groupName = line.mid(1, line.length() - 2); // Извлекаем имя секции
            if (!cImportFiles::Groups->contains(groupName))
            {
                //Чтение списка ключей
                cIniFile::settings.beginGroup(groupName);
                QList<QString> keys = cIniFile::settings.childKeys();
                int iKeysCount = keys.count();
                cIniFile::settings.endGroup();
                //Формирование сообщения
                QString s = groupName;
                s += ": ";
                s += QString::number(iKeysCount);
                //Вывод сообщения в список
                cImportFiles::Groups->append(s); // Добавляем в список, если еще не существует
            }
            else
            {
                qDebug() << "Section already exist: " << groupName;
            }
        }
    }

    file.close();

    qDebug() << "###getGroupsList from " << cIniFile::iniFilePath << " complete";

    return IsError;//Возвращаем флаг ошибки

}//End of QStringList cImportFiles::getGroupsList()

