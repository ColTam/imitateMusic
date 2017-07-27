#ifndef MIDMAINWIDGET_H
#define MIDMAINWIDGET_H

#include <QWidget>

class QStackedWidget;
class QPropertyAnimation;

class basePushButton;
class midMainListWidget;
class midMainCloudWidget;
class midMainRadioWidget;
class midMainPhoneWidget;
class midMainLoadWidget;

class midMainWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int m_index READ getIndex WRITE setIndex)
public:
    explicit midMainWidget(QWidget *parent = 0);
    ~midMainWidget();

public:
    static QColor backgroundColor;

    int getIndex() { return m_index; }
    void setIndex(int i) { m_index = i; update(); }

    static QColor getBackgroundColor();
    static void setBackgroundColor(const QColor &value);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *) override;

private:
    void initForm();
    void initWidget();
    void initConnect();

private Q_SLOTS:
    void updateButtonStyle(int index);
    void on_mainWidget_currentChanged(int index);

private:
    basePushButton *m_listButton;
    basePushButton *m_cloudButton;
    basePushButton *m_radioButton;
    basePushButton *m_phoneButton;
    basePushButton *m_loadButton;

    QStackedWidget *m_stackWidget;

    midMainListWidget  *m_listWidget;
    midMainCloudWidget *m_cloudWidget;
    midMainRadioWidget *m_radioWidget;
    midMainPhoneWidget *m_phoneWidget;
    midMainLoadWidget  *m_loadWidget;

    QPropertyAnimation *m_buttonAnimation;
    QPropertyAnimation *m_stackWidgetAnimation;

    QPixmap m_pix;

    int  m_index;
    int  m_preIndex;
    bool m_isAnimation;
};

#endif // MIDMAINWIDGET_H
