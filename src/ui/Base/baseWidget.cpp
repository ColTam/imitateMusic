#include "baseWidget.h"

#include <QPainter>
#include <QStyleOption>
#include <qevent.h>

baseWidget::baseWidget(QWidget *parent)
    : QWidget(parent)
{

}

void baseWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
