#ifndef MIDPLAYLISTWIDGET_H
#define MIDPLAYLISTWIDGET_H

#include <Base/baseWidget.h>

class midPlayListButton;
class midPlayListListWidget;

class midPlayListWidget : public baseWidget
{
    Q_OBJECT
public:
    explicit midPlayListWidget(QWidget *parent = 0);

public:
    void setListText(const QString &text);
    void setListNumber(int number);
    QString getListText() const;

signals:
    void newListSignal();

public slots:



private:
    void initForm();
    void initWidget();
    void initConnect();

private:
    midPlayListButton *m_playButton;
    midPlayListListWidget *m_playListWidget;
};

#endif // MIDPLAYLISTWIDGET_H
