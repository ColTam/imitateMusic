#ifndef BASETITLEBAR_H
#define BASETITLEBAR_H

#include "baseWidget.h"

class baseTitleBar : public baseWidget
{
    Q_OBJECT
public:
    explicit baseTitleBar(QWidget *parent = 0);
    ~baseTitleBar();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;

signals:

public slots:
};

#endif // BASETITLEBAR_H
