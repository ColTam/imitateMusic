#include "MidRightWidget.h"

#include <QHBoxLayout>
#include <QPainter>
#include <QStackedWidget>
#include <QPropertyAnimation>
#include <qevent.h>
#include <QDebug>

#include <Base/basePushButton.h>
#include <MidRightWidget/stackWidget/midRightKTVWidget.h>
#include <MidRightWidget/stackWidget/midRightLibraryWidget.h>
#include <MidRightWidget/stackWidget/midRightLiveWidget.h>
#include <MidRightWidget/stackWidget/midRightMVWidget.h>
#include <MidRightWidget/stackWidget/midRightRadioWidget.h>
#include <MidRightWidget/stackWidget/midRightSongListWidget.h>
#include <MidRightWidget/stackWidget/midrightLyricwidget.h>

MidRightWidget::MidRightWidget(QWidget *parent)
    : QWidget(parent)
    , m_libraryButton(new basePushButton(this))
    , m_radioButton(new basePushButton(this))
    , m_songListButton(new basePushButton(this))
    , m_MVButton(new basePushButton(this))
    , m_liveButton(new basePushButton(this))
    , m_KTVButton(new basePushButton(this))
    , m_lyricButton(new basePushButton(this))
    , m_stackWidget(new QStackedWidget(this))
    , m_libraryWidget(new midRightLibraryWidget(this))
    , m_radioWidget(new midRightRadioWidget(this))
    , m_songListWidget(new midRightSongListWidget(this))
    , m_MVWidget(new midRightMVWidget(this))
    , m_liveWidget(new midRightLiveWidget(this))
    , m_KTVWidget(new midRightKTVWidget(this))
    , m_lyricWidget(new midRightLyricWidget(this))
    , m_index(0)
    , m_preIndex(0)
    , m_pix(QPixmap("://resource/image/widget/mask.png"))
    , m_buttonAnimation(new QPropertyAnimation(this, "m_index"))
    , m_backgroundColor(QColor(255,255,255))
    , m_isLyricWidget(0)
{
    initForm();
    initWidget();
    initConnect();
    updateButtonStyle(0);
}

MidRightWidget::~MidRightWidget()
{

}

void MidRightWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setPen(Qt::transparent);
    p.setBrush(m_backgroundColor);
    p.drawRect(0,0,width(),height());//背景色

    if (!m_isLyricWidget) {//按钮下的划线
        p.setPen(QColor(229,229,229));
        p.drawLine(0, 39, width(), 39);

        int btnWidth = m_libraryButton->width();//54
        int btnHeight = m_libraryButton->height();//40
//        if(m_isDrawVerticalLine)
//            p.drawLine(width()-1,0,width()-1,height());//vertical line

//    p.drawLine(0,btnHeight-1, m_index+(btnWidth-m_pix.width())/2-1,btnHeight-1);//first line
//    p.drawLine(m_index+(btnWidth+m_pix.width())/2,btnHeight-1, width(),btnHeight-1);//second line
        p.drawPixmap(m_libraryButton->x()+m_index+(btnWidth-m_pix.width())/2, btnHeight-m_pix.height(), m_pix);
//    p.drawPixmap(m_libraryButton->x()+1, btnHeight-m_pix.height(), m_pix);
    }
}

void MidRightWidget::initForm()
{
    setMinimumWidth(690);

    m_libraryButton->setObjectName( "mid_right_libraryBtn");
    m_radioButton->setObjectName("mid_right_radioBtn");
    m_songListButton->setObjectName("mid_right_songListBtn");
    m_MVButton->setObjectName("mid_right_MVBtn");
    m_liveButton->setObjectName("mid_right_liveBtn");
    m_KTVButton->setObjectName("mid_right_KTVBtn");
    m_lyricButton->setObjectName("mid_right_lyricBtn");

    m_libraryButton->setText( "乐库");
    m_radioButton->setText("电台");
    m_songListButton->setText("歌单");
    m_MVButton->setText("MV");
    m_liveButton->setText("直播");
    m_KTVButton->setText("KTV");
    m_lyricButton->setText("歌词");

    m_libraryButton->setToolTip("最新最火歌曲尽在其中");
    m_radioButton->setToolTip("享受随便听听的精彩");
    m_songListButton->setToolTip("海量歌单想听就听");
    m_MVButton->setToolTip("随意点播百万高清MV");
    m_liveButton->setToolTip("在线直播");
    m_KTVButton->setToolTip("在线K歌");
    m_lyricButton->setToolTip("精准歌词搭配高清写真");

    m_libraryButton->setFixedSize(54,40);
    m_radioButton->setFixedSize(54,40);
    m_songListButton->setFixedSize(54,40);
    m_MVButton->setFixedSize(54,40);
    m_liveButton->setFixedSize(54,40);
    m_KTVButton->setFixedSize(54,40);
    m_lyricButton->setFixedSize(54,40);

    setStyleSheet("QPushButton {font-family:微软雅黑;color: #000000;font-size: 16px;}"
                  "QPushButton:hover {color: rgb(55,174,254);}");

    m_stackWidget->addWidget(m_libraryWidget);
    m_stackWidget->addWidget(m_radioWidget);
    m_stackWidget->addWidget(m_songListWidget);
    m_stackWidget->addWidget(m_MVWidget);
    m_stackWidget->addWidget(m_liveWidget);
    m_stackWidget->addWidget(m_KTVWidget);
    m_stackWidget->addWidget(m_lyricWidget);

    m_buttonAnimation->setDuration(200);
}

void MidRightWidget::initWidget()
{
    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->addStretch();
    topLayout->addWidget(m_libraryButton);
    topLayout->addWidget(m_radioButton);
    topLayout->addWidget(m_songListButton);
    topLayout->addWidget(m_MVButton);
    topLayout->addWidget(m_liveButton);
    topLayout->addWidget(m_KTVButton);
    topLayout->addWidget(m_lyricButton);
    topLayout->addStretch();

    topLayout->setSpacing(LAYOUT_SPACING);

    m_buttonVector << m_libraryButton << m_radioButton << m_songListButton
                   << m_MVButton << m_liveButton << m_KTVButton << m_lyricButton;

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(m_stackWidget);

    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0,0,0,0);

    setLayout(mainLayout);
}

void MidRightWidget::initConnect()
{
    connect(m_libraryButton,  &basePushButton::pressed, [this](){ updateButtonStyle(0); m_stackWidget->setCurrentIndex(0); });
    connect(m_radioButton,    &basePushButton::pressed, [this](){ updateButtonStyle(1); m_stackWidget->setCurrentIndex(1); });
    connect(m_songListButton, &basePushButton::pressed, [this](){ updateButtonStyle(2); m_stackWidget->setCurrentIndex(2); });
    connect(m_MVButton,       &basePushButton::pressed, [this](){ updateButtonStyle(3); m_stackWidget->setCurrentIndex(3); });
    connect(m_liveButton,     &basePushButton::pressed, [this](){ updateButtonStyle(4); m_stackWidget->setCurrentIndex(4); });
    connect(m_KTVButton,      &basePushButton::pressed, [this](){ updateButtonStyle(5); m_stackWidget->setCurrentIndex(5); });
    connect(m_lyricButton,    &basePushButton::pressed, [this](){ updateButtonStyle(6); m_stackWidget->setCurrentIndex(6); });

    connect(m_stackWidget, &QStackedWidget::currentChanged, this, &MidRightWidget::on_stackWidget_currentChanged);
}

void MidRightWidget::updateButtonStyle(int index)
{
    if (index == 6) {//判断为歌词界面
        m_backgroundColor = QColor(255, 255, 255, 0);//刷新背景色
        //刷新按钮样式
        m_lyricButton->setStyleSheet("font-family:微软雅黑; color: rgb(255,254,161); "
                                     "font-size: 16px;");
        for (int i=0; i<index; i++)
        {
            m_buttonVector.at(i)->setStyleSheet("QPushButton {font-family:微软雅黑;font-size: 16px;color:white;}"
                                                "QPushButton:hover {color: rgb(255,254,161)}");
        }

        m_isLyricWidget = true;//刷新按钮下的划线
//        update();
    } else {
        if (m_preIndex == 6) {
            m_backgroundColor = QColor(255, 255, 255, 255);
            m_isLyricWidget = false;
        }

        for (int i = 0; i < m_buttonVector.count(); i++)
        {
            if (i == index) {//选中的按钮样式
                m_buttonVector.at(i)->setStyleSheet("font-family:微软雅黑; color: rgb(55,174,254); "
                                                    "font-size: 16px;");
            } else {//other
                m_buttonVector.at(i)->setStyleSheet("QPushButton {font-family:微软雅黑;font-size: 16px;}"
                                                    "QPushButton:hover {color: rgb(55,174,254)}");
            }
        }
    }
}

void MidRightWidget::on_stackWidget_currentChanged(int index)
{
    m_buttonAnimation->setStartValue(m_preIndex * (m_libraryButton->width()+LAYOUT_SPACING));
    m_buttonAnimation->setEndValue(index * (m_libraryButton->width()+LAYOUT_SPACING));
    m_buttonAnimation->start();//按钮点击效果

    m_preIndex = index;//记录为旧窗口序号
}
