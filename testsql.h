//
// Created by 23776 on 2023/8/13.
//

#include <QtSql>
#include <QObject>
#include <time.h>
int test() {
	QString aFile = "C:\\Users\\23776\\OneDrive - stu.fosu.edu.cn\\QtCode\\CallTerminal\\Debug\\DACS_DIR\\log\\logdb.db";
	QSqlDatabase DB;
    DB = QSqlDatabase::addDatabase("QSQLITE");
	DB.setDatabaseName(aFile);
	if (!DB.open()) {
		qDebug() << "error open";
	}
	else {
		qDebug() << "success open";
	}
    qDebug() << time(NULL) ;
	return 0;
}
