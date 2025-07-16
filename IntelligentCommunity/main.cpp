#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QSqlDatabase>
#include <QMessageBox>
#include "mainwindow.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // ✅ 加载样式表（你原来就有的）
    QFile qssFile(":/style.qss");
    if (qssFile.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "Qss file opened successfully.";
        QString style = QLatin1String(qssFile.readAll());
        a.setStyleSheet(style);
        qssFile.close();
    } else {
        qDebug() << "Failed to open Qss file!";
    }

    // ✅ 只建立一次数据库连接
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/dell/Desktop/V1.1-beta1/V1.1/build-IntelligentCommunity-Desktop_Qt_5_8_0_MinGW_32bit-Release/release/usrlist.db");

    if (!db.open()) {
        QMessageBox::critical(nullptr, "数据库错误", "无法打开数据库：" + db.lastError().text());

        return -1;
    }
    qDebug() << "实际使用的数据库路径：" << db.databaseName();
    // ✅ 启动主窗口
    MainWindow w;
    w.show();
    return a.exec();
}
