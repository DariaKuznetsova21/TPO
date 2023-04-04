#include <QCoreApplication>
#include <iostream>
#include <QString>
#include <QTextStream>
#include "FileManager.h"

QTextStream cin(stdin);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);//Опредление приложения
    FileManager manager;
    qint64 choice;

    QString newFile = "C://files/file.txt";
    manager.addNewFile(newFile);


    std::cout << "Start to observe" << std::endl;
    while(true){
        manager.observe();
    }

    return a.exec();//Запуск приложения по дефолту
}
