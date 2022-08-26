#ifndef PLAINTEXTEDIT_H
#define PLAINTEXTEDIT_H

// 编辑器部件

#include <QFont>
#include <QPlainTextEdit>

class PlainTextEdit : public QPlainTextEdit
{
public:
    PlainTextEdit();
    QFont codeFont;
};

#endif // PLAINTEXTEDIT_H
