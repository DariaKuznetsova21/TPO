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
            manager.addNewFile(newFile);
        }
    }
    std::cout << "Start to observe" << std::endl;
    while(true){
        manager.observe();
    }

    return a.exec();
}
