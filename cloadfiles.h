#ifndef CLOADFILES_H
#define CLOADFILES_H

#include <QSettings>
#include <memory>

#include "cimportfiles.h"
#include "cinifile.h"

class cLoadFiles
{
public:
    cLoadFiles();
    static bool execLoadFiles();
};

#endif // CLOADFILES_H
