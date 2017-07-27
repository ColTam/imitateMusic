#ifndef MIDPLAYLISTMENU_H
#define MIDPLAYLISTMENU_H

#include <Base/baseMenu.h>

class midPlayListButtonMenu : public baseMenu
{
    Q_OBJECT
public:
    explicit midPlayListButtonMenu(QWidget *parent = 0);
    ~midPlayListButtonMenu();

protected:
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    void initForm();
    void initConnect();

private:
    QAction  *m_newAction;
    baseMenu *m_addMenu;
    QAction  *m_addAction;
    QAction  *m_addDirAction;
    QAction  *m_delayAction;
    QAction  *m_addListAction;
    QAction  *m_send2PhoneAction;
    QAction  *m_downloadAction;
    baseMenu *m_sortMenu;
    QActionGroup *m_sortActionGroup;
    QAction  *m_sortNameAction;
    QAction  *m_sortSongerAction;
    QAction  *m_sortTimeAction;
    QAction  *m_sortPlayNumberAction;
    QAction  *m_sortIsDownLoadAction;
    QAction  *m_sortRandomAction;
    QAction  *m_searchMVAction;
    QAction  *m_collectAction;
    QAction  *m_shareAction;
    QAction  *m_clearAction;
    QAction  *m_deleteAction;
    QAction  *m_reNameAction;

    friend class midPlayListButton;
};

#endif // MIDPLAYLISTMENU_H
