#ifndef MIDPLAYLISTLINEEDITMENU_H
#define MIDPLAYLISTLINEEDITMENU_H

#include <Base/baseMenu.h>

class midPlayListLineEditMenu : public baseMenu
{
    Q_OBJECT
public:
    explicit midPlayListLineEditMenu(QWidget *parent = 0);
    ~midPlayListLineEditMenu();

signals:

public slots:

private:
    void initForm();
    void initConnect();

private:
    QAction *m_cutAction;
    QAction *m_copyAction;
    QAction *m_pasteAction;
    QAction *m_deleteAction;
    QAction *m_selectAllAction;

    friend class midPlayListLineEdit;
};

#endif // MIDPLAYLISTLINEEDITMENU_H
