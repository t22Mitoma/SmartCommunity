#include "wuyerenyuanguanli.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

Wuyerenyuanguanli::Wuyerenyuanguanli(QWidget *parent)
    : QWidget(parent)
{
    // 初始化UI控件
    labelTitle = new QLabel("业主人员管理", this);
    labelName = new QLabel("姓名:", this);
    labelAge = new QLabel("年龄:", this);
    labelPhone = new QLabel("电话:", this);
    labelAddress = new QLabel("地址:", this);
    lineEditName = new QLineEdit(this);
    lineEditAge = new QLineEdit(this);
    lineEditPhone = new QLineEdit(this);
    lineEditAddress = new QLineEdit(this);
    pushButtonAdd = new QPushButton("添加", this);
    pushButtonDelete = new QPushButton("删除", this);
    pushButtonSearch = new QPushButton("搜索", this);
    tableWidget = new QTableWidget(this);

    // 设置表格列数
    tableWidget->setColumnCount(4);
    tableWidget->setHorizontalHeaderLabels({"姓名", "年龄", "电话", "地址"});

    // 布局管理
    QHBoxLayout *inputLayout = new QHBoxLayout;
    inputLayout->addWidget(labelName);
    inputLayout->addWidget(lineEditName);
    inputLayout->addWidget(labelAge);
    inputLayout->addWidget(lineEditAge);
    inputLayout->addWidget(labelPhone);
    inputLayout->addWidget(lineEditPhone);
    inputLayout->addWidget(labelAddress);
    inputLayout->addWidget(lineEditAddress);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(pushButtonAdd);
    buttonLayout->addWidget(pushButtonDelete);
    buttonLayout->addWidget(pushButtonSearch);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(labelTitle);
    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(tableWidget);

    setLayout(mainLayout);

    // 连接信号和槽
    connect(pushButtonAdd, &QPushButton::clicked, this, &Wuyerenyuanguanli::onAddButtonClicked);
    connect(pushButtonDelete, &QPushButton::clicked, this, &Wuyerenyuanguanli::onDeleteButtonClicked);
    connect(pushButtonSearch, &QPushButton::clicked, this, &Wuyerenyuanguanli::onSearchButtonClicked);


    // 创建表格（如果不存在）
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS owners ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "name TEXT, "
               "age INTEGER, "
               "phone TEXT, "
               "address TEXT)");
}

Wuyerenyuanguanli::~Wuyerenyuanguanli()
{
}

void Wuyerenyuanguanli::onAddButtonClicked()
{
    QString name = lineEditName->text();
    QString ageStr = lineEditAge->text();
    QString phone = lineEditPhone->text();
    QString address = lineEditAddress->text();

    if (name.isEmpty() || ageStr.isEmpty() || phone.isEmpty() || address.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "请填写所有信息");
        return;
    }

    int age = ageStr.toInt();

    QSqlQuery query;
    query.prepare("INSERT INTO owners (name, age, phone, address) VALUES (:name, :age, :phone, :address)");
    query.bindValue(":name", name);
    query.bindValue(":age", age);
    query.bindValue(":phone", phone);
    query.bindValue(":address", address);

    if (query.exec()) {
        QMessageBox::information(this, "成功", "添加业主信息成功");
        // 清空输入框
        lineEditName->clear();
        lineEditAge->clear();
        lineEditPhone->clear();
        lineEditAddress->clear();
    } else {
        QMessageBox::critical(this, "错误", "添加业主信息失败: " + query.lastError().text());
    }
}

void Wuyerenyuanguanli::onDeleteButtonClicked()
{
    int currentRow = tableWidget->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "选择错误", "请选择要删除的业主信息");
        return;
    }

    QString name = tableWidget->item(currentRow, 0)->text();

    QSqlQuery query;
    query.prepare("DELETE FROM owners WHERE name = :name");
    query.bindValue(":name", name);

    if (query.exec()) {
        QMessageBox::information(this, "成功", "删除业主信息成功");
        tableWidget->removeRow(currentRow);
    } else {
        QMessageBox::critical(this, "错误", "删除业主信息失败: " + query.lastError().text());
    }
}

void Wuyerenyuanguanli::onSearchButtonClicked()
{
    QString name = lineEditName->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM owners WHERE name = :name");
    query.bindValue(":name", name);

    if (query.exec()) {
        tableWidget->clearContents();
        tableWidget->setRowCount(0);

        int row = 0;
        while (query.next()) {
            tableWidget->insertRow(row);
            tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("name").toString()));
            tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("age").toString()));
            tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("phone").toString()));
            tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("address").toString()));
            row++;
        }
    } else {
        QMessageBox::critical(this, "错误", "搜索业主信息失败: " + query.lastError().text());
    }
}
