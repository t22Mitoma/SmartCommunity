#include "yezhuguzhuangbaoxiu.h"
#include "ui_yezhuguzhuangbaoxiu.h"
#include <QMessageBox>
#include <QDateTime>
#include <QSqlError>
#include <QDebug>
Yezhuguzhuangbaoxiu::Yezhuguzhuangbaoxiu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Yezhuguzhuangbaoxiu)
{
    ui->setupUi(this);
    // 初始化数据库连接
    if (!initDatabase()) {
        QMessageBox::critical(this, "数据库错误", "无法连接到数据库，请检查路径！");
        this->setEnabled(false); // 连接失败则禁用窗口
    }
}

Yezhuguzhuangbaoxiu::~Yezhuguzhuangbaoxiu()
{
    if (db.isOpen()) {
    }
    delete ui;
}

// 数据库初始化（直接嵌入，无需通用文件）
bool Yezhuguzhuangbaoxiu::initDatabase()
{
    // 检查是否已存在相同连接名
    QSqlDatabase db = QSqlDatabase::database(); // 使用默认连接
    if (!db.isOpen()) {
        QMessageBox::critical(this, "错误", "数据库未连接！");
        return false;
    }
    // 尝试打开数据库
    if (!db.open()) {
        qDebug() << "数据库打开失败：" << db.lastError().text();
        return false;
    }
    // 检查yezhu表是否存在，不存在则创建（避免手动建表）
    QSqlQuery query(db);
    QString createTableSql = R"(CREATE TABLE IF NOT EXISTS yezhupingjia ("id" INTEGER PRIMARY KEY AUTOINCREMENT,
                            "owner_name TEXT NOT NULL, "
                            "phone TEXT NOT NULL, "
                            "address TEXT NOT NULL, "
                            "problem_desc TEXT NOT NULL, "

                             "warranty_status" TEXT,
                             "repair_status" TEXT,
                             "evaluation" TEXT,
                             "request_time" TEXT NOT NULL
                                                      );)";

    if (!query.exec(createTableSql)) {
        qDebug() << "创建表失败：" << query.lastError().text();
        return false;
    }
    return true;
}

// 提交按钮点击事件（核心逻辑）
void Yezhuguzhuangbaoxiu::on_pushButton_2_clicked()
{
    // 获取表单数据
    QString name = ui->lineEdit->text().trimmed();       // 姓名（对应label_2）
    QString phone = ui->lineEdit_2->text().trimmed();    // 电话（对应label_3）
    QString address = ui->lineEdit_3->text().trimmed();  // 地址（对应label_4）
    QString problem = ui->textEdit->toPlainText().trimmed(); // 问题描述（对应label_5）

    // 数据验证
    if (name.isEmpty() || phone.isEmpty() || address.isEmpty() || problem.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "请填写完整信息！");
        return;
    }

    // 插入数据到数据库
    QSqlQuery query(db);
    query.prepare(R"(
        INSERT INTO yezhupingjia
        (owner_name, phone, address, problem_desc)
        VALUES
        (:owner_name, :phone, :address, :problem_desc)
    )");
    query.bindValue(":owner_name", name);         // 对应界面输入的业主姓名
    query.bindValue(":phone", phone);             // 对应界面输入的电话
    query.bindValue(":address", address);         // 对应界面输入的地址
    query.bindValue(":problem_desc", problem);    // 对应界面输入的问题描述

    if (query.exec()) {
        QMessageBox::information(this, "提交成功", "报修信息已提交，工作人员将尽快处理！");
        // 清空表单（可选）
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->textEdit->clear();


    } else {
        QMessageBox::critical(this, "提交失败", "数据库错误：" + query.lastError().text());
    }
}
