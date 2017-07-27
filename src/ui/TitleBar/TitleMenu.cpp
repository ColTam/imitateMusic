#include "TitleMenu.h"

#include <QDebug>
#include <qevent.h>

TitleMenu::TitleMenu(QWidget *parent)
    : baseMenu(parent)
    , m_loginAction(new QAction(this))
    , m_addMusicMenu(new baseMenu(this))
    , m_addMusicFileAction(new QAction(this))
    , m_addMusicDirAction(new QAction(this))
    , m_modeMenu(new baseMenu(this))
    , m_modeActionGroup(new QActionGroup(this))
    , m_modeOnceAction(new QAction(this))
    , m_modeSingleAction(new QAction(this))
    , m_modeOrdinalAction(new QAction(this))
    , m_modeListAction(new QAction(this))
    , m_modeRandomAction(new QAction(this))
    , m_modeAutoAction(new QAction(this))
    , m_remoteMenu(new baseMenu(this))
    , m_remoteCudeAction(new QAction(this))
    , m_remoteBarAction(new QAction(this))
    , m_remoteHideAction(new QAction(this))
    , m_equalizerAction(new QAction(this))
    , m_plugAction(new QAction(this))
    , m_timerAction(new QAction(this))
    , m_stickAction(new QAction(this))
    , m_defaultAction(new QAction(this))
    , m_loadSettingMenu(new baseMenu(this))
    , m_loadActionGroup(new QActionGroup(this))
    , m_loadFullSpeedAction(new QAction(this))
    , m_loadCustomSpeedAction(new QAction(this))
    , m_loadSaveBandWidthAction(new QAction(this))
    , m_updateOnlineAction(new QAction(this))
    , m_showNewsAction(new QAction(this))
    , m_helpMenu(new baseMenu(this))
    , m_helpAction(new QAction(this))
    , m_feedbackAction(new QAction(this))
    , m_aboutAction(new QAction(this))
    , m_settingAction(new QAction(this))
    , m_exitAction(new QAction(this))
{
    initForm();
    initConnect();

//    setMouseTracking(true);
}

TitleMenu::~TitleMenu()
{

}

void TitleMenu::mouseMoveEvent(QMouseEvent *event)
{
    if (m_loginAction == actionAt(event->pos()))
        m_loginAction->setIcon(QIcon("://resource/image/menu/menu_login_light.png"));
    else if (m_equalizerAction == actionAt(event->pos()))
        m_equalizerAction->setIcon(QIcon("://resource/image/menu/equalizer_light.png"));
    else if (m_updateOnlineAction == actionAt(event->pos()))
        m_updateOnlineAction->setIcon(QIcon("://resource/image/menu/onlineUp_light.png"));
    else if (event->pos().x() >=0 && event->pos().x() <= 176 && event->pos().y() >= 402 && event->pos().y() <= 431) {
//        qDebug() << (actionAt(event->pos())->text() == "帮助与意见反馈");
        m_helpMenu->setIcon(QIcon("://resource/image/menu/help_light.png"));
        m_settingAction->setIcon(QIcon("://resource/image/menu/setting_dark.png"));
    } else if (m_settingAction == actionAt(event->pos())) {
        m_settingAction->setIcon(QIcon("://resource/image/menu/setting_light.png"));
        m_helpMenu->setIcon(QIcon("://resource/image/menu/help_dark.png"));
    } else if (m_exitAction == actionAt(event->pos()))
        m_exitAction->setIcon(QIcon("://resource/image/menu/exit_light.png"));
    else {
        m_loginAction->setIcon(QIcon("://resource/image/menu/menu_login_dark.png"));
        m_equalizerAction->setIcon(QIcon("://resource/image/menu/equalizer_dark.png"));
        m_updateOnlineAction->setIcon(QIcon("://resource/image/menu/onlineUp_dark.png"));
        m_helpMenu->setIcon(QIcon("://resource/image/menu/help_dark.png"));
        m_settingAction->setIcon(QIcon("://resource/image/menu/setting_dark.png"));
        m_exitAction->setIcon(QIcon("://resource/image/menu/exit_dark.png"));
    }

    QMenu::mouseMoveEvent(event);
}

void TitleMenu::initForm()
{
    m_addMusicMenu->setObjectName("menu_addMusic");
    m_remoteMenu->setObjectName("menu_remote");

    m_loginAction->setText("登录");
    m_addMusicMenu->setTitle("添加歌曲");
    m_addMusicFileAction->setText("添加本地歌曲...");
    m_addMusicDirAction->setText("添加本地歌曲文件夹...");
    m_modeMenu->setTitle("播放模式");
    m_modeOnceAction->setText("单曲播放");
    m_modeSingleAction->setText("单曲循环");
    m_modeOrdinalAction->setText("顺序播放");
    m_modeListAction->setText("列表循环");
    m_modeRandomAction->setText("随机播放");
    m_modeAutoAction->setText("自动切换列表");
    m_remoteMenu->setTitle("遥控器");
    m_remoteCudeAction->setText("魔方遥控器");
    m_remoteBarAction->setText("条形遥控器");
    m_remoteHideAction->setText("隐藏遥控器");
    m_equalizerAction->setText("均衡器");
    m_plugAction->setText("音效插件");
    m_timerAction->setText("定时设置");
    m_stickAction->setText("界面总在最前");
    m_defaultAction->setText("恢复窗口默认状态");
    m_loadSettingMenu->setTitle("下载设置");
    m_loadFullSpeedAction->setText("全速下载");
    m_loadCustomSpeedAction->setText("自定义");
    m_loadSaveBandWidthAction->setText("节省带宽(仅本次有效)");
    m_updateOnlineAction->setText("在线升级");
    m_showNewsAction->setText("显示今日推荐");
    m_helpMenu->setTitle("帮助与意见反馈");
    m_helpAction->setText("使用帮助");
    m_feedbackAction->setText("意见反馈");
    m_aboutAction->setText("关于酷狗(2017/5/12)");
    m_settingAction->setText("设置");
    m_exitAction->setText("退出");

    m_loginAction->setIcon(QIcon("://resource/image/menu/menu_login_dark.png"));
    m_equalizerAction->setIcon(QIcon("://resource/image/menu/equalizer_dark.png"));
    m_updateOnlineAction->setIcon(QIcon("://resource/image/menu/onlineUp_dark.png"));
    m_helpMenu->setIcon(QIcon("://resource/image/menu/help_dark.png"));
    m_helpAction->setIcon(QIcon("://resource/image/menu/usehelp_dark.png"));
    m_feedbackAction->setIcon(QIcon("://resource/image/menu/feedback_dark.png"));
    m_aboutAction->setIcon(QIcon("://resource/image/menu/_dark.png"));
    m_settingAction->setIcon(QIcon("://resource/image/menu/setting_dark.png"));
    m_exitAction->setIcon(QIcon("://resource/image/menu/exit_dark.png"));

//    m_loginAction
//    connect(m_loginAction, &QAction::hovered, [this](){ m_loginAction->setIcon(QPixmap("://resource/image/menu/menu_login_selection.png")); });
//    connect(m_loginAction, &QAction::changed, [this](){
//        if (m_loginAction->)m_loginAction->setIcon(QPixmap("://resource/image/menu/menu_login.png")); });

    m_addMusicMenu->addAction(m_addMusicFileAction);
    m_addMusicMenu->addAction(m_addMusicDirAction);

    m_modeMenu->addAction(m_modeActionGroup->addAction(m_modeOnceAction));
    m_modeMenu->addAction(m_modeActionGroup->addAction(m_modeSingleAction));
    m_modeMenu->addAction(m_modeActionGroup->addAction(m_modeOrdinalAction));
    m_modeMenu->addAction(m_modeActionGroup->addAction(m_modeListAction));
    m_modeMenu->addAction(m_modeActionGroup->addAction(m_modeRandomAction));
    m_modeMenu->addSeparator();
    m_modeMenu->addAction(m_modeAutoAction);

    m_modeOnceAction->setCheckable(true);
    m_modeSingleAction->setCheckable(true);
    m_modeOrdinalAction->setCheckable(true);
    m_modeListAction->setCheckable(true);
    m_modeRandomAction->setCheckable(true);
    m_modeAutoAction->setCheckable(true);
    m_modeOnceAction->setChecked(true);

    m_remoteMenu->addAction(m_remoteCudeAction);
    m_remoteMenu->addAction(m_remoteBarAction);
    m_remoteMenu->addAction(m_remoteHideAction);

    m_loadSettingMenu->addAction(m_loadActionGroup->addAction(m_loadFullSpeedAction));
    m_loadSettingMenu->addAction(m_loadActionGroup->addAction(m_loadCustomSpeedAction));
    m_loadSettingMenu->addSeparator();
    m_loadSettingMenu->addAction(m_loadActionGroup->addAction(m_loadSaveBandWidthAction));

    m_loadFullSpeedAction->setCheckable(true);
    m_loadCustomSpeedAction->setCheckable(true);
    m_loadSaveBandWidthAction->setCheckable(true);
    m_loadFullSpeedAction->setChecked(true);

    m_helpMenu->addAction(m_helpAction);
    m_helpMenu->addAction(m_feedbackAction);
    m_helpMenu->addSeparator();
    m_helpMenu->addAction(m_aboutAction);

    this->addAction(m_loginAction);
    this->addSeparator();
    this->addMenu(m_addMusicMenu);
    this->addMenu(m_modeMenu);
    this->addSeparator();
    this->addMenu(m_remoteMenu);
    this->addAction(m_equalizerAction);
    this->addAction(m_plugAction);
    this->addAction(m_timerAction);
    this->addSeparator();
    this->addAction(m_stickAction);
    this->addAction(m_defaultAction);
    this->addMenu(m_loadSettingMenu);
    this->addAction(m_updateOnlineAction);
    this->addAction(m_showNewsAction);
    this->addMenu(m_helpMenu);
    this->addAction(m_settingAction);
    this->addSeparator();
    this->addAction(m_exitAction);
}

void TitleMenu::initConnect()
{

}
