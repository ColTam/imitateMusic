#ifndef MIDPLAYLISTLISTWIDGET_H
#define MIDPLAYLISTLISTWIDGET_H

#include <QScrollArea>

#include <Base/baseWidget.h>

class baseWidget;
class basePushButton;
class midPlayListListItem;

class QFormLayout;

class midPlayListListWidget : public QScrollArea
{
    Q_OBJECT
public:
    enum musicState {
        IS_EMPTY = 0
        , NORMAL
        , PLAYING
    };

    musicState m_state;
    explicit midPlayListListWidget(QWidget *parent = 0);
    ~midPlayListListWidget();

public Q_SLOTS:
    void addItem2List();

protected:
    void contextMenuEvent(QContextMenuEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

private:
    void initForm();
    void initWidget();
    void initConnect();

private:
    baseWidget *m_emptyWidget;

    basePushButton *m_addFileIcon;
    basePushButton *m_addFileButton;
    basePushButton *m_addDirIcon;
    basePushButton *m_addDirButton;

    midPlayListListItem *m_item;

    QFormLayout *m_listLayout;
};

#endif // MIDPLAYLISTLISTWIDGET_H
