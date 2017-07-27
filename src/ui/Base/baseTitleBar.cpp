#include "baseTitleBar.h"

#include <QContextMenuEvent>
#include <QPainter>
#include <QStyleOption>

#ifdef Q_OS_WIN
#pragma comment(lib, "user32.lib")
#include <qt_windows.h>
#else
#endif

baseTitleBar::baseTitleBar(QWidget *parent) : baseWidget(parent)
{

}

baseTitleBar::~baseTitleBar()
{

}

void baseTitleBar::mousePressEvent(QMouseEvent *event)
{
#ifdef Q_OS_WIN
    if (ReleaseCapture()) {
        QWidget *window = this->window();
        if (window->isTopLevel())
            SendMessage(HWND(window->winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
    }
    event->ignore();
#endif
}

void baseTitleBar::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        QWidget *window = this->window();
        if (window->isMaximized()) {
            window->showNormal();
        } else
            window->showMaximized();
    }
}
