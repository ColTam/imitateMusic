#ifndef MIDPLAYLISTLISTITEM_H
#define MIDPLAYLISTLISTITEM_H

#include <Base/baseWidget.h>

class basePushButton;
class QLabel;

class midPlayListListItem : public baseWidget
{
    Q_OBJECT
public:
    explicit midPlayListListItem(QWidget *parent = 0);
    ~midPlayListListItem();

signals:

public slots:

private:
    void initForm();
    void initWidget();
    void initConnect();

private:
    basePushButton *m_delayPlayButon;
    QLabel *m_nameLabel;

    QWidget *m_rightWidget;
    basePushButton *m_MVButton;
    basePushButton *m_favoriteButton;
    basePushButton *m_deleteButton;
    basePushButton *m_moreButton;
    QLabel *m_timeLabel;

    friend class midPlayListListWidget;
};

#endif // MIDPLAYLISTLISTITEM_H
