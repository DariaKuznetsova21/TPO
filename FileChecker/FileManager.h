#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <Notifier.h>

class FileManager : public QObject
{
    Q_OBJECT

    QVector<FileChecker> files;
public:
    FileManager();
    void addNewFile(QFileInfo& newFileInfo);
    void startToObserve();
    bool changedExistance(QFileInfo& file, FileChecker& oldFile);
    bool changedFile(QFileInfo& file, FileChecker& oldFile);

signals:
    void existanceChanged(QFileInfo& file, FileChecker& oldFile);
    void fileChanged(QFileInfo& file, FileChecker& oldFile);
};

#endif // FILEMANAGER_H
