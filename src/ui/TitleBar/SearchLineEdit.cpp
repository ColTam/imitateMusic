#include "SearchLineEdit.h"
#include "SearchMenu.h"

#include <Base/basePushButton.h>
#include <QHBoxLayout>
#include <QMenu>
#include <QContextMenuEvent>
#include <QDebug>
#include <QApplication>
#include <QDesktopWidget>
#include <QClipboard>


SearchLineEdit::SearchLineEdit(QWidget *parent)
    : QLineEdit(parent)
    , m_searchButton(new basePushButton(this))
    , m_searchMenu(new SearchMenu(this))
{
    initForm();
    initConnect();
}

SearchLineEdit::~SearchLineEdit()
{

}

void SearchLineEdit::searchContent()
{
    qDebug() << text();
}

void SearchLineEdit::contextMenuEvent(QContextMenuEvent *event)
{
    m_searchMenu->m_cutAction->setEnabled(hasSelectedText());
    m_searchMenu->m_copyAction->setEnabled(hasSelectedText());
    m_searchMenu->m_pasteAction->setEnabled(!QApplication::clipboard()->text().isEmpty());
    m_searchMenu->m_pasteSearchAction->setEnabled(!QApplication::clipboard()->text().isEmpty());
    m_searchMenu->m_deleteAction->setEnabled(!text().isEmpty() && hasSelectedText());
    m_searchMenu->m_selectAllAction->setEnabled(!text().isEmpty());

    bool inSearchButton = m_searchButton->mapFromGlobal(QCursor::pos()).x() >= 0 &&
            m_searchButton->mapFromGlobal(QCursor::pos()).x() <= m_searchButton->width() &&
            m_searchButton->mapFromGlobal(QCursor::pos()).y() >= 0 &&
            m_searchButton->mapFromGlobal(QCursor::pos()).y() <= m_searchButton->height();
    if (!inSearchButton) {
        m_searchMenu->exec(QCursor::pos()+QPoint(5,5));
    }

    event->accept();
}

void SearchLineEdit::initForm()
{
    setCursor(Qt::ArrowCursor);
    setMaximumWidth(320);
    setMinimumWidth(260);
    setObjectName("search");
    m_searchButton->setObjectName("searchBtn");
    m_searchButton->setToolTip("搜索");
    m_searchButton->setFixedSize(25,20);

    m_searchMenu->setObjectName("menu_search");

    QHBoxLayout *mainLayout = new QHBoxLayout(this);

    mainLayout->addStretch();
    mainLayout->addWidget(m_searchButton);

    setTextMargins(0,0,20,0);
    setContentsMargins(0,0,0,0);
    mainLayout->setContentsMargins(2,0,7,0);

    this->setLayout(mainLayout);
}

void SearchLineEdit::initConnect()
{
    connect(m_searchMenu->m_cutAction, &QAction::triggered, this, &SearchLineEdit::cut);
    connect(m_searchMenu->m_copyAction, &QAction::triggered, this, &SearchLineEdit::copy);
    connect(m_searchMenu->m_pasteAction, &QAction::triggered, this, &SearchLineEdit::paste);
    connect(m_searchMenu->m_pasteSearchAction, &QAction::triggered, [this]() {
        paste();
        searchContent();
    });
    connect(m_searchMenu->m_deleteAction, &QAction::triggered, [this]() {
        QString t = text();
        int i = selectionStart();
        t.remove(i, selectedText().length());
        setText(t);
        setCursorPosition(i);
    });
    connect(m_searchMenu->m_selectAllAction, &QAction::triggered, this, &SearchLineEdit::selectAll);
    connect(m_searchButton, &QPushButton::clicked, this, &SearchLineEdit::searchContent);
    connect(this, &SearchLineEdit::textChanged, [this]() {
        setToolTip(text());
    });
}
