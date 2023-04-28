#include <QCoreApplication>
#include <iostream>
#include <QString>
#include "FileManager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FileManager manager;

    QString newFile = "C://files/file.txt";
    manager.addNewFile(newFile);

    QString newFile1 = "C://files/file1.txt";
    manager.addNewFile(newFile1);

    manager.deleteFile(newFile1);

    QString newFile2 = "C://files/file.docx";
    manager.addNewFile(newFile2);

    std::cout << "Start to observe" << std::endl;
    while(true){
        manager.observe();
    }

    return a.exec();
}
