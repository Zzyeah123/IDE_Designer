#ifndef FILENAMELABEL_H
#define FILENAMELABEL_H

// 文件名部件类

#include <QLabel>
#include <QFont>

class FileNameLabel : public QLabel
{
public:
    QFont fileFont;
    FileNameLabel(QString);
};

#endif // FILENAMELABEL_H
