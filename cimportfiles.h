#ifndef CIMPORTFILES_H
#define CIMPORTFILES_H

#include <memory>
#include <QLabel>

#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>

#include "crecord.h"
#include "cinifile.h"

#define MAX_INDEX_DEFAULT_VALUE 100

class cImportFiles
{

public:
    static int MaxIndexValue;
    static int CurrentIndex;
    static QString labelExecStatusText;
    static bool IslabelExecStatusTextChacnged;
    static QStringList Groups;


    static QString labelFileNameText;
    static bool IslabelFileNameTextChanged;

    cImportFiles();

    static bool execImport();
    static bool getGroupsList();

};

#endif // CIMPORTFILES_H
