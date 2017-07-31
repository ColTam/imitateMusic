#include "midPlayListListItem.h"
#include "midPlayListListWidget.h"

#include <Base/basePushButton.h>
#include <Base/baseWidget.h>

#include <QFormLayout>
#include <QVBoxLayout>
#include <QDebug>

midPlayListListWidget::midPlayListListWidget(QWidget *parent)
    : QScrollArea(parent)
    , m_emptyWidget(new baseWidget(this))
    , m_addFileIcon(new basePushButton(this))
    , m_addFileButton(new basePushButton(this))
    , m_addDirIcon(new basePushButton(this))
    , m_addDirButton(new basePushButton(this))
    , m_item(new midPlayListListItem(this))
    , m_listLayout(new QFormLayout())
{
    initForm();
    initWidget();
    initConnect();
}

midPlayListListWidget::~midPlayListListWidget()
{

}

void midPlayListListWidget::addItem2List()
{

}

void midPlayListListWidget::contextMenuEvent(QContextMenuEvent *event)
{

}

void midPlayListListWidget::wheelEvent(QWheelEvent *event)
{

}

void midPlayListListWidget::initForm()
{
    setFrameShape(QFrame::NoFrame);
//    setMinimumHeight(69);
    setMinimumWidth(310);
    setMaximumWidth(380);

    m_emptyWidget->setObjectName("mid_play_listWidget_empty");
    m_addFileIcon->setObjectName("mid_play_listWidget_fileIcon");
    m_addDirIcon->setObjectName("mid_play_listWidget_dirIcon");
    m_addFileButton->setObjectName("mid_play_listWidget_fileBtn");
    m_addDirButton->setObjectName("mid_play_listWidget_dirBtn");

    QFont f;
    f.setUnderline(true);
    m_addFileButton->setText("添加本地歌曲");
    m_addFileButton->setFont(f);
    m_addDirButton->setText("添加本地歌曲文件夹");
    m_addDirButton->setFont(f);

    m_item->setItemName("一闪一闪亮晶晶");
}

void midPlayListListWidget::initWidget()
{
    QHBoxLayout *emptyLayout1 = new QHBoxLayout();
    emptyLayout1->addSpacing(50);
    emptyLayout1->addWidget(m_addFileIcon);
    emptyLayout1->addWidget(m_addFileButton);
    emptyLayout1->addStretch();

    QHBoxLayout *emptyLayout2 = new QHBoxLayout();
    emptyLayout2->addSpacing(50);
    emptyLayout2->addWidget(m_addDirIcon);
    emptyLayout2->addWidget(m_addDirButton);
    emptyLayout2->addStretch();

    QVBoxLayout *emptyLayout = new QVBoxLayout();
    emptyLayout->addLayout(emptyLayout1);
    emptyLayout->addLayout(emptyLayout2);

    emptyLayout->setSpacing(10);
    emptyLayout->setContentsMargins(34,7,30,17);

    m_emptyWidget->setLayout(emptyLayout);

    m_listLayout->addWidget(m_item);
    m_listLayout->setSpacing(0);
    m_listLayout->setContentsMargins(0,0,0,0);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(m_emptyWidget);
    mainLayout->addLayout(m_listLayout);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0,0,0,0);

    setLayout(mainLayout);

//    m_item->hide();
//    setMaximumHeight(69);

    m_emptyWidget->hide();
    setMaximumHeight(32 * m_listLayout->count());
}

void midPlayListListWidget::initConnect()
{

}
