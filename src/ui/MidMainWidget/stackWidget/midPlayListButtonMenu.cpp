#include "midPlayListButtonMenu.h"

#include <qevent.h>

midPlayListButtonMenu::midPlayListButtonMenu(QWidget *parent)
    : baseMenu(parent)
    , m_newAction(new QAction(this))
    , m_addMenu(new baseMenu(this))
    , m_addAction(new QAction(this))
    , m_addDirAction(new QAction(this))
    , m_delayAction(new QAction(this))
    , m_addListAction(new QAction(this))
    , m_send2PhoneAction(new QAction(this))
    , m_downloadAction(new QAction(this))
    , m_sortMenu(new baseMenu(this))
    , m_sortActionGroup(new QActionGroup(this))
    , m_sortNameAction(new QAction(this))
    , m_sortSongerAction(new QAction(this))
    , m_sortTimeAction(new QAction(this))
    , m_sortPlayNumberAction(new QAction(this))
    , m_sortIsDownLoadAction(new QAction(this))
    , m_sortRandomAction(new QAction(this))
    , m_searchMVAction(new QAction(this))
    , m_collectAction(new QAction(this))
    , m_shareAction(new QAction(this))
    , m_clearAction(new QAction(this))
    , m_deleteAction(new QAction(this))
    , m_reNameAction(new QAction(this))
{
    initForm();
    initConnect();
}

midPlayListButtonMenu::~midPlayListButtonMenu()
{

}

void midPlayListButtonMenu::mouseMoveEvent(QMouseEvent *event)
{
    if (actionAt(event->pos()) == m_shareAction) {
        m_shareAction->setIcon(QIcon("://resource/image/menu/share_light.png"));
    } else if (actionAt(event->pos()) == m_deleteAction && m_deleteAction->isEnabled()) {
        m_deleteAction->setIcon(QIcon("://resource/image/menu/del_light.png"));
    } else {
        m_shareAction->setIcon(QIcon("://resource/image/menu/share_dark.png"));
        m_deleteAction->setIcon(QIcon("://resource/image/menu/del_dark.png"));
    }

    QMenu::mouseMoveEvent(event);
}

void midPlayListButtonMenu::initForm()
{
    m_addMenu->setObjectName("listmenu_add");

    m_newAction->setText("新建列表");
    m_addMenu->setTitle("添加歌曲");
    m_addAction->setText("添加本地歌曲...");
    m_addDirAction->setText("添加本地歌曲文件夹...");
    m_delayAction->setText("稍后播");
    m_addListAction->setText("添加到播放列表");
    m_send2PhoneAction->setText("全部发送到移动设备");
    m_downloadAction->setText("下载本列表全部歌曲");
    m_sortMenu->setTitle("排序");
    m_sortNameAction->setText("按文件名");
    m_sortSongerAction->setText("按歌手");
    m_sortTimeAction->setText("按添加时间");
    m_sortPlayNumberAction->setText("按播放次数");
    m_sortIsDownLoadAction->setText("按是否已下载");
    m_sortRandomAction->setText("随机排序");
    m_searchMVAction->setText("匹配MV");
    m_collectAction->setText("收藏整个列表");
    m_shareAction->setText("分享");
    m_clearAction->setText("清除列表");
    m_deleteAction->setText("删除列表");
    m_reNameAction->setText("重命名");

    m_shareAction->setIcon(QIcon("://resource/image/menu/share_dark.png"));
    m_deleteAction->setIcon(QIcon("://resource/image/menu/del_dark.png"));

    m_deleteAction->setObjectName("listmenu_del");

    m_addMenu->addAction(m_addAction);
    m_addMenu->addAction(m_addDirAction);

    m_sortMenu->addAction(m_sortActionGroup->addAction(m_sortNameAction));
    m_sortMenu->addAction(m_sortActionGroup->addAction(m_sortSongerAction));
    m_sortMenu->addAction(m_sortActionGroup->addAction(m_sortTimeAction));
    m_sortMenu->addAction(m_sortActionGroup->addAction(m_sortPlayNumberAction));
    m_sortMenu->addAction(m_sortActionGroup->addAction(m_sortIsDownLoadAction));
    m_sortMenu->addAction(m_sortActionGroup->addAction(m_sortRandomAction));

    m_sortNameAction->setCheckable(true);
    m_sortSongerAction->setCheckable(true);
    m_sortTimeAction->setCheckable(true);
    m_sortPlayNumberAction->setCheckable(true);
    m_sortIsDownLoadAction->setCheckable(true);
    m_sortRandomAction->setCheckable(true);

    this->addAction(m_newAction);
    this->addSeparator();
    this->addMenu(m_addMenu);
    this->addAction(m_delayAction);
    this->addAction(m_addListAction);
    this->addAction(m_send2PhoneAction);
    this->addAction(m_downloadAction);
    this->addMenu(m_sortMenu);
    this->addAction(m_searchMVAction);
    this->addAction(m_collectAction);
    this->addAction(m_shareAction);
    this->addSeparator();
    this->addAction(m_clearAction);
    this->addAction(m_deleteAction);
    this->addAction(m_reNameAction);
}

void midPlayListButtonMenu::initConnect()
{

}
