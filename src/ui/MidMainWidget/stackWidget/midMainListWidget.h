#ifndef MIDMAINLISTWIDGET_H
#define MIDMAINLISTWIDGET_H

#include <QScrollArea>

class midPlayListWidget;
class QFormLayout;

class midMainListWidget : public QScrollArea
{
    Q_OBJECT
public:
    explicit midMainListWidget(QWidget *parent = 0);
    ~midMainListWidget();

public Q_SLOTS:
    void newListSlot();

private:
    void initForm();
    void initWidget();
    void initConnect();

private:
    midPlayListWidget *m_defaultWidget;
    midPlayListWidget *m_latelyWidget;
    QFormLayout *m_mainLayout;
};

#endif // MIDMAINLISTWIDGET_H
