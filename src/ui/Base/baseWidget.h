#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QWidget>

class baseWidget : public QWidget
{
    Q_OBJECT
public:
    explicit baseWidget(QWidget *parent = 0);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *) override;
};

#endif // BASEWIDGET_H
