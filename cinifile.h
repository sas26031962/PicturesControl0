#ifndef CINIFILE_H
#define CINIFILE_H

#include <QString>
#include <QSettings>
#include <QDebug>
#include <QImage>
#include <atomic>

#include "crecord.h"

/******************************************************************************
 * === Выбор вариантов работы ===
 * Для работы с хранилищем фотодокументов размаскировать строку под этим
 * комментарием
 * Для работы с тестовым хранилищем изображений для Blender-проектов
 * замаскировать строку под этим комментарием
 *
 *****************************************************************************/

//#define HOME_STORAGE YES

//-----------------------------------------------------------------------------
//Глобальные переменные
//-----------------------------------------------------------------------------

extern std::atomic<int> iCurrentIndexGlobal;

class cIniFile
{
private:
    QString directoryPath;
public:
    //Атрибуты
    static QString iniFilePath;
    static QString rotatedImagePath;
    static QString scaledImagePath;
    static QSettings settings;
    static cIniFile IniFile;

    int iRecordListLength = 0;  //Полное число записей

    //Конструктор
    cIniFile(QString sourcePath);

    //Методы
    QString getDirectoryPah();

    void addInitalSection(int n);
    void addRecordListData();

    static QString getCurrentImagePath(QString group_name);

};

#endif // CINIFILE_H
