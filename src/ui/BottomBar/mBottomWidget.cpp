#include "mBottomWidget.h"
#include "mSlider.h"

#include <Base/basePushButton.h>
#include <TitleBar/TitleMenu.h>
#include <QContextMenuEvent>
#include <QHBoxLayout>
#include <QLabel>

mBottomWidget::mBottomWidget(QWidget *parent)
    : baseTitleBar(parent)
    , m_prevButton(new basePushButton(this))
    , m_playButton(new basePushButton(this))
    , m_nextButton(new basePushButton(this))
    , m_musicNameLabel(new QLabel(this))
    , m_musicTimeLabel(new QLabel(this))
    , m_slider(new mSlider(this))
    , m_favoriteButton(new basePushButton(this))
    , m_loadButton(new basePushButton(this))
    , m_moreButton(new basePushButton(this))
    , m_modeButton(new basePushButton(this))
    , m_soundButton(new basePushButton(this))
    , m_equalizerButton(new basePushButton(this))
    , m_lyricButton(new basePushButton(this))
    , m_commentButton(new basePushButton(this))
    , m_listButton(new basePushButton(this))
    , m_titleMenu(new TitleMenu(this))
{
    initForm();
    initWidget();
    initConnect();
}

mBottomWidget::~mBottomWidget()
{
}

void mBottomWidget::contextMenuEvent(QContextMenuEvent *event)
{
    //使右击在按钮时 不显示菜单
    bool inPrevButton = m_titleMenu->inChild(m_prevButton);
    bool inPlayButton = m_titleMenu->inChild(m_playButton);
    bool inNextButton = m_titleMenu->inChild(m_nextButton);
    bool inSlider = m_titleMenu->inChild(m_slider);
    bool inFavoriteButton = m_titleMenu->inChild(m_favoriteButton);
    bool inLoadButton = m_titleMenu->inChild(m_loadButton);
    bool inMoreButton = m_titleMenu->inChild(m_moreButton);
    bool inModeButton = m_titleMenu->inChild(m_modeButton);
    bool inSoundButton = m_titleMenu->inChild(m_soundButton);
    bool inEquakizerButton = m_titleMenu->inChild(m_equalizerButton);
    bool inLyricButton = m_titleMenu->inChild(m_lyricButton);
    bool inCommentButton = m_titleMenu->inChild(m_commentButton);
    bool inListButton = m_titleMenu->inChild(m_listButton);

    if (!inPrevButton && !inPlayButton && !inNextButton && !inSlider &&
            !inFavoriteButton && !inLoadButton && !inMoreButton && !inModeButton &&
            !inSoundButton && !inEquakizerButton && !inLyricButton && !inCommentButton &&
            !inListButton)
        m_titleMenu->exec(QCursor::pos()+QPoint(5, -505));

    event->accept();
}

void mBottomWidget::initForm()
{
    setMinimumHeight(66);
    setMaximumHeight(66);

    setObjectName("bottomBar");

    m_prevButton->setObjectName("bottom_prevBtn");
    m_playButton->setObjectName("bottom_playBtn");
    m_nextButton->setObjectName("bottom_nextBtn");

    m_musicNameLabel->setObjectName("bottom_nameLabel");
    m_musicTimeLabel->setObjectName("bottom_timeLabel");
    m_slider->setObjectName("bottom_slider");

    m_favoriteButton->setObjectName("bottom_favoriteBtn");
    m_loadButton->setObjectName("bottom_loadBtn");
    m_moreButton->setObjectName("bottom_moreBtn");
    m_modeButton->setObjectName("bottom_modeBtn");
    m_soundButton->setObjectName("bottom_soundBtn");
    m_equalizerButton->setObjectName("bottom_equalizerBtn");
    m_lyricButton->setObjectName("bottom_lyricBtn");
    m_commentButton->setObjectName("bottom_commentBtn");
    m_listButton->setObjectName("bottom_listBtn");

    m_musicNameLabel->setText("酷狗音乐");
    m_musicTimeLabel->setText("00:00/00:00");
    m_listButton->setText(" 0");
}

void mBottomWidget::initWidget()
{
    QHBoxLayout *leftLayout = new QHBoxLayout();
    leftLayout->addWidget(m_prevButton);
    leftLayout->addWidget(m_playButton);
    leftLayout->addWidget(m_nextButton);

    QHBoxLayout *midLabelLayout = new QHBoxLayout();
    midLabelLayout->addWidget(m_musicNameLabel);
    midLabelLayout->addStretch();
    midLabelLayout->addWidget(m_musicTimeLabel);

    QVBoxLayout *midLayout = new QVBoxLayout();
    midLayout->addLayout(midLabelLayout);
    midLayout->addWidget(m_slider);
    midLayout->setSpacing(0);
    midLayout->setContentsMargins(0,10,0,15);

    QHBoxLayout *rightLayout = new QHBoxLayout();
    rightLayout->addWidget(m_favoriteButton);
    rightLayout->addWidget(m_loadButton);
    rightLayout->addWidget(m_moreButton);
    rightLayout->addWidget(m_modeButton);
    rightLayout->addSpacing(1);
    rightLayout->addWidget(m_soundButton);
    rightLayout->addWidget(m_equalizerButton);
    rightLayout->addSpacing(1);
    rightLayout->addWidget(m_lyricButton);
    rightLayout->addWidget(m_commentButton);
    rightLayout->addWidget(m_listButton);
    rightLayout->setSpacing(16);

    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addLayout(leftLayout);
    mainLayout->addSpacing(18);
    mainLayout->addLayout(midLayout);
    mainLayout->addSpacing(21);
    mainLayout->addLayout(rightLayout);

    mainLayout->setSpacing(15);
    mainLayout->setContentsMargins(13,0,0,0);

    setLayout(mainLayout);
}

void mBottomWidget::initConnect()
{

}
