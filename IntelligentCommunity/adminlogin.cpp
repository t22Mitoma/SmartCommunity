#include "adminlogin.h"
#include "ui_adminlogin.h"
#include "mainwindow.h"
#include "admin_mainwindow.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QLineEdit>
#include<QDebug>
#include<QSqlError>

adminlogin::adminlogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminlogin)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit->setPlaceholderText("账号/手机号/身份证号码等");
    ui->lineEdit_2->setPlaceholderText("密码");
}

adminlogin::~adminlogin()
{
    delete ui;
}

void adminlogin::on_pushButton_clicked()
{
    // 添加输入验证
    if (ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty()) {
        QMessageBox::warning(this, "提示", "请输入账号和密码", QMessageBox::Ok);
        return;
    }

    QSqlQuery query;
    if(query.exec("select * from usrlist"))
    {
        bool found = false;
        QString adminName;

        while(query.next())
        {
            QString id = query.value(0).toString().trimmed();
            QString tel = query.value(1).toString().trimmed();
            QString IDcard = query.value(2).toString().trimmed();
            QString password = query.value(3).toString().trimmed();
            QString name = query.value(5).toString().trimmed();
            int mark = query.value(4).toInt();

            if((ui->lineEdit->text() == id || ui->lineEdit->text() == tel || ui->lineEdit->text() == IDcard) &&
               ui->lineEdit_2->text() == password && mark == 0)
            {
                found = true;
                adminName = name;
                break;
            }
        }

        if (found) {
            // 临时移除tr()函数调用进行测试
            QMessageBox::information(this, "提示", QString("管理员:%1  欢迎您！").arg(adminName), QMessageBox::Ok);

            try {
                admin_MainWindow *admin = new admin_MainWindow;
                admin->show();
                this->close();
            } catch (const std::exception& e) {
                qDebug() << "创建管理员窗口时出错:" << e.what();
                QMessageBox::critical(this, "错误", "无法打开管理员窗口", QMessageBox::Ok);
            }
        } else {
            QMessageBox::warning(this, "登录失败", "请输入正确的账号或密码！", QMessageBox::Ok);
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit->setFocus();
        }
    }
    else
    {
        QMessageBox::critical(this, "数据库错误", query.lastError().text(), QMessageBox::Ok);
    }
}
void adminlogin::on_pushButton_2_clicked()
{

}

void adminlogin::on_commandLinkButton_clicked()
{
    MainWindow *w = new MainWindow;
    w->show();
    this->close();
}

void adminlogin::on_lineEdit_2_cursorPositionChanged(int arg1, int arg2)
{

}
