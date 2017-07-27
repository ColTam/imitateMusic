#ifndef CUSTOMMENU_H
#define CUSTOMMENU_H

#include <QMenu>

class customMenu : public QMenu
{
    Q_OBJECT
public:
    explicit customMenu(QWidget *parent = 0);
    ~customMenu();
};

#endif // CUSTOMMENU_H
