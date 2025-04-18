#include "cinifile.h"

//=============================================================================
//Глобальные переменные
//=============================================================================

// Путь к INI-файлу
#ifdef HOME_STORAGE
    QString cIniFile::iniFilePath = "/home/andy/MyQtProjects/PicturesControl0/programm/data/FilesConfigPhotos.ini";
    QString cIniFile::rotatedImagePath = "/home/andy/MyQtProjects/PicturesControl0/programm/img/tmp/rotated_image.png";
    QString cIniFile::scaledImagePath = "/home/andy/MyQtProjects/PicturesControl0/programm/img/tmp/scaled_image.png";
#else
    QString cIniFile::iniFilePath = "C:/WORK/PicturesControl/PicturesControl0/programm/data/FilesConfigShips.ini";
    QString cIniFile::rotatedImagePath = "C:/WORK/PicturesControl/PicturesControl0/programm/img/tmp/rotated_image.png";
    QString cIniFile::scaledImagePath = "C:/WORK/PicturesControl/PicturesControl0/programm/img/tmp/scaled_image.png";
#endif

    QString cIniFile::currentImagePath = "";
    QString cIniFile::currentRotatedImagePath = "";

    QStringList * cIniFile::Groups;
    QStringList * cIniFile::Keys;
    QStringList * cIniFile::SearchKeys;

    QStringList * cIniFile::currentGroups;

    QList<cRecord> * cRecord::RecordList;

    //QSettings cIniFile::settings(cIniFile::iniFilePath, QSettings::IniFormat);//20250417

// Путь к каталогу, который нужно прочитать.
#ifdef HOME_STORAGE
    cIniFile cIniFile::IniFile("/home/andy/From Smartfone");
#else
    cIniFile cIniFile::IniFile("C:/Work/Ships");
#endif


cIniFile::cIniFile(QString sourcePath)
{
    directoryPath = sourcePath;
    qDebug() << "INI file created at: " << sourcePath;//cIniFile::iniFilePath;
}

QString cIniFile::getDirectoryPah()
{
    return directoryPath;
}

void cIniFile::addInitalSection(int n)
{
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);
    cIniFile::IniFile.iRecordListLength = n;

    settings.beginGroup("RecordList");
    settings.setValue("root_path", cIniFile::IniFile.getDirectoryPah());
    settings.setValue("length", cIniFile::IniFile.iRecordListLength);
    settings.setValue("index", 0);
    settings.endGroup();
    settings.sync();
}
/******************************************************************************
 * Функция добавления данных из списка QList<cRecord> в конфигурационный файл
 *
 *****************************************************************************/
void cIniFile::addRecordListData()
{
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);
    iCurrentIndexGlobal.store(0);
    for(QList<cRecord>::iterator it = cRecord::RecordList->begin(); it != cRecord::RecordList->end(); ++it)
     {
        iCurrentIndexGlobal.fetch_add(1, std::memory_order_relaxed);

        const cRecord rec = *it;

        QString name = rec.qsName;
        int iDotPosition = name.indexOf('.');
        QString groupName = name.mid(0, iDotPosition);

        QString path = rec.qsPath;
        int iNamePosition = path.indexOf(name);
        QString PathWithoutName = path.mid(0, iNamePosition - 1);

        int size = rec.iSize ;

        int iExtensionPosition = path.indexOf('.');
        QString qsExtension = path.mid(iExtensionPosition + 1);

        bool IsError = false;
        int width = 0;
        int height = 0;

        if(qsExtension.toLower() == "mp4")
        {
            qDebug() << "Id=" << iCurrentIndexGlobal.load(std::memory_order_relaxed) << "Extension: mp4";
            IsError = true;
        }
        else
        {
            //Фрагмент для обработки файлов изображений
            QImage image(path);//name

            width = image.width();
            height = image.height();
            qDebug() << "Id=" << iCurrentIndexGlobal.load(std::memory_order_relaxed);
        }

            int id = iCurrentIndexGlobal.load(std::memory_order_relaxed);

            settings.beginGroup(groupName);
            settings.setValue("Id", id);
            settings.setValue("name", name);
            settings.setValue("path", PathWithoutName);
            settings.setValue("size", size);
            if(IsError)
            {
                settings.setValue("error", true);
            }
            else
            {
                settings.setValue("width", width);
                settings.setValue("height", height);
            }
            settings.endGroup();

    }//End of for(QList<cRecord>::iterator it = cRecord::RecordList->begin(); it != cRecord::RecordList->end(); ++it)
    settings.sync();
    qDebug() << "==================Task is done!!!=========================";
}

void cIniFile::getCurrentImagePath()
{
    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);
    QString imagePath = "";

    //--- Читаем значения из INI-файла
    QString GroupName = cIniFile::Groups->at(iCurrentIndexGlobal.load(std::memory_order_relaxed));

    settings.beginGroup(GroupName);

    QString qsPath = settings.value("path","").toString();
    QString qsName = settings.value("name","").toString();

    settings.endGroup();

    imagePath = qsPath + '/' + qsName;
    qDebug() << "OriginalPath:" << imagePath;

    cIniFile::currentImagePath = imagePath;

    settings.sync();
}

int cIniFile::getCurrentIndex()
{
    std::unique_ptr<bool> ptrOk = std::make_unique<bool>(true);
    bool* Ok = ptrOk.get();

    QSettings settings(cIniFile::iniFilePath, QSettings::IniFormat);
    // Читаем значение текущего индекса из INI-файла
    settings.beginGroup("RecordList");

    QString qsCurrentIndex = settings.value("index", "0").toString();
    int LoadedCurrentIndex = qsCurrentIndex.toInt(Ok);
    if(!*Ok)LoadedCurrentIndex = 0;

    qDebug() << "Loaded CurrentIndex:" << LoadedCurrentIndex;

    return LoadedCurrentIndex;
}

