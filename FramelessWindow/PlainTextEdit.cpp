#include "PlainTextEdit.h"

PlainTextEdit::PlainTextEdit()
{
    QFont codeFont("Consolas", 12, 2);
    this->setStyleSheet("background-color:rgb(255,255,255);border:none; border-radius:20px;color:rgb(93, 93, 94);"
                            "selection-background-color:rgb(242, 239, 249);selection-color:rgb(147, 115, 238);"
                            "padding: 20px;");

    this->verticalScrollBar()->setStyleSheet(
                "QScrollBar:vertical{width:12px;border-radius:6px}"
                "QScrollBar::handle:vertical{background:rgb(187, 160, 250);border-radius:6px;min-height:20;}"
                "QScrollBar::handle:vertical:hover{background:rgb(147, 115, 238);border-radius:6px;min-height:20;}"
                "QScrollBar::add-line:vertical{height:0px;width:0px;}"
                "QScrollBar::sub-line:vertical{height:0px;width:0px;}"
                "QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{width:0px;background:rgba(242, 239, 249);border-radius:4px;}"
                );
    this->horizontalScrollBar()->setStyleSheet(
                "QScrollBar:horizontal{height:12px;border-radius:6px}"
                "QScrollBar::handle:horizontal{background:rgb(187, 160, 250);border-radius:6px;min-width:20;}"
                "QScrollBar::handle:horizontal:hover{background:rgb(147, 115, 238);border-radius:6px;min-width:20;}"
                "QScrollBar::add-line:horizontal{height:0px;width:0px;}"
                "QScrollBar::sub-line:horizontal{height:0px;width:0px;}"
                "QScrollBar::add-page:horizontal,QScrollBar::sub-page:horizontal{background:rgba(242, 239, 249);border-radius:4px;}"
                );
    this->setFont(codeFont);
}
