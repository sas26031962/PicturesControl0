#ifndef CIMPORTFILES_H
#define CIMPORTFILES_H

#include <memory>
#include <QLabel>

#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include <atomic>

#include <QProgressBar>
#include "crecord.h"
#include "cinifile.h"

#define MAX_INDEX_DEFAULT_VALUE 100


//-----------------------------------------------------------------------------
//Глобальные переменные
//-----------------------------------------------------------------------------

extern std::atomic<int> iCurrentIndexGlobal;

class cImportFiles
{

public:
    static int MaxIndexValue;
    static QString labelExecStatusText;
    static bool IslabelExecStatusTextChanged;


    static QString labelFileNameText;
    static bool IslabelFileNameTextChanged;

    cImportFiles();

    static void execImport(QProgressBar * bar);
    static bool getGroupsList();
    static bool getKeysList();

};

#endif // CIMPORTFILES_H
