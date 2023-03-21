#include "FileChecker.h"

FileChecker::FileChecker(QString &filePath)
{
    QFileInfo newFile(filePath);
    if(newFile.exists()){
        exist = true;
        pathFile = newFile.filePath();
        sizeFile = newFile.size();
        lastModified = newFile.lastModified();
    }
    else{
        exist = false;
        pathFile = filePath;
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
