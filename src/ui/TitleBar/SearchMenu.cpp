#include "SearchMenu.h"

SearchMenu::SearchMenu(QWidget *parent)
    : baseMenu(parent)
    , m_cutAction(new QAction(this))
    , m_copyAction(new QAction(this))
    , m_pasteAction(new QAction(this))
    , m_pasteSearchAction(new QAction(this))
    , m_deleteAction(new QAction(this))
    , m_selectAllAction(new QAction(this))

{
    initForm();
    initConnect();
}

SearchMenu::~SearchMenu()
{

}

void SearchMenu::initForm()
{
    m_cutAction->setText("剪切");
    m_copyAction->setText("复制");
    m_pasteAction->setText("粘贴");
    m_pasteSearchAction->setText("粘贴并搜索");
    m_deleteAction->setText("删除");
    m_selectAllAction->setText("全选");

    addAction(m_cutAction);
    addAction(m_copyAction);
    addAction(m_pasteAction);
    addAction(m_pasteSearchAction);
    addAction(m_deleteAction);
    addSeparator();
    addAction(m_selectAllAction);
}

void SearchMenu::initConnect()
{
//    connect(m_cutAction,    &QAction::triggered, this, &SearchMenu::clickedCut);
//    connect(m_copyAction,   &QAction::triggered, this, &SearchMenu::clickedCopy);
//    connect(m_pasteAction,  &QAction::triggered, this, &SearchMenu::clickedPaste);
//    connect(m_pasteSearchAction, &QAction::triggered, this, &SearchMenu::clickedPasteSearch);
//    connect(m_deleteAction, &QAction::triggered, this, &SearchMenu::clickedDelete);
//    connect(m_selectAllAction, &QAction::triggered, this, &SearchMenu::clickedSelectAll);
}
