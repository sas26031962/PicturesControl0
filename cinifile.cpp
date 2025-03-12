#include "cinifile.h"

//=============================================================================
//Глобальные переменные
//=============================================================================

// Путь к INI-файлу
#ifdef HOME_STORAGE
    QString cIniFile::iniFilePath = "/home/andy/MyQtProjects/PicturesControl0/programm/data/FilesConfigPhotos.ini";
#else
    QString cIniFile::iniFilePath = "C:/WORK/PicturesControl0/programm/data/FilesConfigShips.ini";
#endif

QList<cRecord> * cRecord::RecordList;

QSettings cIniFile::settings(cIniFile::iniFilePath, QSettings::IniFormat);

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
    cIniFile::IniFile.iRecordListLength = n;

    cIniFile::settings.beginGroup("RecordList");
    cIniFile::settings.setValue("root_path", cIniFile::IniFile.getDirectoryPah());
    cIniFile::settings.setValue("length", cIniFile::IniFile.iRecordListLength);
    cIniFile::settings.setValue("index", 0);
    cIniFile::settings.endGroup();
}

void cIniFile::addRecordListData()
{
    for(QList<cRecord>::iterator it = cRecord::RecordList->begin(); it != cRecord::RecordList->end(); ++it)
     {
        cIniFile::IniFile.Id++;//Счётчик записей

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
}

