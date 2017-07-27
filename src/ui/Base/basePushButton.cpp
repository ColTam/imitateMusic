#include "basePushButton.h"

basePushButton::basePushButton(QWidget *parent) : QPushButton(parent)
{
    setFlat(true);
    setCursor(Qt::PointingHandCursor);
}
