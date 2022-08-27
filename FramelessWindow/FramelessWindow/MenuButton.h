#ifndef MENUBUTTON_H
#define MENUBUTTON_H

// 菜单标题栏按钮部件

#include <QWidget>
#include <QPushButton>
#include <QFont>

class MenuButton : public QPushButton
{
private:
    QFont menuFont;
public:
    MenuButton(QString);
};

#endif // MENUBUTTON_H
