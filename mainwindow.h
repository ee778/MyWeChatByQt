//
// Created by 23776 on 2023/8/11.
//

#ifndef WECHAT__MAINWINDOW_H_
#define WECHAT__MAINWINDOW_H_

#include <QWidget>

#include "GlobalResoure.h"
#include "chatlistwidget.h"
#include "leftbarwidget.h"
class mainwindow : public QWidget {
 Q_OBJECT

 public:
	explicit mainwindow(QWidget *parent = nullptr);
	~mainwindow() override;
	void initUI();  // 用于初始化界面
 protected:
	void resizeEvent(QResizeEvent *event) override;
 private:
	LeftBarWidget *m_pLeftBarWidget;

	QGroupBox *m_pChatListBox;  // 聊天列表装载框
	ChatListWidget *m_pChatListWidget;  // 聊天列表框


};

#endif //WECHAT__MAINWINDOW_H_
