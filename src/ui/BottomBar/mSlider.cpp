#include "mSlider.h"

#include <qevent.h>

mSlider::mSlider(QWidget *parent)
    : QSlider(parent)
{
    setCursor(Qt::PointingHandCursor);
    setMouseTracking(true);
    setOrientation(Qt::Horizontal);
//    setMinimumSize(310,12);
    setMaximumHeight(12);
    installEventFilter(parent);
}

mSlider::~mSlider()
{

}

//void mSlider::mousePressEvent(QMouseEvent *event)
//{

//}

//void mSlider::mouseReleaseEvent(QMouseEvent *event)
//{

//}
