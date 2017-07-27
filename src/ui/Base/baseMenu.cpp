#include "baseMenu.h"

#include <qevent.h>

baseMenu::baseMenu(QWidget *parent) : QMenu(parent)
{

}

void baseMenu::keyPressEvent(QKeyEvent *event)
{
    event->ignore();
}

void baseMenu::showEvent(QShowEvent *event)
{
//    this->move(this->mapFromGlobal(QCursor::pos())+QPoint(5,5));
}
