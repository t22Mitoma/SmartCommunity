#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adminlogin.h"
#include "worker_mainwindow.h"
#include "owner_mainwindow.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("智慧社区管理系统");
    this->setWindowIcon(QIcon(":/logo.png"));
    this->setFixedSize(1024,768); //固定主窗口
    ui->lineEdit->setFocus();
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit->setPlaceholderText("账号/手机号/身份证号码等");
    ui->lineEdit_2->setPlaceholderText("密码");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked(bool checked)//登录
{
        QSqlQuery query;
        if(query.exec("select * from usrlist"))
               {

                   while(query.next())//遍历数据表格

                   {

                        QString id= query.value(0).toString().trimmed();//trimmed函数表示去除QString两边的空格
                        QString tel= query.value(1).toString().trimmed();
                        QString IDcard =query.value(2).toString().trimmed();
                        QString password=query.value(3).toString().trimmed();
                        QString name=query.value(5).toString().trimmed();
                        int mark = query.value(4).toInt();

                        if((ui->lineEdit->text() == id)&&(ui->lineEdit_2->text() == password)&&(mark == 1)||(ui->lineEdit->text() == tel)&&(ui->lineEdit_2->text() == password)&&(mark == 1)||(ui->lineEdit->text() == IDcard)&&(ui->lineEdit_2->text() == password)&&(mark == 1)){

                            QMessageBox::information(this,tr("提示"),tr("尊贵的业主:%1  欢迎您！").arg(name),QMessageBox::Ok);
                            Owner_MainWindow *owner = new Owner_MainWindow;
                            owner->show();
                            this->close();
                            return;

                   }
                        if((ui->lineEdit->text() == id)&&(ui->lineEdit_2->text() == password)&&(mark == 2)||(ui->lineEdit->text() == tel)&&(ui->lineEdit_2->text() == password)&&(mark == 2)||(ui->lineEdit->text() == IDcard)&&(ui->lineEdit_2->text() == password)&&(mark == 2)){

                            QMessageBox::information(this,tr("提示"),tr("物业工作人员:%1  欢迎您！").arg(name),QMessageBox::Ok);
                            worker_MainWindow *worker = new worker_MainWindow;
                            worker->show();
                            this->close();
                            return;

                   }
                        if((ui->lineEdit->text() == id)&&(ui->lineEdit_2->text() == password)&&(mark == 0)||(ui->lineEdit->text() == tel)&&(ui->lineEdit_2->text() == password)&&(mark == 0)||(ui->lineEdit->text() == IDcard)&&(ui->lineEdit_2->text() == password)&&(mark == 0)){

                            QMessageBox::information(this,tr("提示"),tr("管理员%1，请您转至左下角管理员登录！").arg(name),QMessageBox::Ok);
                            ui->lineEdit->clear();
                            ui->lineEdit_2->clear();
                            ui->lineEdit->setFocus();
                            return;

                   }

               }
                       QMessageBox::warning(this, tr("登录失败"),
                                            tr("请输入正确的账号或密码！"), QMessageBox::Ok);
                       ui->lineEdit->clear();
                       ui->lineEdit_2->clear();
                       ui->lineEdit->setFocus();
}


}
void MainWindow::on_commandLinkButton_clicked(bool checked)//管理员登录
{
    adminlogin *admin = new adminlogin;
    admin->setWindowTitle("欢迎您！管理员");
    admin->setWindowIcon(QIcon(":/logo.png"));
    admin->show();
    this->hide();
}

void MainWindow::on_pushButton_2_clicked(bool checked)//关闭窗口
{
    ui->setupUi(this);
    this->close();
}


