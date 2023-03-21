#include "Notifier.h"
#include <iostream>

void Notifier::changeExistance(QFileInfo &file, FileChecker &oldFile)
{
    oldFile.update(file);
    if(!oldFile.isExist()){
        std::cout << "File " << oldFile.path().toStdString() << " isn't exist!"<<std::endl;
    }

    else{
        std::cout << "File " << oldFile.path().toStdString() << " is exist with size " << oldFile.size()
                 << " bytes" << std::endl;
    }
}

void Notifier::changeFile(QFileInfo &file, FileChecker &oldFile)
{
    oldFile.update(file);
    std::cout << "File " << oldFile.path().toStdString() << " is exist with size " << oldFile.size()
              << " bytes and was changed!" << std::endl;
}
