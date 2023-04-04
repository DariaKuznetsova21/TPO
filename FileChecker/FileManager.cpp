#include "FileManager.h"
#include <iostream>

FileManager::FileManager()
{
    connect(this, &FileManager::fileChanged, &Notifier::changeFile);
    connect(this, &FileManager::fileAdded, &Notifier::addFile);
}

void FileManager::addNewFile(QString &newFileInfo)
{
    FileChecker newFile(newFileInfo);
    files.push_back(newFile);
    fileAdded(newFile);
}

void FileManager::observe()
{
    for(auto& file : files){
        QFileInfo checkFile(file.path());
        if(changedFile(checkFile, file)){
            fileChanged(checkFile, file);
        }

//        else {
//            fileNotChanged(file);
//        }
    }
}

bool FileManager::changedFile(QFileInfo &file, FileChecker &oldFile)
{
    return ((file.lastModified() != oldFile.getLastTime()) || (file.exists() != oldFile.isExist()) );
}
