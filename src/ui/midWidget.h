#ifndef MIDWIDGET_H
#define MIDWIDGET_H

#include <QWidget>

class MidWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MidWidget(QWidget *parent = 0);
    ~MidWidget();
};

#endif // MIDWIDGET_H
