#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "Notifier.h"

class FileManager : public QObject  //наследуется от qo
{
    Q_OBJECT

    QVector<FileChecker> files;
public:
    FileManager();
    void addNewFile(QString &newFileInfo);
    void observe();
    bool changedFile(QFileInfo& file, FileChecker& oldFile);

signals:
    void fileExist(FileChecker& file);
    void fileNotExist(FileChecker& file);
    void fileChanged(FileChecker& file);
};

#endif // FILEMANAGER_H
