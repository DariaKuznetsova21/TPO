#include "Notifier.h"
#include <iostream>
void Notifier::changeFile(QFileInfo &file, FileChecker &oldFile)
{
    if((oldFile.isExist()) && (!file.exists())){
        std::cout << "File " << oldFile.path().toStdString() << " isn't exist!"<<std::endl;
        oldFile.setExist(false);
    }
    else if((!oldFile.isExist()) && (file.exists())){
        std::cout << "File " << oldFile.path().toStdString() << " is exist with size " << oldFile.size()
                 << " bytes" << std::endl;
        oldFile.setExist(true);
    }

    else {
        std::cout << "File " << oldFile.path().toStdString() << " is exist with size " << oldFile.size()
                  << " bytes and was changed!" << std::endl;
        oldFile.setLastTime(file.lastModified());
        oldFile.setNewSize(file.size());
    }

}

void Notifier::notChangeFile(FileChecker &oldFile)
{
    if(oldFile.isExist()){
        std::cout << "File " << oldFile.path().toStdString() << " is exist with size " << oldFile.size()
                 << " bytes" << std::endl;
    }
    else{
        std::cout << "File " << oldFile.path().toStdString() << " isn't exist!"<<std::endl;
    }
}
