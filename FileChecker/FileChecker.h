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
    FileChecker(QString &filePath);
    bool isExist();
    QString path();
    qint64 size();
    QDateTime getLastTime();
    void setExist(const bool flag);
    void setLastTime(QDateTime time);
    void setNewSize(qint64 size);
};

#endif // FILECHECKER_H
