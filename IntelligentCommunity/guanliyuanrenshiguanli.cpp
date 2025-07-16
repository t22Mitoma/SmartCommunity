#include "guanliyuanrenshiguanli.h"
#include "ui_guanliyuanrenshiguanli.h"
#include <qdebug.h>
#include <QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QMessageBox>

Guanliyuanrenshiguanli::Guanliyuanrenshiguanli(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)  // 修正UI类名，与.ui文件匹配
{
    ui->setupUi(this);
}

Guanliyuanrenshiguanli::~Guanliyuanrenshiguanli()
{

    delete ui;
}

// 查询按钮点击事件
void Guanliyuanrenshiguanli::on_pushButton_clicked()
{
    QString searchid = ui->lineEdit_6->text().trimmed();

    if (searchid.isEmpty()) {
        QMessageBox::information(this, tr("提示"), tr("请输入需要查询的管理员ID！"));
        return;
    }
QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);  // 使用类成员db
    QString str = QString("select * from wuyerengshiguanli where id = '%1'").arg(searchid);

    if (!query.exec(str)) {
        QMessageBox::critical(this, tr("查询失败"),
            tr("查询数据库时出错！\n错误信息：%1").arg(query.lastError().text()));
        return;
    }

    QString id, tel, IDcard, pwd, mark;
    bool hasRecord = false;

    while (query.next()) {
        hasRecord = true;
        id = query.value(0).toString();
        tel = query.value(1).toString();
        IDcard = query.value(2).toString();
        pwd = query.value(3).toString();
        mark = query.value(4).toString();
    }

    if (!hasRecord) {
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
        ui->lineEdit_6->clear();
        QMessageBox::information(this, tr("提示"), tr("未找到ID为%1的记录，请重新输入！").arg(searchid));
    } else {
        ui->lineEdit->setText(id);
        ui->lineEdit_2->setText(tel);
        ui->lineEdit_3->setText(IDcard);
        ui->lineEdit_4->setText(pwd);
        ui->lineEdit_5->setText(mark);
        ui->lineEdit_6->clear();
    }
}

// 修改按钮点击事件
void Guanliyuanrenshiguanli::on_pushButton_2_clicked()
{
    QString updateid = ui->lineEdit->text().trimmed();
    QString updatetel = ui->lineEdit_2->text().trimmed();
    QString updateIDcard = ui->lineEdit_3->text().trimmed();
    QString updatepwd = ui->lineEdit_4->text().trimmed();
    QString updatemark = ui->lineEdit_5->text().trimmed();

    if (updateid.isEmpty()) {
        QMessageBox::information(this, tr("提示"), tr("请输入需要修改的管理员ID！"));
        return;
    }
QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);  // 使用类成员db
    QString checkStr = QString("select * from wuyerengshiguanli where id = '%1'").arg(updateid);

    if (!query.exec(checkStr)) {
        QMessageBox::critical(this, tr("查询失败"),
            tr("验证记录时出错！\n错误信息：%1").arg(query.lastError().text()));
        return;
    }

    if (!query.next()) {
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
        QMessageBox::information(this, tr("提示"), tr("未找到ID为%1的记录，修改失败！").arg(updateid));
        return;
    }

    QString updateStr = QString("update usrlist set tel = '%1', IDcard = '%2', pwd = '%3', mark = '%4' where id = '%5'")
                        .arg(updatetel).arg(updateIDcard).arg(updatepwd).arg(updatemark).arg(updateid);

    if (!query.exec(updateStr)) {
        QMessageBox::critical(this, tr("修改失败"),
            tr("更新记录时出错！\n错误信息：%1").arg(query.lastError().text()));
        return;
    }

    QMessageBox::information(this, tr("成功"), tr("信息修改成功！"));
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
}

// 新增按钮点击事件
void Guanliyuanrenshiguanli::on_pushButton_3_clicked()
{
    QString userid = ui->lineEdit->text().trimmed();
    QString tel = ui->lineEdit_2->text().trimmed();
    QString IDcard = ui->lineEdit_3->text().trimmed();
    QString pwd = ui->lineEdit_4->text().trimmed();
    QString mark = ui->lineEdit_5->text().trimmed();

    if (userid.isEmpty() || tel.isEmpty() || IDcard.isEmpty() || pwd.isEmpty() || mark.isEmpty()) {
        QMessageBox::information(this, tr("提示"), tr("信息写入失败！请输入完整的信息！"));
        return;
    }
QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);  // 使用类成员db
    QString insertStr = QString("insert into wuyerengshiguanli (id, tel, IDcard, pwd, mark) values('%1', '%2', '%3', '%4', '%5')")
                        .arg(userid).arg(tel).arg(IDcard).arg(pwd).arg(mark);

    if (!query.exec(insertStr)) {
        QMessageBox::critical(this, tr("新增失败"),
            tr("插入记录时出错！\n错误信息：%1").arg(query.lastError().text()));
        return;
    }

    QMessageBox::information(this, tr("成功"), tr("信息写入成功！"));
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
}

// 删除按钮点击事件
void Guanliyuanrenshiguanli::on_pushButton_4_clicked()
{
    QString id = ui->lineEdit->text().trimmed();

    if (id.isEmpty()) {
        QMessageBox::information(this, tr("提示"), tr("请输入需要删除的管理员ID！"));
        return;
    }
QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);  // 使用类成员db
    QString checkStr = QString("select * from wuyerengshiguanli where id = '%1'").arg(id);

    if (!query.exec(checkStr)) {
        QMessageBox::critical(this, tr("查询失败"),
            tr("验证记录时出错！\n错误信息：%1").arg(query.lastError().text()));
        return;
    }

    if (!query.next()) {
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
        QMessageBox::information(this, tr("提示"), tr("未找到ID为%1的记录，删除失败！").arg(id));
        return;
    }

    QString deleteStr = QString("delete from wuyerengshiguanli where id = '%1'").arg(id);

    if (!query.exec(deleteStr)) {
        QMessageBox::critical(this, tr("删除失败"),
            tr("删除记录时出错！\n错误信息：%1").arg(query.lastError().text()));
        return;
    }

    QMessageBox::information(this, tr("成功"), tr("信息删除成功！"));
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
}
