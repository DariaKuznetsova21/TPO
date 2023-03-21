#ifndef FILECHECKER_H
#define FILECHECKER_H
#include <QFileInfo>
#include <QVector>
#include <QDateTime>

//Проверяет существование файла и его 
class FileChecker
{
    bool exist;
    QString pathFile;
    qint64 sizeFile;
    QDateTime lastModified;
public:
    FileChecker() = default;
    FileChecker(QFileInfo& file);
    bool isExist();
    QString path();
    qint64 size();
    QDateTime getLastTime();
    void update(QFileInfo& file);
};

#endif // FILECHECKER_H
