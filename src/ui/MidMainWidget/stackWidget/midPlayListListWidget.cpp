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
    , m_mainLayout(new QFormLayout())
{
    initForm();
    initWidget();
    initConnect();
}

midPlayListListWidget::~midPlayListListWidget()
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
    setFixedSize(310,69);
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

    m_emptyWidget->setFixedSize(310,69);
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

    m_mainLayout->addWidget(m_emptyWidget);
    m_mainLayout->setSpacing(0);
    m_mainLayout->setContentsMargins(0,0,0,0);

    setLayout(m_mainLayout);
}

void midPlayListListWidget::initConnect()
{

}
