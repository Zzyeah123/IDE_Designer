#ifndef MAINMENU_H
#define MAINMENU_H

// 单个菜单部件

#include <QFont>
#include <QMenu>

class MainMenu : public QMenu
{
private:
    QFont actionFont;
public:
    MainMenu();
};

#endif // MAINMENU_H
