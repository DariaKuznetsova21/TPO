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

void FileChecker::setExist(const bool flag)
{
    exist = flag;
}

void FileChecker::setLastTime(QDateTime time)
{
    lastModified = time;
}

void FileChecker::setNewSize(qint64 size)
{
    sizeFile = size;
}

