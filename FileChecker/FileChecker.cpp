#include "FileChecker.h"

FileChecker::FileChecker(QFileInfo &file)
{
    if(file.exists()){
        exist = true;
        pathFile = file.filePath();
        sizeFile = file.size();
        lastModified = file.lastModified();
    }
    else{
        exist = false;
        pathFile = "";
        sizeFile = 0;
        lastModified = QDateTime();
    }
}

bool FileChecker::isExist()
{
    return exist;
}

QString FileChecker::path()
{
    return pathFile;
}

qint64 FileChecker::size()
{
    return sizeFile;
}

QDateTime FileChecker::getLastTime()
{
    return lastModified;
}

void FileChecker::update(QFileInfo &file)
{
    exist = file.exists();
    pathFile = file.filePath();
    sizeFile = file.size();
    lastModified = file.lastModified();
}
