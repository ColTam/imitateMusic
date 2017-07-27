#include "midMainListWidget.h"
#include "midPlayListWidget.h"

#include <QFormLayout>
#include <QDebug>

midMainListWidget::midMainListWidget(QWidget *parent)
    : QScrollArea(parent)
    , m_defaultWidget(new midPlayListWidget(this))
    , m_latelyWidget(new midPlayListWidget(this))
    , m_mainLayout(new QFormLayout())
{
    initForm();
    initWidget();
    initConnect();
}

midMainListWidget::~midMainListWidget()
{

}

void midMainListWidget::newListSlot()
{
    midPlayListWidget *senderWidget = qobject_cast<midPlayListWidget *>(sender());
    midPlayListWidget *newWidget = new midPlayListWidget(this);
    connect(newWidget, &midPlayListWidget::newListSignal, this, &midMainListWidget::newListSlot);

    if (m_mainLayout->indexOf(senderWidget)+1 == m_mainLayout->count())
        m_mainLayout->insertRow(m_mainLayout->indexOf(senderWidget), newWidget);
    else
        m_mainLayout->insertRow(m_mainLayout->indexOf(senderWidget)+1, newWidget);
}

void midMainListWidget::initForm()
{
    setMouseTracking(true);
    m_defaultWidget->setListText("默认列表");
    m_latelyWidget->setListText("最近播放");

    setFrameShape(QFrame::NoFrame);
}

void midMainListWidget::initWidget()
{
    m_mainLayout->addWidget(m_defaultWidget);
    m_mainLayout->addWidget(m_latelyWidget);

    m_mainLayout->setSpacing(0);
    m_mainLayout->setContentsMargins(0,0,0,0);

    setLayout(m_mainLayout);
}

void midMainListWidget::initConnect()
{
    connect(m_defaultWidget, &midPlayListWidget::newListSignal, this, &midMainListWidget::newListSlot);
    connect(m_latelyWidget, &midPlayListWidget::newListSignal, this, &midMainListWidget::newListSlot);
}
