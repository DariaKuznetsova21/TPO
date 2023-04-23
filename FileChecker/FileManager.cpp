#include "FileManager.h"
#include <iostream>

FileManager::FileManager()
{
    connect(this, &FileManager::fileChanged, &Notifier::changeFile);
    connect(this, &FileManager::fileExist, &Notifier::FileExist);
    connect(this, &FileManager::fileNotExist, &Notifier::FileNotExist);
}

void FileManager::addNewFile(QString &newFileInfo)
{
    FileChecker newFile(newFileInfo);
    files.push_back(newFile);
    if(newFile.isExist()){
        emit fileExist(newFile);
    }
    else {
        emit fileNotExist(newFile);
    }
}

void FileManager::observe()
{
    for(auto& file : files){ //
        QFileInfo checkFile(file.path());
        if((file.isExist()) && (!checkFile.exists())){
            file.setExist(false);
            file.setLastTime(QDateTime());
            file.setNewSize(0);
            emit fileNotExist(file);
        }
        else if((!file.isExist()) && (checkFile.exists())){
            file.setExist(true);
            file.setLastTime(checkFile.lastModified());
            file.setNewSize(checkFile.size());
            emit fileExist(file);
        }
        else if(checkFile.lastModified() != file.getLastTime()){
            file.setLastTime(checkFile.lastModified());
            emit fileChanged(file);
        }
    }
}
