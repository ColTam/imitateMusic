#include "midPlayListButton.h"
#include "midPlayListButtonMenu.h"
#include "midPlayListLineEdit.h"

#include <QLabel>
#include <QHBoxLayout>
#include <QDebug>
#include <QContextMenuEvent>
#include <QMessageBox>

#include <Base/basePushButton.h>
#include <Base/baseWidget.h>

midPlayListButton::midPlayListButton(QWidget *parent)
    : QPushButton(parent)
    , m_iconLabel(new QLabel(this))
    , m_nameLabel(new QLabel(this))
    , m_numberLabel(new QLabel(this))
    , m_rightWidget(new baseWidget(this))
    , m_upLoadingButton(new basePushButton(m_rightWidget))
    , m_shareButton(new basePushButton(m_rightWidget))
    , m_listButton(new basePushButton(m_rightWidget))
    , m_nameEdit(new midPlayListLineEdit(this))
    , m_contextMenu(new midPlayListButtonMenu(this))
    , isListBtnClicked(0)
{
    initForm();
    initWidget();
    initConnect();
    m_nameEdit->setText("新建列表1");
    m_nameEdit->selectAll();
}

midPlayListButton::~midPlayListButton()
{

}

void midPlayListButton::reNameSlot()
{
    if (m_nameEdit->text().isEmpty()) {
        disconnect(m_nameEdit, &QLineEdit::editingFinished, this, &midPlayListButton::reNameSlot);
        QMessageBox msg(QMessageBox::NoIcon,"错误","列表名不能为空   ");
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setButtonText(QMessageBox::Ok, "确定");
        msg.setStyleSheet("color: #000;");
        msg.exec();
        m_nameEdit->setFocus();
        m_nameEdit->setText(m_nameLabel->text());
        m_nameEdit->selectAll();
        connect(m_nameEdit, &QLineEdit::editingFinished, this, &midPlayListButton::reNameSlot);
    } else {
        setText(m_nameEdit->text().left(20));
    }
}

void midPlayListButton::setIcon(const QString &icon)
{
    m_iconLabel->setStyleSheet(QString("image: url(%1)").arg(icon));
}

void midPlayListButton::setText(const QString &text)
{
    if (text.isEmpty()){
        m_nameEdit->setFocus();
        return;
    }
    QFont font(m_nameLabel->font());
    QFontMetrics fontM(font);
    m_nameLabel->setToolTip(text);
    m_nameLabel->setText(fontM.elidedText(text, Qt::ElideRight, width()-143));
    m_nameEdit->hide();
}

void midPlayListButton::setNumber(int number)
{
    m_numberLabel->setText(QString("[%1]").arg(number));
}

void midPlayListButton::enterEvent(QEvent *)
{
    m_upLoadingButton->show();
    m_shareButton->show();
    m_listButton->show();
}

void midPlayListButton::leaveEvent(QEvent *)
{
    if (!isListBtnClicked) {
        m_upLoadingButton->hide();
        m_shareButton->hide();
        m_listButton->hide();
    }
}

void midPlayListButton::contextMenuEvent(QContextMenuEvent *event)
{
    bool isUploadBtn = m_contextMenu->inChild(m_upLoadingButton);
    bool isShareBtn = m_contextMenu->inChild(m_shareButton);
    bool isListBtn = m_contextMenu->inChild(m_listButton);

    if (!isUploadBtn && !isShareBtn && !isListBtn)
        m_contextMenu->exec(QCursor::pos()+QPoint(5,5));

    event->accept();
}

void midPlayListButton::resizeEvent(QResizeEvent *event)
{
    setText(m_nameLabel->toolTip());
    QWidget::resizeEvent(event);
}

void midPlayListButton::initForm()
{
    setMouseTracking(true);
    setMinimumSize(310, 40);
    setMaximumSize(380, 40);

    m_iconLabel->setFixedSize(9,9);
    m_numberLabel->setText("[0]");

    m_iconLabel->setObjectName("playList_icon");
    m_nameLabel->setObjectName("playList_name");

    m_upLoadingButton->setObjectName("playList_upLoading");
    m_shareButton->setObjectName("playList_share");
    m_listButton->setObjectName("playList_list");
    m_nameEdit->setObjectName("playList_edit");

    m_upLoadingButton->setToolTip("一键升级无损音质");
    m_shareButton->setToolTip("分享");
    m_listButton->setToolTip("列表菜单");

    m_nameEdit->setGeometry(18, 4, 225, 32);
    m_nameEdit->installEventFilter(this);
}

void midPlayListButton::initWidget()
{
    QHBoxLayout *wLayout = new QHBoxLayout();
    wLayout->addWidget(m_upLoadingButton);
    wLayout->addSpacing(3);
    wLayout->addWidget(m_shareButton);
    wLayout->addSpacing(3);
    wLayout->addWidget(m_listButton);
    wLayout->setSpacing(5);
    wLayout->setContentsMargins(8,0,0,0);

    m_rightWidget->setFixedSize(60+20,20);
    m_rightWidget->setLayout(wLayout);

    QHBoxLayout *mainLayout = new QHBoxLayout();

    mainLayout->addWidget(m_iconLabel);
    mainLayout->addWidget(m_nameLabel);
    mainLayout->addWidget(m_numberLabel);
    mainLayout->addStretch();
    mainLayout->addWidget(m_rightWidget);

    mainLayout->setSpacing(5);
    mainLayout->setContentsMargins(9,0,14,2);

    setLayout(mainLayout);

    m_upLoadingButton->hide();
    m_shareButton->hide();
    m_listButton->hide();
}

void midPlayListButton::initConnect()
{
    connect(m_contextMenu->m_newAction, &QAction::triggered, this, &midPlayListButton::newListSignal);
    connect(m_contextMenu->m_reNameAction, &QAction::triggered, [this](){
        m_nameEdit->show();
        m_nameEdit->setText(m_nameLabel->text());
        m_nameEdit->setFocus();
        m_nameEdit->selectAll();
    });
    connect(m_nameEdit, &QLineEdit::editingFinished, this, &midPlayListButton::reNameSlot);
    connect(m_listButton, &basePushButton::clicked, [this](){
        isListBtnClicked = true;
        m_contextMenu->exec(m_rightWidget->mapToGlobal(m_listButton->pos()) + QPoint(10, 25));
        m_upLoadingButton->hide();
        m_shareButton->hide();
        m_listButton->hide();
        isListBtnClicked = false;
    });
}
