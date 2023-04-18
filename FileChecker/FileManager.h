#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "Notifier.h"

class FileManager : public QObject  //наследуется от qo
{
    Q_OBJECT //определчяем макрос класса QO

    QVector<FileChecker> files;
public:
    FileManager();
    void addNewFile(QString &newFileInfo);
    void observe();
    bool changedFile(QFileInfo& file, FileChecker& oldFile);

signals:
    void fileAdded(FileChecker& newFile);
    void fileChanged(QFileInfo& file, FileChecker& oldFile);
};

#endif // FILEMANAGER_H
