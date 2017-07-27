#ifndef MUSICWIDGET_H
#define MUSICWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QSystemTrayIcon>

class mTitleWidget;
class midMainWidget;
class MidRightWidget;
class mBottomWidget;

class QWinThumbnailToolBar;
class QWinThumbnailToolButton;

class MusicWidget : public QFrame
{
    Q_OBJECT
public:
    explicit MusicWidget(QWidget *parent = nullptr);
    ~MusicWidget();

    void creatrWinThumbnail();

protected:
    void paintEvent(QPaintEvent *) override;

private:
    void initForm();
    void initWidget();
    void initConnect();

private:
    mTitleWidget *m_titleBar;
    midMainWidget *m_midMainWidget;
    MidRightWidget *m_midRightWidget;
    mBottomWidget *m_bottomBar;

    QWinThumbnailToolBar *thumbbar;
    QWinThumbnailToolButton *prevMusic;
    QWinThumbnailToolButton *playPause;
    QWinThumbnailToolButton *nextMusic;
};

#endif // MUSICWIDGET_H
