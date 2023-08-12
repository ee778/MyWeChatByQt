//
// Created by 23776 on 2023/8/11.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include "mainwindow.h"

const int HomePageWidth = 1516;
const int HomePageHeight = 854;

mainwindow::mainwindow(QWidget *parent) :
	QWidget(parent) {
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
	m_pLeftBarWidget->setGeometry(0, 0, 144, 854);
	m_pLeftBarWidget->show();
	// 初始化聊天列表框  -- 尝试使用一个box装载子文件

	m_pChatListWidget = new ChatListWidget(this);
	m_pChatListWidget->setGeometry(144, 0, 307, 852);
	m_pChatListWidget->show();

}
