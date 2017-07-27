#ifndef MSLIDER_H
#define MSLIDER_H

#include <QSlider>

class mSlider : public QSlider
{
    Q_OBJECT
public:
    explicit mSlider(QWidget *parent = 0);
    ~mSlider();

protected:
//    void mousePressEvent(QMouseEvent *event) override;
//    void mouseReleaseEvent(QMouseEvent *event) override;

signals:

public slots:
};

#endif // MSLIDER_H
