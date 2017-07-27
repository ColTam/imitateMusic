#ifndef MIDPLAYLISTLINEEDIT_H
#define MIDPLAYLISTLINEEDIT_H

#include <QLineEdit>

class midPlayListLineEditMenu;

class midPlayListLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit midPlayListLineEdit(QWidget *parent = 0);
    ~midPlayListLineEdit();

protected:
    void focusOutEvent(QFocusEvent *event) override;
    void contextMenuEvent(QContextMenuEvent *event) override;

signals:

public slots:

private:
    void initConnect();

private:
    midPlayListLineEditMenu *m_contextMenu;

    friend class midPlayListButton;
};

#endif // MIDPLAYLISTLINEEDIT_H
