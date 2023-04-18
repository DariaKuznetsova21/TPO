#include "Notifier.h"
#include <iostream>
void Notifier::changeFile(QFileInfo &file, FileChecker &oldFile)
{
    if((oldFile.isExist()) && (!file.exists())){
        oldFile.setExist(false);
        oldFile.setLastTime(QDateTime());
        oldFile.setNewSize(0);
        std::cout << "File " << oldFile.path().toStdString() << " isn't exist!"<<std::endl;
    }
    else if((!oldFile.isExist()) && (file.exists())){
        oldFile.setExist(true);
        oldFile.setLastTime(file.lastModified());
        oldFile.setNewSize(file.size());
        std::cout << "File " << oldFile.path().toStdString() << " is exist with size " << oldFile.size()
                 << " bytes" << std::endl;
    }

    else {
        oldFile.setLastTime(file.lastModified());
        oldFile.setNewSize(file.size());
        std::cout << "File " << oldFile.path().toStdString() << " is exist with size " << oldFile.size()
                  << " bytes and was changed!" << std::endl;
    }

}

void Notifier::addFile(FileChecker &newFile)
{
    if(newFile.isExist()){
        std::cout << "File " << newFile.path().toStdString() << " is exist with size " << newFile.size()
                 << " bytes" << std::endl;
    }
    else{
        std::cout << "File " << newFile.path().toStdString() << " isn't exist!"<<std::endl;
    }
}


