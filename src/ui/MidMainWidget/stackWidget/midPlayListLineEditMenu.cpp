#include "midPlayListLineEditMenu.h"

midPlayListLineEditMenu::midPlayListLineEditMenu(QWidget *parent)
    : baseMenu(parent)
    , m_cutAction(new QAction(this))
    , m_copyAction(new QAction(this))
    , m_pasteAction(new QAction(this))
    , m_deleteAction(new QAction(this))
    , m_selectAllAction(new QAction(this))
{
    initForm();
    initConnect();
}

midPlayListLineEditMenu::~midPlayListLineEditMenu()
{

}

void midPlayListLineEditMenu::initForm()
{
    m_cutAction->setText("剪切");
    m_copyAction->setText("复制");
    m_pasteAction->setText("粘贴");
    m_deleteAction->setText("删除");
    m_selectAllAction->setText("全选");

    this->addAction(m_cutAction);
    this->addAction(m_copyAction);
    this->addAction(m_pasteAction);
    this->addAction(m_deleteAction);
    this->addSeparator();
    this->addAction(m_selectAllAction);
}

void midPlayListLineEditMenu::initConnect()
{

}
