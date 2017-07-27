#ifndef MIDRIGHTWIDGET_H
#define MIDRIGHTWIDGET_H

#define LAYOUT_SPACING 20

#include <QWidget>

class basePushButton;
class QStackedWidget;
class QPropertyAnimation;

class midRightLibraryWidget;
class midRightRadioWidget;
class midRightSongListWidget;
class midRightMVWidget;
class midRightLiveWidget;
class midRightKTVWidget;
class midRightLyricWidget;

class MidRightWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int m_index READ getIndex WRITE setIndex)
public:
    explicit MidRightWidget(QWidget *parent = 0);
    ~MidRightWidget();

    int getIndex() { return m_index; }
    void setIndex(int i) { m_index = i; update(); }

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
    void on_stackWidget_currentChanged(int index);

private:
    basePushButton *m_libraryButton;
    basePushButton *m_radioButton;
    basePushButton *m_songListButton;
    basePushButton *m_MVButton;
    basePushButton *m_liveButton;
    basePushButton *m_KTVButton;
    basePushButton *m_lyricButton;
    QVector<basePushButton *> m_buttonVector;

    QStackedWidget *m_stackWidget;
    midRightLibraryWidget   *m_libraryWidget;
    midRightRadioWidget     *m_radioWidget;
    midRightSongListWidget  *m_songListWidget;
    midRightMVWidget        *m_MVWidget;
    midRightLiveWidget      *m_liveWidget;
    midRightKTVWidget       *m_KTVWidget;
    midRightLyricWidget     *m_lyricWidget;

    int m_index;
    int m_preIndex;

    QPixmap m_pix;
    QPropertyAnimation *m_buttonAnimation;

    QColor m_backgroundColor;
    bool   m_isLyricWidget;
};

#endif // MIDRIGHTWIDGET_H
