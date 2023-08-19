#include "leftbarwidget.h"


// 左侧边栏的样式
const QString LeftSideBarQSS = "QWidget{\n"
							   "    position: absolute;\n"
							   "    opacity: 1;\n"
							   "    background-color: #E9E7EA;\n"
							   "    border: none"
							   "}";
// 头像组件样式
const QString AvatarComponentQSS = "QWidget {\n"
								   "    position: absolute;\n"
								   "    opacity: 1;\n"
								   "    padding: 0px;\n"
								   "    spacing: 8px;\n"
								   "}";

// 底部组件框
const QString BottomComponentQSS = "QWidget#bottomIcons {\n"
								   "    position: absolute;\n"
								   "    opacity: 1;\n"
								   "    padding: 0px;\n"
								   "    spacing: 16px;\n"
								   "}";

LeftBarWidget::LeftBarWidget(QWidget *parent) :
    QWidget(parent)
{
	this->resize(144, parent->height()); // 854
	this->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
	this->hide();

	m_pLeftSidebarBox = nullptr;
	m_pAvatarComponentBox = nullptr;
	m_pUserNameText = nullptr;
	m_pAvatarImage = nullptr;
	m_pBottomComponentBox = nullptr;  // 底部组件框
	m_pMoreComponentBox = nullptr;   // 更多组件框
	m_pMoreIcon = nullptr;   // 更多 图片
	m_pMoreText = nullptr;   // 更多 文字
	m_pBackstageManagementComponentBox = nullptr;  // 管理后台组件框
	m_pBackstageManagementIcon = nullptr;   // 管理后台图片
	m_pBackstageManagementText = nullptr;   // 管理后台文字
	initUI();
}

LeftBarWidget::~LeftBarWidget()
{

}
void LeftBarWidget::initUI() {
	// 左边的整体box
	m_pLeftSidebarBox = new QGroupBox(this);
	m_pLeftSidebarBox->setGeometry(0, 0, 144, this->height());
	m_pLeftSidebarBox->setStyleSheet(LeftSideBarQSS);

	// 头像部分的box
	m_pAvatarComponentBox = new QGroupBox(m_pLeftSidebarBox);
	m_pAvatarComponentBox->setGeometry(16, 44, 82, 24);
	m_pAvatarComponentBox->setStyleSheet(AvatarComponentQSS);

	// 设置头像 使用缺省头像
	m_pAvatarImage = new QLabel(m_pAvatarComponentBox);
	m_pAvatarImage->resize(24, 24);
	m_pAvatarImage->move(0, 0);
	m_pAvatarImage->setPixmap(QPixmap(":/main/image/avatar_en.png"));
	m_pAvatarImage->setStyleSheet("left: 0px; top: 0px; width: 24px; height: 24px; border-radius: 1px; opacity: 1; background-repeat: no-repeat; background-position: center; background-color: transparent;");
	// 用户名称
	m_pUserNameText = new QLabel(m_pAvatarComponentBox);
	m_pUserNameText->setGeometry(32, 3, 50, 18);
	m_pUserNameText->setText(tr("hello"));
	m_pUserNameText->setStyleSheet("position: static; left: 32px; top: 3px; width: 50px; height: 18px; opacity: 1; font-family: PingFangSC-Regular; font-size: 13px; font-weight: normal; line-height: 18px; letter-spacing: 0px; color: #3A3D43;");

	//底部组件框
	m_pBottomComponentBox = new QGroupBox(m_pLeftSidebarBox);
	m_pBottomComponentBox->setGeometry(20, 787, 78, 52);
	m_pBottomComponentBox->setStyleSheet(BottomComponentQSS);

	// 管理后台组件框
	m_pBackstageManagementComponentBox = new QGroupBox(m_pBottomComponentBox);
	m_pBackstageManagementComponentBox->setGeometry(0, 0, 78, 18);

	// 管理后台图标
	m_pBackstageManagementIcon = new QLabel(m_pBackstageManagementComponentBox);
	m_pBackstageManagementIcon->resize(16, 16);
	m_pBackstageManagementIcon->move(0, 1);
	m_pBackstageManagementIcon->setPixmap(QPixmap(":/main/image/backstageManagementIcon.png"));
	m_pBackstageManagementIcon->setStyleSheet("position: static; left: 1px; top: 2px; width: 14px; height: 12px; opacity: 1; ");
	// background-color: #6C7680;
	// 管理后台文字
	m_pBackstageManagementText = new QLabel(m_pBottomComponentBox);
	m_pBackstageManagementText->setText(tr("管理后台"));
	m_pBackstageManagementText->setGeometry(26, 0, 52, 18);
	m_pBackstageManagementText->setStyleSheet("position: static; left: 26px; top: 0px; width: 52px; height: 18px; opacity: 1; font-family: PingFangSC-Regular; font-size: 13px; font-weight: normal; line-height: 18px; letter-spacing: 0px; color: #3A3D43;");
	//更多组件框
	m_pMoreComponentBox = new QGroupBox(m_pBottomComponentBox);
	m_pMoreComponentBox->setGeometry(0, 34, 78, 18);

	// 更多图片
	m_pMoreIcon = new QLabel(m_pMoreComponentBox);
	m_pMoreIcon->resize(16, 16);
	m_pMoreIcon->move(0, 1);
	m_pMoreIcon->setPixmap(QPixmap(":/main/image/MoreIcon.png"));
	m_pMoreIcon->setStyleSheet("position: static; left: 1.5px; top: 2.5px; width: 13px; height: 11px; opacity: 1;");
	//  background-color: #6C7680;
	// 更多文字
	m_pMoreText = new QLabel(m_pMoreComponentBox);
	m_pMoreText->setGeometry(26, 0, 26, 18);
	m_pMoreText->setText(tr("更多"));
	m_pMoreText->setStyleSheet("position: static; left: 26px; top: 0px; width: 26px; height: 18px; opacity: 1; font-family: PingFangSC-Regular; font-size: 13px; font-weight: normal; line-height: 18px; letter-spacing: 0px; color: #3A3D43;");

	// 聊天气泡
	m_pChatBubble = new QLabel(m_pLeftSidebarBox);
	m_pChatBubble->setText("3");   // 用以测试， 随后删除
	m_pChatBubble->setGeometry(105, 96, 16, 16);
	m_pChatBubble->setAlignment(Qt::AlignCenter);
	m_pChatBubble->setStyleSheet("border-radius: 8px; opacity: 1; background: #DE5747; font-family: PingFangSC-Regular; font-size: 10px; font-weight: normal; line-height: 14px; letter-spacing: 0px; color: #FEFBFB;");

	// 左菜单栏
	m_pLeftMenuBar = new QGroupBox(this);
	m_pLeftMenuBar->setGeometry(20, 95, 65, 210);
	m_pLeftMenuBar->setStyleSheet("position: absolute; left: 20px; top: 95px; width: 65px; height: 210px; opacity: 1; spacing: 14px; border: none");

	// 通讯录
	m_pContactsBox = new QGroupBox(m_pLeftMenuBar);
	m_pContactsBox->setGeometry(0, 192, 65, 18);
	m_pContactsBox->setStyleSheet("border: none");
	m_pContactsText = new QLabel(m_pContactsBox);
	m_pContactsText->setText(tr("通讯录"));
	m_pContactsText->resize(39, 18);
	m_pContactsText->move(26, 0);
	m_pContactsText->setAlignment(Qt::AlignCenter);
	m_pContactsText->setStyleSheet("font-family: PingFangSC-Regular; font-size: 13px; font-weight: normal; line-height: 18px; letter-spacing: 0px; color: #3A3D43;");

	m_pContactsIcon = new QLabel(m_pContactsBox);
	m_pContactsIcon->setPixmap(QPixmap(":/main/image/Contactsicon.png"));
	m_pContactsIcon->resize(16, 16);
	m_pContactsIcon->move(0, 1);
	m_pContactsIcon->setStyleSheet("border: none;");

    // 工作台
	m_pWorkbenchBox = new QGroupBox(m_pLeftMenuBar);
	m_pWorkbenchBox->setGeometry(0, 160, 65, 18);
	m_pWorkbenchBox->setStyleSheet("border: none");

	m_pWorkbenchText = new QLabel(m_pWorkbenchBox);
    m_pWorkbenchText->setText(tr("工作台"));
	m_pWorkbenchText->setGeometry(26, 0, 39, 18);
	m_pContactsText->setAlignment(Qt::AlignCenter);
	m_pWorkbenchText->setStyleSheet("font-family: PingFangSC-Regular; font-size: 13px; font-weight: normal; line-height: 18px; letter-spacing: 0px; color: #3A3D43;");

	m_pWorkbenchIcon = new QLabel(m_pWorkbenchBox);
	m_pWorkbenchIcon->setPixmap(QPixmap(":/main/image/Union.png"));
	m_pWorkbenchIcon->resize(16, 16);
	m_pWorkbenchIcon->move(0, 1);
	m_pWorkbenchIcon->setStyleSheet("border: none;");

    // 会议
	m_pMeetingBox = new QGroupBox(m_pLeftMenuBar);
	m_pMeetingBox->setGeometry(0, 128, 65, 18);
	m_pMeetingBox->setStyleSheet("border: none");

    m_pMeetingText = new QLabel(m_pMeetingBox);
    m_pMeetingText->setText(tr("会议"));
    m_pMeetingText->setGeometry(26, 0, 26, 18);
    m_pContactsText->setAlignment(Qt::AlignCenter);
    m_pMeetingText->setStyleSheet("font-family: PingFangSC-Regular; font-size: 13px; font-weight: normal; line-height: 18px; letter-spacing: 0px; color: #3A3D43;");

    m_pMeetingIcon = new QLabel(m_pMeetingBox);
    m_pMeetingIcon->setPixmap(QPixmap(":/main/image/Meetingicon.png"));
    m_pMeetingIcon->resize(16, 16);
    m_pMeetingIcon->move(0, 1);
    m_pMeetingIcon->setStyleSheet("border: none;");

	// 日程
	m_pScheduleBox = new QGroupBox(m_pLeftMenuBar);
	m_pScheduleBox->setGeometry(0, 96, 65, 18);
	m_pScheduleBox->setStyleSheet("border: none");

	m_pScheduleText = new QLabel(m_pScheduleBox);
	m_pScheduleText->setText(tr("日程"));
	m_pScheduleText->setGeometry(26, 0, 26, 18);
	m_pContactsText->setAlignment(Qt::AlignCenter);
	m_pScheduleText->setStyleSheet("font-family: PingFangSC-Regular; font-size: 13px; font-weight: normal; line-height: 18px; letter-spacing: 0px; color: #3A3D43;");

	m_pScheduleIcon = new QLabel(m_pScheduleBox);
	m_pScheduleIcon->setPixmap(QPixmap(":/main/image/scheduleicon.png"));
	m_pScheduleIcon->resize(16, 16);
	m_pScheduleIcon->move(0, 1);
	m_pScheduleIcon->setStyleSheet("border: none;");

	// 文档
	m_pDocumentBox = new QGroupBox(m_pLeftMenuBar);
	m_pDocumentBox->setGeometry(0, 64, 65, 18);
	m_pDocumentBox->setStyleSheet("border: none");

	m_pDocumentText = new QLabel(m_pDocumentBox);
	m_pDocumentText->setText(tr("日程"));
	m_pDocumentText->setGeometry(26, 0, 26, 18);
	m_pContactsText->setAlignment(Qt::AlignCenter);
	m_pDocumentText->setStyleSheet("font-family: PingFangSC-Regular; font-size: 13px; font-weight: normal; line-height: 18px; letter-spacing: 0px; color: #3A3D43;");

	m_pDocumentIcon = new QLabel(m_pDocumentBox);
	m_pDocumentIcon->setPixmap(QPixmap(":/main/image/documenticon.png"));
	m_pDocumentIcon->resize(16, 16);
	m_pDocumentIcon->move(0, 1);
	m_pDocumentIcon->setStyleSheet("border: none;");

	// 邮件
	m_pEmailBox = new QGroupBox(m_pLeftMenuBar);
	m_pEmailBox->setGeometry(0, 32, 65, 18);
	m_pEmailBox->setStyleSheet("border: none");

	m_pEmailText = new QLabel(m_pEmailBox);
	m_pEmailText->setText(tr("邮件"));
	m_pEmailText->setGeometry(26, 0, 26, 18);
	m_pContactsText->setAlignment(Qt::AlignCenter);
	m_pEmailText->setStyleSheet("font-family: PingFangSC-Regular; font-size: 13px; font-weight: normal; line-height: 18px; letter-spacing: 0px; color: #3A3D43;");

	m_pEmailIcon = new QLabel(m_pEmailBox);
	m_pEmailIcon->setPixmap(QPixmap(":/main/image/emailicon.png"));
	m_pEmailIcon->resize(16, 16);
	m_pEmailIcon->move(0, 1);
	m_pEmailIcon->setStyleSheet("border: none;");

    // 消息
    m_pMessageBox = new QGroupBox(m_pLeftMenuBar);
    m_pMessageBox->setGeometry(0, 0, 65, 18);
    m_pMessageBox->setStyleSheet("border: none");

    m_pMessageText = new QLabel(m_pMessageBox);
    m_pMessageText->setText(tr("消息"));
    m_pMessageText->setGeometry(26, 0, 26, 18);
    m_pContactsText->setAlignment(Qt::AlignCenter);
    m_pMessageText->setStyleSheet("font-family: PingFangSC-Regular; font-size: 13px; font-weight: normal; line-height: 18px; letter-spacing: 0px; color: #3A3D43;");

    m_pMessageIcon = new QLabel(m_pMessageBox);
    m_pMessageIcon->setPixmap(QPixmap(":/main/image/messageicon.png"));
    m_pMessageIcon->resize(16, 16);
    m_pMessageIcon->move(0, 1);
    m_pMessageIcon->setStyleSheet("border: none;");

	// 选中背景
	m_pSelectBackground = new QGroupBox(this);
	m_pSelectBackground->setGeometry(12, 88, 120, 32);
	m_pSelectBackground->setStyleSheet("border-radius: 5px; opacity: 0.2; background-color: rgba(64, 124, 232, 0.2);");
	m_pSelectBackground->stackUnder(m_pLeftMenuBar);
}
void LeftBarWidget::ResizeWindows(int width, int height) {
	Q_UNUSED(width);
	this->resize(144, height);
	m_pLeftSidebarBox->setGeometry(0, 0, 144, this->height());
	m_pBottomComponentBox->setGeometry(20, m_pLeftSidebarBox->height() - 67, 78, 52);
}

