#include "FramelessWindow.h"




class FramelessWindowPrivate {
public:
    FramelessWindowPrivate(QWidget *contentWidget) : contentWidget(contentWidget) {}

    QWidget *contentWidget;
};

FramelessWindow::FramelessWindow(QWidget *parent) : QWidget(parent) {

    setWindowFlags(Qt::FramelessWindowHint);    // 去掉边框
    setAttribute(Qt::WA_TranslucentBackground); // 背景透明
    setMouseTracking(true); // 随时监测鼠标位置


    //ScreenButton类中包含左上角三个按钮，分别控制关闭窗口，窗口最小化和窗口最大化
    ScreenButton *screenButton = new ScreenButton();
    // 连接三个按钮的槽函数
    connect(screenButton->quitButton, &QPushButton::clicked, this, &QWidget::close);
    connect(screenButton->minButton, &QPushButton::clicked, this, &QWidget::showMinimized);
    connect(screenButton->maxButton, &QPushButton::clicked, this, &FramelessWindow::maxScreen);

    // 左侧的文件列表（未完成）
    fileList = new FileList();
    // 右侧的编辑器
    plainTextEdit = new PlainTextEdit();

    // 测试用，显示一个文件名
    //setFileName("FileName.c");
    fileName="FileName.c";
    // 顶端中部显示文件名
    fileNameLabel = new FileNameLabel(fileName);


    // 创建MenuButton类对象，分别对应每一个菜单栏按钮
    MenuButton* fileButton = new MenuButton("   Files");
    // 创建MainMenu类对象，对应一个菜单
    MainMenu* fileMenu = new MainMenu();
    fileButton->setMenu(fileMenu);
    // 菜单里的数个选项
    //add,新建文件
    QAction* newFileAction = new QAction(this);
    fileMenu->addAction(newFileAction);
    newFileAction->setText(tr("New"));
    //
    QAction* openFileAction = new QAction(this);
    fileMenu->addAction(openFileAction);
    openFileAction->setText(tr("Open"));
    QAction* closeFileAction = new QAction(this);
    fileMenu->addAction(closeFileAction);
    closeFileAction->setText(tr("Close"));
    QAction* saveFileAction = new QAction(this);
    fileMenu->addAction(saveFileAction);
    saveFileAction->setText(tr("Save"));
    QAction* saveAsAction = new QAction(this);
    fileMenu->addAction(saveAsAction);
    saveAsAction->setText(tr("Save As"));
    connect(newFileAction, SIGNAL(triggered()), fileList, SLOT(NewFile()));//新建
    connect(openFileAction, SIGNAL(triggered()), fileList, SLOT(OpenFile()));//打开
    connect(closeFileAction, SIGNAL(triggered()), fileList, SLOT(Close()));//关闭
    connect(saveFileAction, SIGNAL(triggered()), fileList, SLOT(Save()));//保存
    connect(saveAsAction, SIGNAL(triggered()), fileList, SLOT(SaveAs()));//另存

    connect(plainTextEdit,SIGNAL(textChanged()),fileList,SLOT(SetCurrentFilemodified()));//编辑区做出修改

    connect(fileList,SIGNAL(LoadData(QString)),plainTextEdit,SLOT(setPlainText(QString)));//打开文件
    connect(fileList,SIGNAL(ClearText()),plainTextEdit,SLOT(clear()));//关闭或新建
    connect(fileList,SIGNAL(GetText()),plainTextEdit,SLOT(SendTextToFile()));//保存文件，需要编辑区发送文本
    connect(plainTextEdit,SIGNAL(SendText(QString)),fileList,SLOT(GetPlainText(QString)));//编辑区发送文本内容
    connect(fileList,SIGNAL(SetTitle(QString)),this,SLOT(setFileName(QString)));//设置当前文件名

    // 创建MenuButton类对象，分别对应每一个菜单栏按钮
    MenuButton* buildButton = new MenuButton("  Build");
    // 创建MainMenu类对象，对应一个菜单
    MainMenu* buildMenu = new MainMenu();
    buildButton->setMenu(buildMenu);
    // 菜单里的数个选项
    QAction* compileAction = new QAction(this);
    buildMenu->addAction(compileAction);
    compileAction->setText(tr("Compile"));
    connect(saveAsAction, SIGNAL(triggered()), this, SLOT());


    // 设计整体布局
    QVBoxLayout *layout = new QVBoxLayout();
    // 整个的标题题栏底
    QWidget *menuWidget = new QWidget();
    menuWidget->setStyleSheet("border:none; border-radius:20px;background-color:rgb(147, 115, 238)");
    QHBoxLayout *menuLayout = new QHBoxLayout();
    QWidget *emptyWidget = new QWidget();
    // 将标题栏所有部件放到布局中
    menuLayout->addWidget(screenButton->quitButton);
    menuLayout->addWidget(screenButton->minButton);
    menuLayout->addWidget(screenButton->maxButton);
    menuLayout->addWidget(emptyWidget);
    menuLayout->addWidget(fileNameLabel);
    menuLayout->addWidget(emptyWidget);
    menuLayout->addWidget(buildButton);
    menuLayout->addWidget(fileButton);
    menuWidget->setLayout(menuLayout);

    layout->addWidget(menuWidget);


    // 编辑区布局，包括文件列表和编辑器
    QHBoxLayout *editRegion = new QHBoxLayout();
    editRegion->addWidget(fileList);
    editRegion->addWidget(plainTextEdit);
    editRegion->setStretch(0, 2);
    editRegion->setStretch(1, 8);

    layout->addLayout(editRegion);

    QWidget *contentWidget = new QWidget();
    //此处为当前窗口，传递到Frameless窗口
    contentWidget->setLayout(layout);
    contentWidget->setObjectName("contentWidget");
    contentWidget->setStyleSheet("background-color: rgb(228, 228, 228); border-radius: 20px;");


    d = new FramelessWindowPrivate(contentWidget);

    // 添加阴影
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect(contentWidget);
    shadowEffect->setColor(Qt::gray);
    shadowEffect->setBlurRadius(15); // 阴影的大小
    shadowEffect->setOffset(0, 0);
    contentWidget->setGraphicsEffect(shadowEffect);

    // 添加到窗口中
    lo = new QGridLayout();
    lo->addWidget(contentWidget, 0, 0);
    lo->setContentsMargins(10, 10, 10, 10); // 注意和阴影大小的协调
    setLayout(lo);
}

FramelessWindow::~FramelessWindow() {
    delete d;
}


//实现最大化和标准大小的窗口切换
void FramelessWindow::maxScreen()
{
    if (this->isMaximized()) {
        lo->setContentsMargins(10, 10, 10, 10);
        this->showNormal();
    } else {
        lo->setContentsMargins(0, 0, 0, 0);
        this->showMaximized();
    }
}

// 文件名的setter
void FramelessWindow::setFileName(QString name)
{
    this->fileNameLabel->setText(name);
}
