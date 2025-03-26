#include "cimportfiles.h"

int cImportFiles::CurrentIndex = 0;
int cImportFiles::MaxIndexValue = MAX_INDEX_DEFAULT_VALUE;
QStringList cImportFiles::Groups;

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
 *****************************************************************************/
bool cImportFiles::execImport()
{
    bool IsError = false;

    //-------------------------------------------------------------------------
    // Получить текущее содержимое директория (операция безопасная)
    //-------------------------------------------------------------------------
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
        return IsError;
    }

    //---Отображение даных
    //cRecord::showList();

    //-------------------------------------------------------------------------
    // Добавление данных в файл конфигурации (операция потенциально опасная)
    //-------------------------------------------------------------------------
    /*     ПЕРЕНЕСТИ В КОНЕЦ ПРОДЕДУРЫ
     *
    //---Добавление идентификационной секции
    cImportFiles::MaxIndexValue = cRecord::RecordList->count();
    cIniFile::IniFile.addInitalSection(cImportFiles::MaxIndexValue);

    //---Добавление данных в файл конфигурации
    //cIniFile::IniFile.addRecordListData();
    */
    //-- Перед началом процедуры импорта следует получить список имён групп

    if(getGroupsList())
    {
        qDebug() << "File " << cIniFile::iniFilePath<< " not found, groups list is empty";
    }
    else
    {
        qDebug() << "Groups list length: " << cImportFiles::Groups.count();
    }
    //--- Главный цикл переборки файлов: начало
    for(QList<cRecord>::iterator it = cRecord::RecordList->begin(); it != cRecord::RecordList->end(); ++it)
     {
        cIniFile::IniFile.Id++;//Счётчик записей

        cImportFiles::CurrentIndex = cIniFile::IniFile.Id;

        const cRecord rec = *it;

        QString name = rec.qsName;
        int iDotPosition = name.indexOf('.');
        // Имя группы получается из имени файла путём отбрасывания точки и всего, что после неё
        // На этом этапе необходимо проверять наличие такого имени группы в списке
        QString groupName = name.mid(0, iDotPosition);

        QString path = rec.qsPath;
        int iNamePosition = path.indexOf(name);
        QString PathWithoutName = path.mid(0, iNamePosition - 1);
        /*
        int size = rec.iSize;

        int iExtensionPosition = path.indexOf('.');
        QString qsExtension = path.mid(iExtensionPosition + 1);

        IsError = false;
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
        */
        /*
            //Запись данных в файл (очень опасная операция)
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
        */
    }//End of for(QList<cRecord>::iterator it = cRecord::RecordList->begin(); it != cRecord::RecordList->end(); ++it)

    //--- Главный цикл переборки файлов: начало

    return IsError;
}


//-------------------------------------------------------------------------
// Получить список групп
//-------------------------------------------------------------------------
bool cImportFiles::getGroupsList()
{
    bool IsError = false;
    cImportFiles::Groups.clear();
    QFile file(cIniFile::iniFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Не удалось открыть файл для чтения: " << cIniFile::iniFilePath;
        IsError = true;
        return IsError; // Возвращаем флаг ошибки
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed(); // Читаем строку и убираем пробелы в начале и конце
        if (line.startsWith("[") && line.endsWith("]"))
        {
            QString groupName = line.mid(1, line.length() - 2); // Извлекаем имя секции
            if (!cImportFiles::Groups.contains(groupName))
            {
                cImportFiles::Groups << groupName; // Добавляем в список, если еще не существует
            }
        }
    }

    file.close();

    return IsError;//Возвращаем флаг ошибки

}//End of QStringList cImportFiles::getGroupsList()

