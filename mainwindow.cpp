//
// Created by 23776 on 2023/8/11.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include "mainwindow.h"

const int HomePageWidth = 1516;
const int HomePageHeight = 854;

mainwindow::mainwindow(QWidget *parent) :
	QWidget(parent) {
	setMinimumHeight(500);   // 设置最小的高度
//  setMinimumWidth();    // 设置最小宽度
	m_pChatListWidget = nullptr;
	m_pLeftBarWidget = nullptr;
	initUI();
}

mainwindow::~mainwindow() {

}

void mainwindow::initUI() {
	setGeometry(50, 50, HomePageWidth, HomePageHeight);
	// 初始化left bar
	m_pLeftBarWidget = new LeftBarWidget(this);
	m_pLeftBarWidget->setGeometry(0, 0, 144, this->height());
	m_pLeftBarWidget->show();
	// 初始化聊天列表框  -- 尝试使用一个box装载子文件

	m_pChatListWidget = new ChatListWidget(this);
	m_pChatListWidget->setGeometry(144, 0, 307, this->height());
	m_pChatListWidget->show();

}
void mainwindow::resizeEvent(QResizeEvent *event) {
	// 使用新的窗口大小给子窗口赋值
	QSize newSize = event->size();
	m_pLeftBarWidget->ResizeWindows(newSize.width(), newSize.height());  // 重设左边框的大小
	qDebug() << newSize.height() << "\t";
	QWidget::resizeEvent(event);
}
