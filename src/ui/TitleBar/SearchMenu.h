#ifndef SEARCHMENU_H
#define SEARCHMENU_H

#include <Base/baseMenu.h>

class SearchMenu : public baseMenu
{
    Q_OBJECT
public:
    explicit SearchMenu(QWidget *parent = 0);
    ~SearchMenu();

Q_SIGNALS:
//    void clickedCut();
//    void clickedCopy();
//    void clickedPaste();
//    void clickedPasteSearch();
//    void clickedDelete();
//    void clickedSelectAll();

private:
    void initForm();
    void initConnect();

private:
    QAction *m_cutAction;
    QAction *m_copyAction;
    QAction *m_pasteAction;
    QAction *m_pasteSearchAction;
    QAction *m_deleteAction;
    QAction *m_selectAllAction;

    friend class SearchLineEdit;
};

#endif // SEARCHMENU_H
