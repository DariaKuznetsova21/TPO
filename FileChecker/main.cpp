#include <QCoreApplication>
#include <iostream>
#include <QString>
#include <QTextStream>
#include "FileManager.h"

QTextStream cin(stdin);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FileManager manager;
    qint64 choice;

    std::cout<<"Hello, it's a FileChecker!"<<std::endl;

    while(true){
        std::cout<<"Do you want to add some file for observer?(1-yes/Any-no): ";
        cin >> choice;
        if(choice != 1){
            break;
        }
        else{
            std::cout << "Input absolute path to file: ";
            QString newFile;
            cin >> newFile;
            QFileInfo newFileInfo(newFile);
            manager.addNewFile(newFileInfo);
        }
    }
    std::cout << "Start to observe" << std::endl;
    manager.startToObserve();

    return a.exec();
}
