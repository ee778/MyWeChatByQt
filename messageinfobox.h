#ifndef MESSAGEINFOBOX_H
#define MESSAGEINFOBOX_H

#include <QWidget>
#include "GlobalResoure.h"
class MessageInfoBox: public QGroupBox
{
    Q_OBJECT
public:
    explicit MessageInfoBox(QWidget *parent = nullptr);
	void initUI();
	void setContactsAvater(QPixmap *pixmap);
	void setContactsName(const QString& name);
	void setLastTime(const QString& qtime);
 private:
	QLabel *m_pContactsAvater;
	QLabel *m_pLastMessage;
	QLabel *m_pContactsName;
	QLabel *m_pLastTime;   // 最后发布时间
	QGroupBox *m_pContactsInfoBox;
	QGroupBox *m_pContactsNameAndTimeBox;
};

#endif // MESSAGEINFOBOX_H
