#include "FileList.h"

FileList::FileList()
{

    QFont fileListFont("Microsoft YaHei", 10, 50);
    this->addItem("DragWgt.h");
    this->addItem("FileList.h");
    this->addItem("FileNameLabel.h");
    this->addItem("FramelessWindow.h");
    this->addItem("MainMenu.h");
    this->addItem("MenuButton.h");
    this->addItem("MoveWgt.h");
    this->addItem("PlainTextEdit.h");
    this->addItem("ScreenButton.h");
    this->addItem("FileList.cpp");
    this->addItem("FileNameLabel.cpp");
    this->addItem("FramelessWindow.cpp");
    this->addItem("main.cpp");
    this->addItem("MainMenu.cpp");
    this->addItem("MenuButton.cpp");
    this->addItem("PlainTextEdit.cpp");
    this->addItem("ScreenButton.cpp");
    this->addItem("DragWgt.h");
    this->addItem("FileList.h");
    this->addItem("FileNameLabel.h");
    this->addItem("FramelessWindow.h");
    this->addItem("MainMenu.h");
    this->addItem("MenuButton.h");
    this->addItem("MoveWgt.h");
    this->addItem("PlainTextEdit.h");
    this->addItem("ScreenButton.h");
    this->addItem("FileList.cpp");
    this->addItem("FileNameLabel.cpp");
    this->addItem("FramelessWindow.cpp");
    this->addItem("main.cpp");
    this->addItem("MainMenu.cpp");
    this->addItem("MenuButton.cpp");
    this->addItem("PlainTextEdit.cpp");
    this->addItem("ScreenButton.cpp");
    this->addItem("DragWgt.h");
    this->addItem("FileList.h");
    this->addItem("FileNameLabel.h");
    this->addItem("FramelessWindow.h");
    this->addItem("MainMenu.h");
    this->addItem("MenuButton.h");
    this->addItem("MoveWgt.h");
    this->addItem("PlainTextEdit.h");
    this->addItem("ScreenButton.h");
    this->addItem("FileList.cpp");
    this->addItem("FileNameLabel.cpp");
    this->addItem("FramelessWindow.cpp");
    this->addItem("main.cpp");
    this->addItem("MainMenu.cpp");
    this->addItem("MenuButton.cpp");
    this->addItem("PlainTextEdit.cpp");
    this->addItem("ScreenButton.cpp");

    this->setFont(fileListFont);


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

    this->setStyleSheet("QListWidget{outline:0px;padding:10px;border:none; border-radius:20px;background-color:rgb(242, 239, 249);}"
                        "QListWidget::item{border:none; border-radius:15px;padding:10px;color:rgb(93, 93, 94)}"
                        "QListWidget::item:hover{background:rgb(187, 160, 250)}"
                        "QListWidget::item:selected{background:rgb(147, 115, 238);color:white}");
}
