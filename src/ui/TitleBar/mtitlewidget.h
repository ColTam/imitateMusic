#ifndef MTITLEWIDGET_H
#define MTITLEWIDGET_H

#include <QWidget>
#include <Base/baseTitleBar.h>

class QLabel;
class basePushButton;
class SearchLineEdit;
class TitleMenu;

class mTitleWidget : public baseTitleBar
{
    Q_OBJECT
public:
    explicit mTitleWidget(QWidget *parent = 0);
    ~mTitleWidget();

signals:
    void showMusizLibrary();
    void hideMusizLibrary();
    void minimizeApp();
    void closeApp();

public slots:

protected:
    void contextMenuEvent(QContextMenuEvent *event) override;

private:
    void initForm();
    void initWidget();
    void initConnect();

private:
    basePushButton *m_iconButton;

    basePushButton *m_loginButton;
    QLabel *m_lineLabel;
    basePushButton *m_registerButton;

    basePushButton *m_returnButton;
    basePushButton *m_refreshButton;

    SearchLineEdit *m_searchLineEdit;

    basePushButton *m_toolButton;
    basePushButton *m_gameButton;
    basePushButton *m_newsButton;
    basePushButton *m_skinButton;
    basePushButton *m_menuButton;

    QLabel *m_lineLabel_2;

    basePushButton *m_remoteButton;
    basePushButton *m_hideMusicLibraryButton;//hide show library
    basePushButton *m_minimizeButton;
    basePushButton *m_closeButton;

    TitleMenu *m_titleMenu;
};

#endif // MTITLEWIDGET_H
