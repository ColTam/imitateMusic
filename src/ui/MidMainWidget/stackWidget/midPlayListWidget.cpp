#include "midPlayListButton.h"
#include "midPlayListListWidget.h"
#include "midPlayListWidget.h"

#include <QVBoxLayout>
#include <QDebug>

midPlayListWidget::midPlayListWidget(QWidget *parent)
    : baseWidget(parent)
    , m_playButton(new midPlayListButton(this))
    , m_playListWidget(new midPlayListListWidget(this))
{
    initForm();
    initWidget();
    initConnect();
}

void midPlayListWidget::setListText(const QString &text)
{
    m_playButton->setText(text);
}

void midPlayListWidget::setListNumber(int number)
{
    m_playButton->setNumber(number);

    if (number == 0);
//        m_playListWidget->musicState = midPlayListListWidget::IS_EMPTY;
}

QString midPlayListWidget::getListText() const
{
    return m_playButton->text();
}

void midPlayListWidget::initForm()
{
    setMouseTracking(true);
    setObjectName("midPlayListWidget");

    m_playListWidget->setObjectName("midPlayList_listWidget");
//    m_playListWidget->setStyleSheet( " QWidget {background:transparent;border:none;} " );

    m_playListWidget->hide();
}

void midPlayListWidget::initWidget()
{
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(m_playButton);
    mainLayout->addWidget(m_playListWidget);

    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0,0,0,0);

    setLayout(mainLayout);
}
void midPlayListWidget::initConnect()
{
    connect(m_playButton, &midPlayListButton::clicked, [this](){
        if (m_playListWidget->isHidden()) {
            m_playButton->setIcon("://resource/image/widget/arrow_down.png");
            m_playListWidget->show();
        } else {
            m_playButton->setIcon("://resource/image/widget/arrow_right.png");
            m_playListWidget->hide();
        }
    });
    connect(m_playButton, &midPlayListButton::newListSignal, this, &midPlayListWidget::newListSignal);
}
