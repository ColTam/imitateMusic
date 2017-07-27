#ifndef BASEPUSHBUTTON_H
#define BASEPUSHBUTTON_H

#include <QPushButton>

class basePushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit basePushButton(QWidget *parent = 0);
    ~basePushButton() {}

signals:

public slots:
};

#endif // BASEPUSHBUTTON_H
