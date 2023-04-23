#ifndef NOTIFIER_H
#define NOTIFIER_H

#include <QString>
#include <QObject>
#include <FileChecker.h>

class Notifier : public QObject
{
    Q_OBJECT
public:
    Notifier() = default;
public slots:
    static void changeFile(FileChecker& oldFile);
    static void FileExist(FileChecker& oldFile);
    static void FileNotExist(FileChecker& oldFile);
};

#endif // NOTIFIER_H
