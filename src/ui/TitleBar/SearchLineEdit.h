#ifndef SEARCHLINEEDIT_H
#define SEARCHLINEEDIT_H

#include <QWidget>
#include <QLineEdit>

class basePushButton;
class SearchMenu;

class SearchLineEdit : public QLineEdit
{
public:
    SearchLineEdit(QWidget *parent = 0);
    ~SearchLineEdit();

public Q_SLOTS:
    void searchContent();

protected:
    void contextMenuEvent(QContextMenuEvent *event) override;

private:
    void initForm();
    void initConnect();

private:
    basePushButton *m_searchButton;
    SearchMenu     *m_searchMenu;
};

#endif // SERCHLINEEDIT_H
