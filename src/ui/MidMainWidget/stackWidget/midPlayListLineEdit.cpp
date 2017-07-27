#include "midPlayListLineEdit.h"
#include "midPlayListLineEditMenu.h"

#include <QContextMenuEvent>
#include <QApplication>
#include <QDesktopWidget>
#include <QClipboard>
#include <QDebug>

midPlayListLineEdit::midPlayListLineEdit(QWidget *parent)
    : QLineEdit(parent)
    , m_contextMenu(new midPlayListLineEditMenu(this))
{
    m_contextMenu->setObjectName("listmenu_edit");
    setMaxLength(20);
    raise();

    initConnect();
}

midPlayListLineEdit::~midPlayListLineEdit()
{

}

void midPlayListLineEdit::focusOutEvent(QFocusEvent *event)
{
    QLineEdit::focusOutEvent(event);
}

void midPlayListLineEdit::contextMenuEvent(QContextMenuEvent *event)
{
    m_contextMenu->m_cutAction->setEnabled(hasSelectedText());
    m_contextMenu->m_copyAction->setEnabled(hasSelectedText());
    m_contextMenu->m_pasteAction->setEnabled(!QApplication::clipboard()->text().isEmpty());
    m_contextMenu->m_deleteAction->setEnabled(!text().isEmpty() && hasSelectedText());
    m_contextMenu->m_selectAllAction->setEnabled(!text().isEmpty());

    m_contextMenu->exec(QCursor::pos()+QPoint(5,5));

    event->accept();
}

void midPlayListLineEdit::initConnect()
{
    connect(m_contextMenu->m_cutAction, &QAction::triggered, this, &midPlayListLineEdit::cut);
    connect(m_contextMenu->m_copyAction, &QAction::triggered, this, &midPlayListLineEdit::copy);
    connect(m_contextMenu->m_pasteAction, &QAction::triggered, this, &midPlayListLineEdit::paste);
    connect(m_contextMenu->m_deleteAction, &QAction::triggered, [this](){
        QString t = text();
        int i = selectionStart();
        t.remove(i, selectedText().length());
        setText(t);
        setCursorPosition(i);
    });
    connect(m_contextMenu->m_selectAllAction, &QAction::triggered, this, &midPlayListLineEdit::selectAll);
}
