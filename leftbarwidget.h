#ifndef LEFTBARWIDGET_H
#define LEFTBARWIDGET_H

#include <QWidget>
#include "GlobalResoure.h"

class LeftBarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LeftBarWidget(QWidget *parent = nullptr);
    ~LeftBarWidget() override;
	void initUI();
private:
	QGroupBox *m_pLeftSidebarBox;  // 左侧边栏
	QGroupBox *m_pAvatarComponentBox; // 图像组件框
	QLabel *m_pUserNameText; // 用户名姓名
	QLabel *m_pAvatarImage; // 用户头像
	QGroupBox *m_pBottomComponentBox;  // 底部组件框
	QGroupBox *m_pMoreComponentBox;   // 更多组件框
	QLabel *m_pMoreIcon;   // 更多 图片
	QLabel *m_pMoreText;   // 更多 文字
	QGroupBox *m_pBackstageManagementComponentBox;  // 管理后台组件框
	QLabel *m_pBackstageManagementIcon;   // 管理后台图片
	QLabel *m_pBackstageManagementText;   // 管理后台文字

	QLabel *m_pChatBubble; // 聊天气泡
	QGroupBox *m_pLeftMenuBar;  // 左菜单栏

	QGroupBox *m_pContactsBox;  // 通讯录框
	QLabel *m_pContactsText;   // 通讯录文字
	QLabel *m_pContactsIcon;  // 通讯录图标

	QGroupBox *m_pEmailBox; // 邮件框
	QLabel *m_pEmailText;  // 邮件文字
	QLabel *m_pEmailIcon;  // 邮件框

	QGroupBox *m_pDocumentBox;
	QLabel *m_pDocumentText;
	QLabel *m_pDocumentIcon;

	QGroupBox *m_pScheduleBox;
	QLabel *m_pScheduleText;
	QLabel *m_pScheduleIcon;

	QGroupBox *m_pMeetingBox;
	QLabel *m_pMeetingText;
	QLabel *m_pMeetingIcon;

	QGroupBox *m_pWorkbenchBox;
	QLabel *m_pWorkbenchText;
	QLabel *m_pWorkbenchIcon;

    QGroupBox *m_pMessageBox;
    QLabel *m_pMessageText;
    QLabel *m_pMessageIcon;

	QGroupBox *m_pSelectBackground;
};

#endif // LEFTBARWIDGET_H
