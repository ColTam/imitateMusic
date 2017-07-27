#ifndef TITLEMENU_H
#define TITLEMENU_H

#include <Base/baseMenu.h>

class TitleMenu : public baseMenu
{
    Q_OBJECT
public:
    explicit TitleMenu(QWidget *parent = 0);
    ~TitleMenu();

protected:
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    void initForm();
    void initConnect();

private:
    QAction  *m_loginAction;

    baseMenu *m_addMusicMenu;
    QAction  *m_addMusicFileAction;
    QAction  *m_addMusicDirAction;

    baseMenu *m_modeMenu;
    QActionGroup *m_modeActionGroup;
    QAction  *m_modeOnceAction;
    QAction  *m_modeSingleAction;
    QAction  *m_modeOrdinalAction;
    QAction  *m_modeListAction;
    QAction  *m_modeRandomAction;
    QAction  *m_modeAutoAction;

    baseMenu *m_remoteMenu;
    QAction  *m_remoteCudeAction;
    QAction  *m_remoteBarAction;
    QAction  *m_remoteHideAction;

    QAction  *m_equalizerAction;
    QAction  *m_plugAction;
    QAction  *m_timerAction;
    QAction  *m_stickAction;
    QAction  *m_defaultAction;

    baseMenu *m_loadSettingMenu;
    QActionGroup *m_loadActionGroup;
    QAction  *m_loadFullSpeedAction;
    QAction  *m_loadCustomSpeedAction;
    QAction  *m_loadSaveBandWidthAction;

    QAction  *m_updateOnlineAction;
    QAction  *m_showNewsAction;

    baseMenu *m_helpMenu;
    QAction  *m_helpAction;
    QAction  *m_feedbackAction;
    QAction  *m_aboutAction;

    QAction  *m_settingAction;
    QAction  *m_exitAction;

//    friend class mTitleWidget;
};

#endif // TITLEMENU_H
