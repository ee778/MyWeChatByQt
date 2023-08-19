#include "messageinfobox.h"

MessageInfoBox::MessageInfoBox(QWidget *parent): QGroupBox(parent)
{
	this->resize(307, 67);
	this->setStyleSheet("border: none;");
	m_pContactsAvater = nullptr;
	m_pLastMessage = nullptr;
	m_pContactsName = nullptr;
	m_pLastTime  = nullptr;   // 最后发布时间
	m_pContactsInfoBox  = nullptr;
	m_pContactsNameAndTimeBox  = nullptr;

	initUI();
}
void MessageInfoBox::initUI() {
	m_pContactsAvater = new QLabel(this);
	m_pContactsAvater->resize(40, 40);
	m_pContactsAvater->move(19, 12);
	m_pContactsAvater->setPixmap(QPixmap(":/main/avatar/Rectangle33.png"));
	//联系信息框，包括名称加时间框加最后消息
	m_pContactsInfoBox = new QGroupBox(this);
	m_pContactsInfoBox->setGeometry(69, 14, 218, 37);
	m_pContactsInfoBox->setStyleSheet("border: none;");

	// 最后消息
	m_pLastMessage = new QLabel(m_pContactsInfoBox);
	m_pLastMessage->setText(tr("最后消息"));
	m_pLastMessage->setAlignment(Qt::AlignLeft);
	m_pLastMessage->setGeometry(0, 20, 24, 17);  // width的宽度可能需要变化
	m_pLastMessage->setStyleSheet("opacity: 1; font-family: PingFangSC-Medium; font-size: 12px; font-weight: normal; line-height: 17px; letter-spacing: 0px; color: #B0B0B0;");
	// 名称加时间框
	m_pContactsNameAndTimeBox = new QGroupBox(m_pContactsInfoBox);
	m_pContactsNameAndTimeBox->setGeometry(0, 0, 218, 20);
	m_pContactsNameAndTimeBox->setStyleSheet("border: none;");

	// 名称框
	m_pContactsName = new QLabel(m_pContactsInfoBox);
	m_pContactsName->setText("缺省");
	m_pContactsName->setAlignment(Qt::AlignLeft);
	m_pContactsName->setGeometry(0, 0, 84, 20);   //这个width可能会发生改变
	m_pContactsName->setStyleSheet("opacity: 1; font-family: PingFangSC-Regular; font-size: 14px; font-weight: normal; line-height: 20px; letter-spacing: 0px; color: #000000;");

	// 时间
	m_pLastTime = new QLabel(m_pContactsNameAndTimeBox);
	m_pLastTime->setText("13:00");
	m_pLastTime->setGeometry(182, 3, 36, 14);
	m_pLastTime->setAlignment(Qt::AlignRight);  // 尝试靠右显示
	m_pLastTime->setStyleSheet("opacity: 0.4; font-family: PingFangSC-Regular; font-size: 10px; font-weight: normal; line-height: 14px; letter-spacing: 0px; color: #000000;");

}
void MessageInfoBox::setContactsAvater(QPixmap *pixmap) {
	m_pContactsAvater->setPixmap(*pixmap);
}
void MessageInfoBox::setContactsName(const QString& name) {
	m_pContactsName->setText(name);
}
void MessageInfoBox::setLastTime(const QString& qtime) {
	m_pLastTime->setText(qtime);
}



