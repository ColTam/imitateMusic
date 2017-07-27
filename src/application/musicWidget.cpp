#include "musicWidget.h"

#include <TitleBar/mtitlewidget.h>
#include <MidMainWidget/midMainWidget.h>
#include <BottomBar/mBottomWidget.h>
#include <MidRightWidget/MidRightWidget.h>

#include <QHBoxLayout>
#include <QLabel>
#include <QPainter>
#include <QVBoxLayout>
#include <QtWinExtras>
#include <QWinThumbnailToolBar>
#include <QWinThumbnailToolButton>
#include <QtWin>

MusicWidget::MusicWidget(QWidget *parent)
    : QFrame(parent)
    , m_titleBar(new mTitleWidget(this))
    , m_midMainWidget(new midMainWidget(this))
    , m_midRightWidget(new MidRightWidget(this))
    , m_bottomBar(new mBottomWidget(this))
    , thumbbar(new QWinThumbnailToolBar(this))
    , prevMusic(new QWinThumbnailToolButton(thumbbar))
    , playPause(new QWinThumbnailToolButton(thumbbar))
    , nextMusic(new QWinThumbnailToolButton(thumbbar))
{
    initForm();
    initWidget();
    initConnect();
}

MusicWidget::~MusicWidget()
{

}

void MusicWidget::creatrWinThumbnail()
{
    if (QtWin::isCompositionEnabled())
        QtWin::enableBlurBehindWindow(this);
    else
        QtWin::disableBlurBehindWindow(this);

    thumbbar->setWindow(this->windowHandle());

    prevMusic->setToolTip("上一首");
    prevMusic->setIcon(QIcon("://resource/image/widget/prev.png"));
//    settings->setDismissOnClick(true);
//    connect(settings, SIGNAL(clicked()), settingsPage, SLOT(show()));

    playPause->setToolTip("播放/暂停");
    playPause->setIcon(QIcon("://resource/image/widget/play.png"));
//    connect(playPause, SIGNAL(clicked()), mediaPlayer, SLOT(play()));

    nextMusic->setToolTip("下一首");
    nextMusic->setIcon(QIcon("://resource/image/widget/next.png"));
//    connect(nextMusic, SIGNAL(clicked()), mediaPlayer, SLOT(play()));

    thumbbar->addButton(prevMusic);
    thumbbar->addButton(playPause);
    thumbbar->addButton(nextMusic);
}

void MusicWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(),this->height(),QPixmap("://resource/image/skin/13.png"));
}

void MusicWidget::initForm()
{
    setMinimumSize(1000,690);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    setObjectName("musicWidget");

//    setStyleSheet(".QWidget {image: url(://resource/image/skin/13.png);}");
//    setWindowFlags(Qt::WindowTitleHint);
//    setWindowFlags(Qt::CustomizeWindowHint);
}

void MusicWidget::initWidget()
{
    installEventFilter(m_titleBar);

    QHBoxLayout *midLayout = new QHBoxLayout();
    midLayout->addWidget(m_midMainWidget, 3);
    midLayout->addWidget(m_midRightWidget, 7);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(m_titleBar);
    mainLayout->addLayout(midLayout);
    mainLayout->addWidget(m_bottomBar);

    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0,0,0,0);

    setLayout(mainLayout);
}

void MusicWidget::initConnect()
{
    connect(m_titleBar, &mTitleWidget::minimizeApp, this, &MusicWidget::showMinimized);
    connect(m_titleBar, &mTitleWidget::closeApp, this, &MusicWidget::close);
}
