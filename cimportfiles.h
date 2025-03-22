#ifndef CIMPORTFILES_H
#define CIMPORTFILES_H

#include <memory>
#include <QLabel>

#include "crecord.h"
#include "cinifile.h"

class cImportFiles
{
//    bool IsError = false;
public:
    static int CurrentIndex;
    static QString labelExecStatusText;
    static bool IslabelExecStatusTextChacnged;

    static QString labelFileNameText;
    static bool IslabelFileNameTextChanged;

    cImportFiles();

static bool execImport();

};

#endif // CIMPORTFILES_H
