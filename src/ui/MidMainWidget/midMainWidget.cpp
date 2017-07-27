#include "midMainWidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QPropertyAnimation>
#include <qevent.h>
#include <QPainter>
#include <QDebug>

#include <Base/basePushButton.h>
#include <MidMainWidget/stackWidget/midMainCloudWidget.h>
#include <MidMainWidget/stackWidget/midMainListWidget.h>
#include <MidMainWidget/stackWidget/midMainLoadWidget.h>
#include <MidMainWidget/stackWidget/midMainPhoneWidget.h>
#include <MidMainWidget/stackWidget/midMainRadioWidget.h>

QColor midMainWidget::backgroundColor = QColor(255,255,255,30);

midMainWidget::midMainWidget(QWidget *parent)
    : QWidget(parent)
    , m_listButton(new basePushButton(this))
    , m_cloudButton(new basePushButton(this))
    , m_radioButton(new basePushButton(this))
    , m_phoneButton(new basePushButton(this))
    , m_loadButton(new basePushButton(this))
    , m_stackWidget(new QStackedWidget(this))
    , m_listWidget(new midMainListWidget(this))
    , m_cloudWidget(new midMainCloudWidget(this))
    , m_radioWidget(new midMainRadioWidget(this))
    , m_phoneWidget(new midMainPhoneWidget(this))
    , m_loadWidget(new midMainLoadWidget(this))
    , m_buttonAnimation(new QPropertyAnimation(this, "m_index"))
    , m_stackWidgetAnimation(new QPropertyAnimation(this, "geometry"))
    , m_pix(QPixmap("://resource/image/widget/indicator.png"))
    , m_index(0)
    , m_preIndex(0)
{
    initForm();
    initWidget();
    initConnect();
}

midMainWidget::~midMainWidget()
{
}

QColor midMainWidget::getBackgroundColor()
{
    return backgroundColor;
}

void midMainWidget::setBackgroundColor(const QColor &value)
{
    backgroundColor = value;
}

void midMainWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setPen(Qt::transparent);
    p.setBrush(getBackgroundColor());//刷新背景
    p.drawRect(0,0,width(),height());

    p.setPen(QColor(255,255,255,60));//刷新按钮下划线

    int btnWidth = m_listButton->width();//[62:76]
    int btnHeight = m_listButton->height();//40
//        if(m_isDrawVerticalLine)
//            p.drawLine(width()-1,0,width()-1,height());//vertical line

    p.drawLine(0,btnHeight-1, m_index+(btnWidth-m_pix.width())/2-1,btnHeight-1);//first line
    p.drawLine(m_index+(btnWidth+m_pix.width())/2,btnHeight-1, width(),btnHeight-1);//second line
    p.drawPixmap(m_index+(btnWidth-m_pix.width())/2, btnHeight-m_pix.height()+1, m_pix);
}

void midMainWidget::initForm()
{
    setMinimumSize(310, 574);
    setMaximumWidth(380);

    m_listButton->setObjectName( "mid_main_listBtn");
    m_cloudButton->setObjectName("mid_main_cloudBtn");
    m_radioButton->setObjectName("mid_main_radioBtn");
    m_phoneButton->setObjectName("mid_main_phoneBtn");
    m_loadButton->setObjectName( "mid_main_loadBtn");
    m_stackWidget->setObjectName("mid_main_widget");

    m_listButton->setToolTip( "本地列表");
    m_cloudButton->setToolTip("网络收藏");
    m_radioButton->setToolTip("音乐电台");
    m_phoneButton->setToolTip("手机音乐管理器");
    m_loadButton->setToolTip( "本地音乐");

    m_listButton->setFixedHeight( 40);
    m_cloudButton->setFixedHeight(40);
    m_radioButton->setFixedHeight(40);
    m_phoneButton->setFixedHeight(40);
    m_loadButton->setFixedHeight( 40);

    m_buttonAnimation->setDuration(200);
    m_stackWidgetAnimation->setDuration(200);

    m_stackWidget->addWidget(m_listWidget);
    m_stackWidget->addWidget(m_cloudWidget);
    m_stackWidget->addWidget(m_radioWidget);
    m_stackWidget->addWidget(m_phoneWidget);
    m_stackWidget->addWidget(m_loadWidget);

    m_listWidget->setObjectName("midListWidget");
}

void midMainWidget::initWidget()
{
    QHBoxLayout *topLayout = new QHBoxLayout();

    topLayout->addWidget(m_listButton);
    topLayout->addWidget(m_cloudButton);
    topLayout->addWidget(m_radioButton);
    topLayout->addWidget(m_phoneButton);
    topLayout->addWidget(m_loadButton);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(m_stackWidget);

    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0,0,0,0);

    setLayout(mainLayout);
}

void midMainWidget::initConnect()
{
    connect(m_listButton,  &basePushButton::pressed, [this](){ updateButtonStyle(0); m_stackWidget->setCurrentIndex(0); });
    connect(m_cloudButton, &basePushButton::pressed, [this](){ updateButtonStyle(1); m_stackWidget->setCurrentIndex(1); });
    connect(m_radioButton, &basePushButton::pressed, [this](){ updateButtonStyle(2); m_stackWidget->setCurrentIndex(2); });
    connect(m_phoneButton, &basePushButton::pressed, [this](){ updateButtonStyle(3); m_stackWidget->setCurrentIndex(3); });
    connect(m_loadButton,  &basePushButton::pressed, [this](){ updateButtonStyle(4); m_stackWidget->setCurrentIndex(4); });

    connect(m_stackWidget, &QStackedWidget::currentChanged, this, &midMainWidget::on_mainWidget_currentChanged);
}

void midMainWidget::updateButtonStyle(int index)
{
    switch (m_preIndex) {
    case 0:
        m_listButton->setStyleSheet( "QPushButton {image: url(://resource/image/widget/playlist.png);}"
                                     "QPushButton:hover {image: url(://resource/image/widget/playlist_hover.png);}");
        break;
    case 1:
        m_cloudButton->setStyleSheet("QPushButton {image: url(://resource/image/widget/cloud.png);}"
                                     "QPushButton:hover {image: url(://resource/image/widget/cloud_hover.png);}");
        break;
    case 2:
        m_radioButton->setStyleSheet("QPushButton {image: url(://resource/image/widget/radio.png);}"
                                     "QPushButton:hover {image: url(://resource/image/widget/radio_hover.png);}");
        break;
    case 3:
        m_phoneButton->setStyleSheet("QPushButton {image: url(://resource/image/widget/phone.png);}"
                                     "QPushButton:hover {image: url(://resource/image/widget/phone_hover.png);}");
        break;
    case 4:
        m_loadButton->setStyleSheet( "QPushButton {image: url(://resource/image/widget/load.png);}"
                                     "QPushButton:hover {image: url(://resource/image/widget/load_hover.png);}");
        break;
    }

    switch (index) {
    case 0:
        m_listButton->setStyleSheet( "image: url(://resource/image/widget/playlist_pressed.png);");
        break;
    case 1:
        m_cloudButton->setStyleSheet("image: url(://resource/image/widget/cloud_pressed.png);");
        break;
    case 2:
        m_radioButton->setStyleSheet("image: url(://resource/image/widget/radio_pressed.png);");
        break;
    case 3:
        m_phoneButton->setStyleSheet("image: url(://resource/image/widget/phone_pressed.png);");
        break;
    case 4:
        m_loadButton->setStyleSheet( "image: url(://resource/image/widget/load_pressed.png);");
        break;
    }
}

void midMainWidget::on_mainWidget_currentChanged(int index)
{
    m_buttonAnimation->setStartValue(m_preIndex * m_listButton->width());
    m_buttonAnimation->setEndValue(index * m_listButton->width());
    m_buttonAnimation->start();//按钮点击效果

    m_stackWidgetAnimation->setTargetObject(m_stackWidget);

    if (index > m_preIndex) {
        m_stackWidgetAnimation->setStartValue(QRect(m_stackWidget->width(), 40, m_stackWidget->width(), m_stackWidget->height()));
    } else if (index < m_preIndex) {
        m_stackWidgetAnimation->setStartValue(QRect(-m_stackWidget->width(),40, m_stackWidget->width(), m_stackWidget->height()));
    }

    m_stackWidgetAnimation->setEndValue(QRect(0, 40, m_stackWidget->width(), m_stackWidget->height()));
    m_stackWidgetAnimation->start();//界面切换效果

    m_preIndex = index;//记录为旧窗口序号
}
