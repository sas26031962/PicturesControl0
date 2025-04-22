#ifndef CLOADFILES_H
#define CLOADFILES_H

#include <QSettings>
#include <memory>
#include <QStringList>
#include <QFile>
#include <QTextStream>

#include "cimportfiles.h"
#include "cinifile.h"

class cLoadFiles
{
public:
    cLoadFiles();
    static bool execLoadFiles();
    static bool execLoadFilesByConditionOrYes(QStringList yes);
    static bool saveStringListToFile(const QString& fileName, const QStringList& list);
    static QStringList loadStringListFromFile(const QString& fileName);

};

#endif // CLOADFILES_H
