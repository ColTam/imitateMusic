#ifndef BASEMENU_H
#define BASEMENU_H

#include <QMenu>

class baseMenu : public QMenu
{
    Q_OBJECT
public:
    explicit baseMenu(QWidget *parent = 0);
    ~baseMenu() {}

    bool inChild(const QWidget *w) {
        return w->mapFromGlobal(QCursor::pos()).x() >= 0 &&
                w->mapFromGlobal(QCursor::pos()).y() >= 0 &&
                w->mapFromGlobal(QCursor::pos()).x() <= w->width() &&
                w->mapFromGlobal(QCursor::pos()).y() <= w->height();
    }

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void showEvent(QShowEvent *event) override;
    void leaveEvent(QEvent *event) override;
};

#endif // BASEMENU_H
