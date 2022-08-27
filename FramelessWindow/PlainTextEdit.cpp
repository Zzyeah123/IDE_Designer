#include "PlainTextEdit.h"

PlainTextEdit::PlainTextEdit()
{
    QFont codeFont("Consolas", 12, 2);
    this->setStyleSheet("background-color:rgb(255,255,255);border:none; border-radius:20px;color:rgb(93, 93, 94);"
                            "selection-background-color:rgb(242, 239, 249);selection-color:rgb(147, 115, 238);"
                            "padding: 20px;");
    this->setFont(codeFont);
}
void PlainTextEdit::SendTextToFile(){//编辑发送文本内容至文件
    QString Text=this->toPlainText();
    emit(SendText(Text));
}
