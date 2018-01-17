#include "baseMenu.h"

#include <qevent.h>
#include <QDebug>

baseMenu::baseMenu(QWidget *parent) : QMenu(parent)
{

}

void baseMenu::keyPressEvent(QKeyEvent *event)
{
    event->ignore();
}

void baseMenu::showEvent(QShowEvent *event)
{
    this->move(QPoint(this->x()+7, this->y()-9));
}

void baseMenu::leaveEvent(QEvent *event)
{
    event->ignore();
}
