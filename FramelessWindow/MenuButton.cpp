#include "MenuButton.h"

MenuButton::MenuButton(QString buttonName)
{
    QFont menuFont("Microsoft YaHei", 12, 75);
    this->setFixedSize(130, 50);
    this->setStyleSheet("QPushButton{background-color: rgb(147, 115, 238);color:rgb(255, 255, 255);}"
                              "QPushButton::hover{background-color: rgb(187, 160, 250)}"
                              "QPushButton::pressed{background-color: rgb(187, 160, 250)}"
                              "QPushButton::menu-indicator{ image:none;}");
    this->setText(buttonName);
    this->setFont(menuFont);
}
