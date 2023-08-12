#include "chatlistwidget.h"
#include "mainwindow.h"

ChatListWidget::ChatListWidget(QWidget *parent): QWidget(parent) {
	this->resize(307, 852);
	this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
	this->hide();
	this->setStyleSheet(ChatListWidgetQSS);
	m_pTopComponentBox = nullptr;
	m_pSearchAndAddBox = nullptr;
	m_pAddIcon = nullptr;
	m_pSearchText = nullptr;
	m_pSearchIcon = nullptr;
	InitTopAear();   // 初始化头部区域

}

ChatListWidget::~ChatListWidget() {

}

// 初始化头部区域
void ChatListWidget::InitTopAear() {
	m_pTopComponentBox = new QGroupBox(this);
	m_pTopComponentBox->setGeometry(0, 0, 307, 62);

	m_pSearchAndAddBox = new QGroupBox(m_pTopComponentBox);
	m_pSearchAndAddBox->setGeometry(20, 24, 269, 24);
    m_pSearchAndAddBox->setStyleSheet("border: none");
    m_pAddIcon = new QLabel(m_pSearchAndAddBox);
    m_pAddIcon->setPixmap(QPixmap(":/main/image/AddIcon.png"));
	m_pAddIcon->resize(15, 15);
	m_pAddIcon->move(254, 4);
    m_pAddIcon->setStyleSheet("position: static; left: 254.5px; top: 4.5px; width: 15px; height: 15px; opacity: 1; ");
    //background-color: #7A8294;
	m_pSearchBox = new QGroupBox(m_pSearchAndAddBox);
	m_pSearchBox->setGeometry(0, 0, 247, 24);
    m_pSearchBox->setStyleSheet("position: static; left: 0px; top: 0px; width: 247px; height: 24px; border-radius: 4px; opacity: 1; spacing: 10px; background-color: #F2F3F5;");
    //qproperty-alignment: 'AlignVCenter'; padding: 3px 99px;
	m_pSearchDetailBox = new QGroupBox(m_pSearchBox);
	m_pSearchDetailBox->setGeometry(103, 3, 40, 17);

	m_pSearchText = new QLabel(m_pSearchDetailBox);
    m_pSearchText->setGeometry(16, 0, 24, 17);
    m_pSearchText->setStyleSheet("position: static; left: 16px; top: 0px; width: 24px; height: 17px; opacity: 1; font-family: PingFangSC-Regular; font-size: 12px; font-weight: normal; line-height: 17px; letter-spacing: 0px; color: #B8B8BC;");
    m_pSearchText->setText(tr("搜索"));

	m_pSearchIcon = new QLabel(m_pSearchDetailBox);
	m_pSearchIcon->setPixmap(QPixmap(":/main/image/SearchIcon.png"));
	m_pSearchIcon->resize(12, 12);
	m_pSearchIcon->move(0, 2);
    m_pSearchIcon->setStyleSheet("position: static;opacity: 1;left: 0px; top: 2.5px; width: 12px; height: 12px;");
    // background-color: #8F9BAD;

}

