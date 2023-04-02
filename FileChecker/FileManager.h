#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <Notifier.h>

class FileManager : public QObject
{
    Q_OBJECT

    QVector<FileChecker> files;
public:
    FileManager();
    void addNewFile(QString &newFileInfo);
    void observe();
    bool changedFile(QFileInfo& file, FileChecker& oldFile);

signals:
    void fileNotChanged(FileChecker& oldFile);
    void fileChanged(QFileInfo& file, FileChecker& oldFile);
};

#endif // FILEMANAGER_H
