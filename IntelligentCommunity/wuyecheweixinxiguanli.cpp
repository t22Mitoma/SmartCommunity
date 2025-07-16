#include "wuyecheweixinxiguanli.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QGridLayout>
#include <QButtonGroup>
#include <QHeaderView>
#include "ui_yezhucheweiguanli.h" // 替换成实际的 UI 头文件名
Wuyecheweixinxiguanli::Wuyecheweixinxiguanli(QWidget *parent) : QWidget(parent)
{
    // 设置窗口标题和大小
    setWindowTitle("车位信息管理");
    resize(800, 600);

    // 初始化UI控件
    tableView = new QTableView(this);
    numEdit = new QLineEdit(this);
    addrEdit = new QLineEdit(this);
    yradioButton = new QRadioButton("已售出", this);
    nradioButton = new QRadioButton("未售出", this);
    useridEdit = new QLineEdit(this);
    addButton = new QPushButton("添加车位", this);
    modifyButton = new QPushButton("修改车位", this);
    queryButton = new QPushButton("查询车位", this);
    model = new QSqlQueryModel(this);

    // 设置输入框提示文本
    numEdit->setPlaceholderText("请输入车位编号");
    addrEdit->setPlaceholderText("请输入车位地址");
    useridEdit->setPlaceholderText("请输入购买人ID");
    nradioButton->setChecked(true); // 默认未售出

    // 单选按钮分组（互斥）
    QButtonGroup *statusGroup = new QButtonGroup(this);
    statusGroup->addButton(yradioButton, 1);
    statusGroup->addButton(nradioButton, 0);

    // 构建布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // 1. 操作按钮区域（添加/修改/查询）
    QHBoxLayout *btnLayout = new QHBoxLayout();
    btnLayout->addWidget(addButton);
    btnLayout->addWidget(modifyButton);
    btnLayout->addWidget(queryButton);
    mainLayout->addLayout(btnLayout);

    // 2. 表格区域
    mainLayout->addWidget(tableView);

    // 3. 车位信息输入区域（网格布局）
    QGroupBox *inputGroup = new QGroupBox("车位信息", this);
    QGridLayout *inputLayout = new QGridLayout(inputGroup);
    inputLayout->addWidget(new QLabel("车位编号：", this), 0, 0);
    inputLayout->addWidget(numEdit, 0, 1);
    inputLayout->addWidget(new QLabel("车位地址：", this), 1, 0);
    inputLayout->addWidget(addrEdit, 1, 1);
    inputLayout->addWidget(new QLabel("状态：", this), 2, 0);
    QHBoxLayout *statusLayout = new QHBoxLayout();
    statusLayout->addWidget(yradioButton);
    statusLayout->addWidget(nradioButton);
    inputLayout->addLayout(statusLayout, 2, 1);
    inputLayout->addWidget(new QLabel("购买人ID：", this), 3, 0);
    inputLayout->addWidget(useridEdit, 3, 1);
    mainLayout->addWidget(inputGroup);

    // 设置表格属性
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->horizontalHeader()->setStretchLastSection(true);

    // 连接信号槽
    connect(addButton, &QPushButton::clicked, this, &Wuyecheweixinxiguanli::on_addButton_clicked);
    connect(modifyButton, &QPushButton::clicked, this, &Wuyecheweixinxiguanli::on_modifyButton_clicked);
    connect(queryButton, &QPushButton::clicked, this, &Wuyecheweixinxiguanli::on_queryButton_clicked);
    connect(tableView, &QTableView::clicked, this, &Wuyecheweixinxiguanli::on_tableView_clicked);

    // 初始化加载数据
    refreshTableView();
}

Wuyecheweixinxiguanli::~Wuyecheweixinxiguanli()
{
    delete model;
}

// 刷新表格
void Wuyecheweixinxiguanli::refreshTableView(const QString &sql)
{
   QSqlDatabase db = QSqlDatabase::database(); // 使用默认连接
    if (!db.isOpen()) return;

    model->setQuery(sql, db);

    if (model->lastError().isValid()) {
        QMessageBox::warning(this, "查询错误", model->lastError().text());
        return;
    }

    // 设置表格标题
    model->setHeaderData(0, Qt::Horizontal, "车位编号");
    model->setHeaderData(1, Qt::Horizontal, "车位地址");
    model->setHeaderData(2, Qt::Horizontal, "是否售出");
    model->setHeaderData(3, Qt::Horizontal, "购买人账号");

    // 绑定模型到 tableview
    tableView->setModel(model);
    // 自动调整列宽
    tableView->resizeColumnsToContents();

    qDebug() << "刷新表格成功，行数：" << model->rowCount();
}

// 添加车位按钮逻辑
void Wuyecheweixinxiguanli::on_addButton_clicked()
{
    QString number = numEdit->text().trimmed();
    QString address = addrEdit->text().trimmed();
    QString status = yradioButton->isChecked() ? "是" : "否";
    QString buyerId = useridEdit->text().trimmed();

    // 输入校验
    if (number.isEmpty() || address.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "请填写车位编号和地址！");
        return;
    }

   QSqlDatabase db = QSqlDatabase::database(); // 使用默认连接
    if (!db.isOpen()) return;

    // 检查车位是否已存在
    QSqlQuery checkQuery(db);
    checkQuery.prepare("SELECT COUNT(*) FROM park WHERE number = :number");
    checkQuery.bindValue(":number", number);

    if (!checkQuery.exec() || !checkQuery.next()) {
        QMessageBox::critical(this, "查询错误", "检查车位是否存在失败！");
        return;
    }

    if (checkQuery.value(0).toInt() > 0) {
        QMessageBox::warning(this, "添加失败", "该车位编号已存在！");
        return;
    }
    // 插入新车位
    QSqlQuery insertQuery(db);
    insertQuery.prepare("INSERT INTO park (number, addr, sellout, user_id) "
                        "VALUES (:number, :addr, :sellout, :user_id)");
    insertQuery.bindValue(":number", number);
    insertQuery.bindValue(":addr", address);
    insertQuery.bindValue(":sellout", status);
    insertQuery.bindValue(":user_id", buyerId.isEmpty() ? QVariant(QVariant::Int) : buyerId);

    if (!insertQuery.exec()) {
        QMessageBox::critical(this, "添加失败",
                             "SQL 执行错误：" + insertQuery.lastError().text());
        return;
    }

    QMessageBox::information(this, "添加成功", "车位添加成功！");
    refreshTableView();
    numEdit->clear();
    addrEdit->clear();
    useridEdit->clear();
    nradioButton->setChecked(true); // 重置状态为未售出
}

// 修改车位按钮逻辑
void Wuyecheweixinxiguanli::on_modifyButton_clicked()
{
    QString number = numEdit->text().trimmed();
    QString address = addrEdit->text().trimmed();
    QString status = yradioButton->isChecked() ? "是" : "否";
    QString buyerId = useridEdit->text().trimmed();

    // 输入校验
    if (number.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "请选择要修改的车位！");
        return;
    }

    QSqlDatabase db = QSqlDatabase::database(); // 使用默认连接
    if (!db.isOpen()) return;

    // 更新车位信息
    QSqlQuery updateQuery(db);
    updateQuery.prepare("UPDATE park "
                        "SET addr = :addr, sellout = :sellout, user_id = :user_id "
                        "WHERE number = :number");
    updateQuery.bindValue(":addr", address);
    updateQuery.bindValue(":sellout", status);
    updateQuery.bindValue(":user_id", buyerId.isEmpty() ? QVariant(QVariant::Int) : buyerId);
    updateQuery.bindValue(":number", number);

    if (!updateQuery.exec()) {
        QMessageBox::critical(this, "修改失败",
                             "SQL 执行错误：" + updateQuery.lastError().text());
        return;
    }

    if (updateQuery.numRowsAffected() == 0) {
        QMessageBox::warning(this, "修改失败", "未找到指定的车位！");
        return;
    }

    QMessageBox::information(this, "修改成功", "车位信息已更新！");
    refreshTableView();
}

// 查询车位按钮逻辑
void Wuyecheweixinxiguanli::on_queryButton_clicked()
{
    QString keyword = numEdit->text().trimmed();  // 使用车位编号输入框作为查询条件

    if (keyword.isEmpty()) {
        refreshTableView(); // 查询条件为空时显示全部
        return;
    }

    QString sql = "SELECT * FROM park WHERE number LIKE '%" + keyword + "%' "
                 "OR addr LIKE '%" + keyword + "%'";

    refreshTableView(sql);
}

// 表格点击事件（自动填充表单）
void Wuyecheweixinxiguanli::on_tableView_clicked(const QModelIndex &index)
{
    if (!index.isValid()) return;

    // 获取选中行的数据
    QString number = model->data(model->index(index.row(), 0)).toString();
    QString address = model->data(model->index(index.row(), 1)).toString();
    QString status = model->data(model->index(index.row(), 2)).toString();
    QString buyerId = model->data(model->index(index.row(), 3)).toString();

    // 填充表单
    numEdit->setText(number);
    addrEdit->setText(address);
    yradioButton->setChecked(status == "是");
    nradioButton->setChecked(status == "否");
    useridEdit->setText(buyerId);
}
