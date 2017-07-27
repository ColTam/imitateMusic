#ifndef MIDPLAYLISTBUTTON_H
#define MIDPLAYLISTBUTTON_H

#include <QPushButton>

class baseWidget;
class basePushButton;
class midPlayListButtonMenu;
class midPlayListLineEdit;

class QLabel;

class midPlayListButton : public QPushButton
{
    Q_OBJECT
public:
    explicit midPlayListButton(QWidget *parent = 0);
    ~midPlayListButton();

signals:
    void newListSignal();

public slots:
    void reNameSlot();

public:
    void setIcon(const QString &icon);
    void setText(const QString &text);
    void setNumber(int number);

protected:
    void enterEvent(QEvent *) override;
    void leaveEvent(QEvent *) override;
    void contextMenuEvent(QContextMenuEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void initForm();
    void initWidget();
    void initConnect();

private:
    QLabel *m_iconLabel;
    QLabel *m_nameLabel;
    QLabel *m_numberLabel;

    baseWidget *m_rightWidget;
    basePushButton *m_upLoadingButton;
    basePushButton *m_shareButton;
    basePushButton *m_listButton;

    midPlayListLineEdit *m_nameEdit;

    midPlayListButtonMenu *m_contextMenu;

    bool isListBtnClicked;
};

#endif // MIDPLAYLISTBUTTON_H
