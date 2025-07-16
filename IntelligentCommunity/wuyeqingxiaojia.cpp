#include "wuyeqingxiaojia.h"
#include "ui_wuyeqingxiaojia.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDate>
#include <QSqlRecord>
Wuyeqingxiaojia::~Wuyeqingxiaojia()
{
    delete ui;
    delete model;
}
Wuyeqingxiaojia::Wuyeqingxiaojia(QWidget *parent)
    : QWidget(parent), ui(new Ui::Wuyeqingxiaojia)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::critical(this, "错误", "数据库未打开，无法使用请销假功能！");
       this->setEnabled(false);
        return;
    }
    model = new QSqlTableModel(this, db);
    model->setTable("leave_records");
    model->select();
}

// 请假（新增记录）
void Wuyeqingxiaojia::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text().trimmed();
    QString startDate = ui->lineEdit_2->text().trimmed();
    QString endDate = ui->lineEdit_4->text().trimmed();

    if (name.isEmpty() || startDate.isEmpty()) {
        QMessageBox::warning(this, "提示", "姓名和开始日期不能为空！");
        return;
    }

    QSqlRecord record = model->record();
    // 在插入记录后添加
    record.setValue("name", name);
    record.setValue("start_date", startDate);
    record.setValue("end_date", endDate.isEmpty() ? QVariant(QVariant::String) : endDate);
    record.setValue("status", "未销假");
    record.setValue("approved", "未审批");

    if (!model->insertRecord(-1, record)) {
        QMessageBox::critical(this, "数据库错误", model->lastError().text());
    } else {
        QMessageBox::information(this, "成功", "请假记录已保存！");
        model->select();
    }
}

// 原退出按钮
void Wuyeqingxiaojia::on_pushButton_2_clicked()
{
    if (QMessageBox::question(this, "确认", "确定要退出吗？",
                              QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
        close();
    }
}

// 一键销假
void Wuyeqingxiaojia::on_pushButton_3_clicked()
{
    QString name = ui->lineEdit->text().trimmed();
    if (name.isEmpty()) {
        QMessageBox::warning(this, "提示", "请输入要销假的人名！");
        return;
    }

    QString today = QDate::currentDate().toString("yyyy-MM-dd");

    model->setFilter(QString("name = '%1' AND status = '未销假'").arg(name));
    model->select();

    if (model->rowCount() == 0) {
        QMessageBox::information(this, "提示", QString("“%1”没有未销假记录！").arg(name));
        return;
    }

    QSqlRecord record = model->record(0);
    record.setValue("end_date", today);
    record.setValue("status", "已销假");
    if (!model->setRecord(0, record)) {
        QMessageBox::critical(this, "数据库错误", model->lastError().text());
    } else {
        QMessageBox::information(this, "成功", QString("“%1”已于今日销假！").arg(name));
        model->setFilter("");
        model->select();
    }
}

// 查询审批情况
void Wuyeqingxiaojia::on_pushButton_4_clicked()
{
    QString name = ui->lineEdit->text().trimmed();
    QString filter = name.isEmpty() ? "" : QString("name = '%1'").arg(name);

    model->setFilter(filter);
    model->select();

    QString resultText = "审批结果：\n\n";
    bool hasRecords = false;

    for (int i = 0; i < model->rowCount(); ++i) {
        hasRecords = true;
        QSqlRecord record = model->record(i);
        QString recName = record.value("name").toString();
        QString startDate = record.value("start_date").toString();
        QString endDate = record.value("end_date").toString();
        QString status = record.value("status").toString();
        QString approved = record.value("approved").toString();

        resultText += QString("姓名：%1\n开始日期：%2\n结束日期：%3\n销假状态：%4\n审批状态：%5\n\n")
                      .arg(recName, startDate, endDate.isEmpty() ? "未填写" : endDate, status, approved);
    }

    if (!hasRecords) {
        resultText += "未找到匹配的记录！";
    }

    QMessageBox::information(this, "审批结果", resultText);
}
