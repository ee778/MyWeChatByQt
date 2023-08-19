#ifndef CHATLISTWIDGET_H
#define CHATLISTWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include "GlobalResoure.h"
#include "messageinfobox.h"

const QString ChatListWidgetQSS = "position: absolute;\n"
								  "opacity: 1;\n"
								  "padding: 0px;\n"
								  "background: #FFFFFF;\n";

class ChatListWidget:public QWidget
{
    Q_OBJECT
public:
    explicit ChatListWidget(QWidget *parent = nullptr);
	void InitTopAear();   // 初始化头部区域
	void InitMessageTable();  //初始化信息表
	void ResizeWindows();   // 根据父接口来来重设窗口的高度 可以不用传参数，直接读取父窗口的高度
	~ChatListWidget() override;  // 析构函数
 private:
	QGroupBox *m_pTopComponentBox;
	QGroupBox *m_pSearchAndAddBox;
	QLabel *m_pAddIcon;
	QGroupBox *m_pSearchBox;   // 搜索框
	QGroupBox *m_pSearchDetailBox;  //搜索框内部详细信息
	QLabel *m_pSearchText;
	QLabel *m_pSearchIcon;

	QTableWidget *m_iMessageInfoTableWidget;  // 聊天列表   大小为307 * 84 一共能够显示12个窗口
	std::vector<MessageInfoBox*> m_vMessageInfoBoxList;  // 聊天信息列表数组
//	std::vector<        // 这里应该还需要一些数据
};

#endif // CHATLISTWIDGET_H
