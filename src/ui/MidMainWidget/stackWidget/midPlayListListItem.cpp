#include "midPlayListListItem.h"

#include <Base/basePushButton.h>

#include <QHBoxLayout>
#include <QLabel>

midPlayListListItem::midPlayListListItem(QWidget *parent)
    : baseWidget(parent)
    , m_delayPlayButon(new basePushButton(this))
    , m_nameLabel(new QLabel(this))
    , m_rightWidget(new QWidget(this))
    , m_MVButton(new basePushButton(m_rightWidget))
    , m_favoriteButton(new basePushButton(m_rightWidget))
    , m_deleteButton(new basePushButton(m_rightWidget))
    , m_moreButton(new basePushButton(m_rightWidget))
    , m_timeLabel(new QLabel(m_rightWidget))
{
    initForm();
    initWidget();
    initConnect();
}

midPlayListListItem::~midPlayListListItem()
{

}

void midPlayListListItem::setItemName(const QString &name)
{
    m_nameLabel->setText(name);
}

void midPlayListListItem::enterEvent(QEvent *)
{
    m_favoriteButton->show();
    m_deleteButton->show();
    m_moreButton->show();
    m_timeLabel->hide();
}

void midPlayListListItem::leaveEvent(QEvent *)
{
    m_favoriteButton->hide();
    m_deleteButton->hide();
    m_moreButton->hide();
    m_timeLabel->show();
}

void midPlayListListItem::initForm()
{
    m_delayPlayButon->setObjectName("listitem_delayBtn");
    m_MVButton->setObjectName("listitem_mvBtn");
    m_favoriteButton->setObjectName("listitem_favrBtn");
    m_deleteButton->setObjectName("listitem_delBtn");
    m_moreButton->setObjectName("listitem_moreBtn");

    m_rightWidget->setFixedSize(101, 32);

    m_MVButton->setGeometry(1,6,20,20);
    m_favoriteButton->setGeometry(28,6,20,20);
    m_deleteButton->setGeometry(55,6,20,20);
    m_moreButton->setGeometry(82,6,20,20);

    m_timeLabel->setGeometry(64,6,35,20);
    m_timeLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    m_timeLabel->setText("00:00");
}

void midPlayListListItem::initWidget()
{
    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addWidget(m_delayPlayButon);
    mainLayout->addWidget(m_nameLabel);
    mainLayout->addStretch();
    mainLayout->addWidget(m_rightWidget);

    mainLayout->setSpacing(4);
    mainLayout->setContentsMargins(0,0,14,0);

    setLayout(mainLayout);

    m_favoriteButton->hide();
    m_deleteButton->hide();
    m_moreButton->hide();
}

void midPlayListListItem::initConnect()
{

}
