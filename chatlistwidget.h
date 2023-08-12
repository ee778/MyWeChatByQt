#ifndef CHATLISTWIDGET_H
#define CHATLISTWIDGET_H

#include <QWidget>
#include "GlobalResoure.h"

const QString ChatListWidgetQSS = "position: absolute;\n"
								  "opacity: 1;\n"
								  "padding: 0px;\n"
								  "background: #FFFFFF;\n";

class ChatListWidget:public QWidget
{
    Q_OBJECT
public:
    explicit ChatListWidget(QWidget *parent = nullptr);
	void InitTopAear();
	~ChatListWidget() override;
 private:
	QGroupBox *m_pTopComponentBox;
	QGroupBox *m_pSearchAndAddBox;
	QLabel *m_pAddIcon;
	QGroupBox *m_pSearchBox;   // 搜索框
	QGroupBox *m_pSearchDetailBox;  //搜索框内部详细信息
	QLabel *m_pSearchText;
	QLabel *m_pSearchIcon;
};

#endif // CHATLISTWIDGET_H
