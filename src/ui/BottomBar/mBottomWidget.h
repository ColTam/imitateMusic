#ifndef MBOTTOMWIDGET_H
#define MBOTTOMWIDGET_H

#include <Base/baseTitleBar.h>

class basePushButton;
class QLabel;
class mSlider;
class TitleMenu;

class mBottomWidget : public baseTitleBar
{
    Q_OBJECT
public:
    explicit mBottomWidget(QWidget *parent = 0);
    ~mBottomWidget();

signals:

public slots:

protected:
    void contextMenuEvent(QContextMenuEvent *event) override;

private:
    void initForm();
    void initWidget();
    void initConnect();

private:
    basePushButton *m_prevButton;
    basePushButton *m_playButton;
    basePushButton *m_nextButton;

    QLabel *m_musicNameLabel;
    QLabel *m_musicTimeLabel;

    mSlider *m_slider;

    basePushButton *m_favoriteButton;
    basePushButton *m_loadButton;
    basePushButton *m_moreButton;
    basePushButton *m_modeButton;
    basePushButton *m_soundButton;
    basePushButton *m_equalizerButton;
    basePushButton *m_lyricButton;
    basePushButton *m_commentButton;
    basePushButton *m_listButton;

    TitleMenu *m_titleMenu;
};

#endif // MBOTTOMWIDGET_H
