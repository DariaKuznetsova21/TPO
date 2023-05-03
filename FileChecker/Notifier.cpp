#include "Notifier.h"
#include <iostream>
void Notifier::FileNotExist(FileChecker &file)
{
    std::cout << "File " << file.path().toStdString() << " isn't exist!"<<std::endl;
}
void Notifier::FileExist(FileChecker &file)
{
    std::cout << "File " << file.path().toStdString() << " is exist with size " << file.size()
             << " bytes, " << file.getLastTime().toString("hh:mm:ss dd.MM.yyyy").toStdString() << " last modified time" <<std::endl;
}
void Notifier::changeFile(FileChecker &file)
{
    std::cout << "File " << file.path().toStdString() << " is exist with size " << file.size()
              << " bytes and was changed, " << file.getLastTime().toString("hh:mm:ss dd.MM.yyyy").toStdString()
              << " last modified time" <<std::endl;
}

