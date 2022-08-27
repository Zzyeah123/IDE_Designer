#ifndef PLAINTEXTEDIT_H
#define PLAINTEXTEDIT_H

// 编辑器部件

#include <QFont>
#include <QPlainTextEdit>

class PlainTextEdit : public QPlainTextEdit
{
    Q_OBJECT
public:
    PlainTextEdit();
    QFont codeFont;

public slots:
    void SendTextToFile();
signals:
    SendText(QString Text);//发送文本给文件保存函数
};

#endif // PLAINTEXTEDIT_H
