#include "yezhucheweiguanli.h"

YeZhuCheWeiGuanLi::YeZhuCheWeiGuanLi(QWidget *parent)
    : QWidget(parent)
{
    // 1. 初始化数据库
    initDatabase();

    // 2. 初始化 UI 控件
    initUI();

    // 3. 绑定按钮事件
    bindEvents();
}

YeZhuCheWeiGuanLi::~YeZhuCheWeiGuanLi()
{

}

// 初始化数据库（创建表、连接数据库）
void YeZhuCheWeiGuanLi::initDatabase()
{
    // 4. 创建表（如果不存在）
    QSqlQuery query;
    // 表名：chewei_guanli，字段可根据需求扩展
    QString createTableSql = R"(
        CREATE TABLE IF NOT EXISTS chewei_guanli (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            chewei_id TEXT,         -- 车位 ID
            cheliang_info TEXT,     -- 车辆信息
            status INTEGER,         -- 状态（0：空闲；1：已申请；2：已承租）
            create_time DATETIME DEFAULT (datetime('now'))
        )
    )";

    if (!query.exec(createTableSql)) {
        QMessageBox::critical(this, "错误", "创建表失败：" + query.lastError().text());
    }
}

// 初始化 UI 控件
void YeZhuCheWeiGuanLi::initUI()
{
    // ======== 1. 创建控件 ========
    labelCheWeiID = new QLabel("车位 ID：", this);
    editCheWeiID = new QLineEdit(this);

    labelCheLiangInfo = new QLabel("车辆信息：", this);
    editCheLiangInfo = new QLineEdit(this);

    btnShenQing = new QPushButton("申请车位", this);
    btnChaXun = new QPushButton("查询车位", this);
    btnChengZu = new QPushButton("车位承租", this);
    btnWoDeCheWei = new QPushButton("我的车位", this);
    btnRuKu = new QPushButton("车辆入库识别", this);

    tableWidget = new QTableWidget(this);
    // 设置表格列数
    tableWidget->setColumnCount(5);
    // 设置表头
    tableWidget->setHorizontalHeaderLabels(QStringList()
        << "ID" << "车位 ID" << "车辆信息" << "状态" << "创建时间");
    // 自动调整列宽
    tableWidget->horizontalHeader()->setStretchLastSection(true);

    // ======== 2. 布局管理 ========
    // 水平布局：输入区域
    QHBoxLayout *inputLayout = new QHBoxLayout();
    inputLayout->addWidget(labelCheWeiID);
    inputLayout->addWidget(editCheWeiID);
    inputLayout->addWidget(labelCheLiangInfo);
    inputLayout->addWidget(editCheLiangInfo);

    // 水平布局：按钮区域
    QHBoxLayout *btnLayout = new QHBoxLayout();
    btnLayout->addWidget(btnShenQing);
    btnLayout->addWidget(btnChaXun);
    btnLayout->addWidget(btnChengZu);
    btnLayout->addWidget(btnWoDeCheWei);
    btnLayout->addWidget(btnRuKu);

    // 垂直布局：整体
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(btnLayout);
    mainLayout->addWidget(tableWidget);

    // 设置主布局
    setLayout(mainLayout);
    // 设置窗口标题
    setWindowTitle("业主车位管理");
    // 设置窗口大小
    resize(800, 600);
}

// 绑定按钮事件
void YeZhuCheWeiGuanLi::bindEvents()
{
    connect(btnShenQing, &QPushButton::clicked, this, &YeZhuCheWeiGuanLi::onBtnShenQingClicked);
    connect(btnChaXun, &QPushButton::clicked, this, &YeZhuCheWeiGuanLi::onBtnChaXunClicked);
    connect(btnChengZu, &QPushButton::clicked, this, &YeZhuCheWeiGuanLi::onBtnChengZuClicked);
    connect(btnWoDeCheWei, &QPushButton::clicked, this, &YeZhuCheWeiGuanLi::onBtnWoDeCheWeiClicked);
    connect(btnRuKu, &QPushButton::clicked, this, &YeZhuCheWeiGuanLi::onBtnRuKuClicked);
}

// ====================== 槽函数实现 ======================

// 申请车位
void YeZhuCheWeiGuanLi::onBtnShenQingClicked()
{
    QString cheWeiID = editCheWeiID->text().trimmed();
    QString cheLiangInfo = editCheLiangInfo->text().trimmed();

    // 简单校验
    if (cheWeiID.isEmpty() || cheLiangInfo.isEmpty()) {
        QMessageBox::warning(this, "提示", "车位 ID 和车辆信息不能为空！");
        return;
    }

    QSqlQuery query;
    // 插入数据（状态：1 表示“已申请”）
    query.prepare("INSERT INTO chewei_guanli (chewei_id, cheliang_info, status) VALUES (:chewei_id, :cheliang_info, 1)");
    query.bindValue(":chewei_id", cheWeiID);
    query.bindValue(":cheliang_info", cheLiangInfo);

    if (query.exec()) {
        QMessageBox::information(this, "成功", "车位申请提交成功！");
        // 清空输入框
        editCheWeiID->clear();
        editCheLiangInfo->clear();
    } else {
        QMessageBox::critical(this, "错误", "申请失败：" + query.lastError().text());
    }
}

// 查询车位
void YeZhuCheWeiGuanLi::onBtnChaXunClicked()
{
    QSqlQuery query;
    // 查询所有数据（可扩展条件查询）
    query.exec("SELECT id, chewei_id, cheliang_info, status, create_time FROM chewei_guanli");

    // 清空表格
    tableWidget->setRowCount(0);

    // 遍历结果集
    while (query.next()) {
        int row = tableWidget->rowCount();
        tableWidget->insertRow(row);

        // 读取字段
        int id = query.value(0).toInt();
        QString cheWeiID = query.value(1).toString();
        QString cheLiangInfo = query.value(2).toString();
        int status = query.value(3).toInt();
        QString createTime = query.value(4).toString();

        // 状态转换（0：空闲；1：已申请；2：已承租）
        QString statusText = status == 0 ? "空闲" : (status == 1 ? "已申请" : "已承租");

        // 设置表格数据
        tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(id)));
        tableWidget->setItem(row, 1, new QTableWidgetItem(cheWeiID));
        tableWidget->setItem(row, 2, new QTableWidgetItem(cheLiangInfo));
        tableWidget->setItem(row, 3, new QTableWidgetItem(statusText));
        tableWidget->setItem(row, 4, new QTableWidgetItem(createTime));
    }
}

// 车位承租
void YeZhuCheWeiGuanLi::onBtnChengZuClicked()
{
    QString cheWeiID = editCheWeiID->text().trimmed();
    if (cheWeiID.isEmpty()) {
        QMessageBox::warning(this, "提示", "请输入车位 ID！");
        return;
    }

    QSqlQuery query;
    // 更新状态为“已承租”（status=2）
    query.prepare("UPDATE chewei_guanli SET status = 2 WHERE chewei_id = :chewei_id");
    query.bindValue(":chewei_id", cheWeiID);

    if (query.exec()) {
        if (query.numRowsAffected() > 0) {
            QMessageBox::information(this, "成功", "车位承租操作完成！");
        } else {
            QMessageBox::warning(this, "提示", "未找到该车位或状态不允许承租！");
        }
    } else {
        QMessageBox::critical(this, "错误", "承租失败：" + query.lastError().text());
    }
}

// 我的车位（查询当前业主的车位，这里简单示例：查询状态=1 或 2 的车位）
void YeZhuCheWeiGuanLi::onBtnWoDeCheWeiClicked()
{
    QSqlQuery query;
    // 查询“已申请”或“已承租”的车位
    query.exec("SELECT id, chewei_id, cheliang_info, status, create_time FROM chewei_guanli WHERE status IN (1, 2)");

    // 清空表格
    tableWidget->setRowCount(0);

    // 遍历结果集
    while (query.next()) {
        int row = tableWidget->rowCount();
        tableWidget->insertRow(row);

        int id = query.value(0).toInt();
        QString cheWeiID = query.value(1).toString();
        QString cheLiangInfo = query.value(2).toString();
        int status = query.value(3).toInt();
        QString createTime = query.value(4).toString();

        QString statusText = status == 1 ? "已申请" : "已承租";

        tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(id)));
        tableWidget->setItem(row, 1, new QTableWidgetItem(cheWeiID));
        tableWidget->setItem(row, 2, new QTableWidgetItem(cheLiangInfo));
        tableWidget->setItem(row, 3, new QTableWidgetItem(statusText));
        tableWidget->setItem(row, 4, new QTableWidgetItem(createTime));
    }
}

// 车辆入库识别（简单示例：标记状态为“已使用”，实际可结合硬件逻辑）
void YeZhuCheWeiGuanLi::onBtnRuKuClicked()
{
    QString cheWeiID = editCheWeiID->text().trimmed();
    if (cheWeiID.isEmpty()) {
        QMessageBox::warning(this, "提示", "请输入车位 ID！");
        return;
    }

    QSqlQuery query;
    // 这里仅做演示，实际可根据需求更新状态
    query.prepare("UPDATE chewei_guanli SET status = 2 WHERE chewei_id = :chewei_id");
    query.bindValue(":chewei_id", cheWeiID);

    if (query.exec()) {
        if (query.numRowsAffected() > 0) {
            QMessageBox::information(this, "成功", "车辆入库识别完成！");
        } else {
            QMessageBox::warning(this, "提示", "未找到该车位或状态不允许入库！");
        }
    } else {
        QMessageBox::critical(this, "错误", "入库识别失败：" + query.lastError().text());
    }
}
