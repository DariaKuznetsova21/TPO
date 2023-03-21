#include "FileManager.h"
#include <iostream>

FileManager::FileManager()
{
    connect(this, &FileManager::existanceChanged, &Notifier::changeExistance);
    connect(this, &FileManager::fileChanged, &Notifier::changeFile);
}

void FileManager::addNewFile(QFileInfo &newFileInfo)
{
    FileChecker newFile(newFileInfo);
    files.push_back(newFile);
}

void FileManager::startToObserve()
{
    while(true){
        qint64 choice;
        std::cout << "Input 1 - to check the states of your files / "
                  << "2 - to exit" <<std::endl;
        std::cin >> choice;
        if(choice == 1){
            for(auto& file : files){
                QFileInfo checkFile(file.path());
                if(changedExistance(checkFile, file)){
                    existanceChanged(checkFile, file);
                }
                else if(changedFile(checkFile, file)){
                    fileChanged(checkFile, file);
                }

                else {
                    if(file.isExist()){
                        std::cout << "File " << file.path().toStdString() << " is exist with size "
                                  << file.size() << " bytes" << std::endl;
                    }
                    else {
                        std::cout << "File " << file.path().toStdString() << " isn't exist!" << std::endl;
                    }
                }
            }
        }
        else if(choice == 2){
            std::cout << "Good bye!" << std::endl;
            return;
        }
        else{
            std::cout << "Try again!!!" << std::endl;
        }
    }
}

bool FileManager::changedExistance(QFileInfo &file, FileChecker &oldFile)
{
    return (file.exists() != oldFile.isExist());
}

bool FileManager::changedFile(QFileInfo &file, FileChecker &oldFile)
{
    return (file.lastModified() != oldFile.getLastTime());
}
