#include "SearchLineEdit.h"
#include "TitleMenu.h"
#include "mtitlewidget.h"

#include <Base/basePushButton.h>
#include <QContextMenuEvent>
#include <QHBoxLayout>
#include <QLabel>
#include <QPainter>
#include <QStyleOption>
#include <QDebug>

mTitleWidget::mTitleWidget(QWidget *parent)
    : baseTitleBar(parent)
    , m_iconButton(new basePushButton(this))
    , m_loginButton(new basePushButton(this))
    , m_lineLabel(new QLabel(this))
    , m_registerButton(new basePushButton(this))
    , m_returnButton(new basePushButton(this))
    , m_refreshButton(new basePushButton(this))
    , m_searchLineEdit(new SearchLineEdit(this))
    , m_toolButton(new basePushButton(this))
    , m_gameButton(new basePushButton(this))
    , m_newsButton(new basePushButton(this))
    , m_skinButton(new basePushButton(this))
    , m_menuButton(new basePushButton(this))
    , m_lineLabel_2(new QLabel(this))
    , m_remoteButton(new basePushButton(this))
    , m_hideMusicLibraryButton(new basePushButton(this))
    , m_minimizeButton(new basePushButton(this))
    , m_closeButton(new basePushButton(this))
    , m_titleMenu(new TitleMenu(this))
{
    initForm();
    initWidget();
    initConnect();
}

mTitleWidget::~mTitleWidget()
{
}

void mTitleWidget::contextMenuEvent(QContextMenuEvent *event)
{
    //使右击在按钮时 不显示菜单
    bool inIconButton = m_titleMenu->inChild(m_iconButton);
    bool inLoginButton = m_titleMenu->inChild(m_loginButton);
    bool inRegisterButton = m_titleMenu->inChild(m_registerButton);
    bool inReturnButton = m_titleMenu->inChild(m_returnButton);
    bool inRefreshButton = m_titleMenu->inChild(m_refreshButton);
    bool inToolButton = m_titleMenu->inChild(m_toolButton);
    bool inGameButton = m_titleMenu->inChild(m_gameButton);
    bool inNewsButton = m_titleMenu->inChild(m_newsButton);
    bool inSkinButton = m_titleMenu->inChild(m_skinButton);
    bool inMenuButton = m_titleMenu->inChild(m_menuButton);
    bool inRemoteButton = m_titleMenu->inChild(m_remoteButton);
    bool inHideButton = m_titleMenu->inChild(m_hideMusicLibraryButton);
    bool inMinimizeButton = m_titleMenu->inChild(m_minimizeButton);
    bool inCloseButton = m_titleMenu->inChild(m_closeButton);

    if (!inIconButton && !inLoginButton && !inRegisterButton && !inReturnButton &&
            !inRefreshButton && !inToolButton && !inGameButton && !inNewsButton &&
            !inSkinButton && !inMenuButton && !inRemoteButton && !inHideButton &&
            !inMinimizeButton && !inCloseButton)
        m_titleMenu->exec(QCursor::pos()+QPoint(5,5));

    event->accept();
}

void mTitleWidget::initForm()
{
    setMinimumHeight(50);
    setMaximumHeight(50);

    setObjectName("titleBar");
    m_iconButton->setObjectName("iconBtn");
    m_loginButton->setObjectName("loginBtn");
    m_lineLabel->setObjectName("lineLabel");
    m_registerButton->setObjectName("registerBtn");
    m_returnButton->setObjectName("returnBtn");
    m_refreshButton->setObjectName("refreshBtn");
    m_searchLineEdit->setObjectName("searchLineEdit");
    m_toolButton->setObjectName("toolBtn");
    m_gameButton->setObjectName("gameBtn");
    m_newsButton->setObjectName("newsBtn");
    m_skinButton->setObjectName("skinBtn");
    m_menuButton->setObjectName("menuBtn");
    m_lineLabel_2->setObjectName("lineLabel2");
    m_remoteButton->setObjectName("remoteBtn");
    m_hideMusicLibraryButton->setObjectName("hideMLBtn");
    m_minimizeButton->setObjectName("minimizeBtn");
    m_closeButton->setObjectName("closeBtn");

    m_lineLabel->setFixedSize(1, 11);
    m_lineLabel_2->setFixedSize(1, 11);

    m_loginButton->setText("登录");
    m_registerButton->setText("注册");

    m_returnButton->setToolTip("返回");
    m_refreshButton->setToolTip("刷新");
    m_toolButton->setToolTip("工具");
    m_gameButton->setToolTip("网页游戏平台");
    m_newsButton->setToolTip("消息通知");
    m_skinButton->setToolTip("更换皮肤");
    m_menuButton->setToolTip("主菜单");
    m_remoteButton->setToolTip("打开遥控器");
    m_hideMusicLibraryButton->setToolTip("隐藏音乐库");
    m_minimizeButton->setToolTip("最小化");
    m_closeButton->setToolTip("关闭");
}

void mTitleWidget::initWidget()
{
    QHBoxLayout *leftLayout = new QHBoxLayout();
    leftLayout->addSpacing(7);
    leftLayout->addWidget(m_iconButton);
    leftLayout->addSpacing(6);
    leftLayout->addWidget(m_loginButton);
    leftLayout->addSpacing(3);
    leftLayout->addWidget(m_lineLabel);
    leftLayout->addWidget(m_registerButton);
    leftLayout->addStretch();

    QWidget *leftWidget = new QWidget(this);
    leftWidget->setMinimumWidth(310);
    leftWidget->setMaximumWidth(380);
    leftWidget->setLayout(leftLayout);

    QHBoxLayout *rightLayout = new QHBoxLayout();
    rightLayout->addWidget(m_returnButton);
    rightLayout->addSpacing(6);
    rightLayout->addWidget(m_refreshButton);
    rightLayout->addSpacing(13);
    rightLayout->addWidget(m_searchLineEdit);
    rightLayout->addStretch();
    rightLayout->addWidget(m_toolButton);
    rightLayout->addSpacing(7);
    rightLayout->addWidget(m_gameButton);
    rightLayout->addSpacing(6);
    rightLayout->addWidget(m_newsButton);
    rightLayout->addSpacing(6);
    rightLayout->addWidget(m_skinButton);
    rightLayout->addSpacing(6);
    rightLayout->addWidget(m_menuButton);
    rightLayout->addSpacing(10);
    rightLayout->addWidget(m_lineLabel_2);
    rightLayout->addSpacing(8);
    rightLayout->addWidget(m_remoteButton);
    rightLayout->addSpacing(3);
    rightLayout->addWidget(m_hideMusicLibraryButton);
    rightLayout->addSpacing(1);
    rightLayout->addWidget(m_minimizeButton);
    rightLayout->addSpacing(2);
    rightLayout->addWidget(m_closeButton);

    rightLayout->setSpacing(0);

    QHBoxLayout *mainLayout = new QHBoxLayout();
//    mainLayout->addLayout(leftLayout, 3);
    mainLayout->addWidget(leftWidget, 3);
    mainLayout->addLayout(rightLayout, 7);

    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0,0,11,0);

    setLayout(mainLayout);
}

void mTitleWidget::initConnect()
{
    connect(m_hideMusicLibraryButton, &QPushButton::clicked, this, &mTitleWidget::hideMusizLibrary);
    connect(m_minimizeButton, &QPushButton::clicked, this, &mTitleWidget::minimizeApp);
    connect(m_closeButton, &QPushButton::clicked, this, &mTitleWidget::closeApp);
}
