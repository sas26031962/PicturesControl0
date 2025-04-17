#ifndef CLOADFILES_H
#define CLOADFILES_H

#include <QSettings>
#include <memory>
#include <QStringList>

#include "cimportfiles.h"
#include "cinifile.h"

class cLoadFiles
{
public:
    cLoadFiles();
    static bool execLoadFiles();
    static bool execLoadFilesByConditionOrYes(QStringList yes);
};

#endif // CLOADFILES_H
