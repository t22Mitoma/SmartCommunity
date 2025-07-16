#include "wuyecheweichuzu.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QGridLayout>
#include <QHeaderView>
Wuyecheweichuzu::Wuyecheweichuzu(QWidget *parent) : QWidget(parent)
{
    // 设置窗口标题和大小
    setWindowTitle("车位出租管理");
    resize(800, 600);

    // 初始化UI控件
    tableView = new QTableView(this);
    numlineEdit = new QLineEdit(this);
    namelineEdit = new QLineEdit(this);
    IDlineEdit = new QLineEdit(this);
    selectpushButton = new QPushButton("查询未租赁车位", this);
    yespushButton = new QPushButton("确认租赁", this);
    model = new QSqlQueryModel(this);

    // 设置输入框提示文本
    numlineEdit->setPlaceholderText("请输入车位编号");
    namelineEdit->setPlaceholderText("请输入租户姓名");
    IDlineEdit->setPlaceholderText("请输入租户身份证号");

    // 构建布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // 1. 查询按钮区域
    mainLayout->addWidget(selectpushButton);

    // 2. 表格区域
    mainLayout->addWidget(tableView);

    // 3. 租赁信息输入区域（使用网格布局）
    QGroupBox *inputGroup = new QGroupBox("租赁信息", this);
    QGridLayout *inputLayout = new QGridLayout(inputGroup);
    inputLayout->addWidget(new QLabel("车位编号：", this), 0, 0);
    inputLayout->addWidget(numlineEdit, 0, 1);
    inputLayout->addWidget(new QLabel("租户姓名：", this), 1, 0);
    inputLayout->addWidget(namelineEdit, 1, 1);
    inputLayout->addWidget(new QLabel("身份证号：", this), 2, 0);
    inputLayout->addWidget(IDlineEdit, 2, 1);
    inputLayout->addWidget(yespushButton, 3, 0, 1, 2); // 确认按钮跨两列
    mainLayout->addWidget(inputGroup);

    // 设置表格属性
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); // 禁止编辑
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows); // 整行选中
    tableView->horizontalHeader()->setStretchLastSection(true); // 最后一列自适应

    // 连接信号槽
    connect(selectpushButton, &QPushButton::clicked, this, &Wuyecheweichuzu::on_selectpushButton_clicked);
    connect(yespushButton, &QPushButton::clicked, this, &Wuyecheweichuzu::on_yespushButton_clicked);
    connect(tableView, &QTableView::clicked, this, &Wuyecheweichuzu::on_tableView_clicked);

    // 初始化数据库
    initDatabase();
}

Wuyecheweichuzu::~Wuyecheweichuzu()
{
    delete model;
}


// 初始化数据库检查
void Wuyecheweichuzu::initDatabase()
{QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) return;

    if (!db.tables().contains("park", Qt::CaseInsensitive)) {
        QMessageBox::critical(this, "错误", "缺少park表，请检查数据库！");
    }
    if (!db.tables().contains("user", Qt::CaseInsensitive)) {
        QMessageBox::critical(this, "错误", "缺少user表，请检查数据库！");
    }
}

// 查询未租赁车位
void Wuyecheweichuzu::on_selectpushButton_clicked()
{
   QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) return;

    model->setQuery("SELECT number, addr, sellout, user_id FROM park WHERE sellout = '否'", db);

    if (model->lastError().isValid()) {
        QMessageBox::warning(this, "查询错误", model->lastError().text());
        return;
    }

    // 设置表格标题
    model->setHeaderData(0, Qt::Horizontal, "车位编号");
    model->setHeaderData(1, Qt::Horizontal, "车位地址");
    model->setHeaderData(2, Qt::Horizontal, "是否出租");
    model->setHeaderData(3, Qt::Horizontal, "租户ID");
    tableView->setModel(model);
    tableView->resizeColumnsToContents(); // 自适应列宽
}

// 确认租赁
void Wuyecheweichuzu::on_yespushButton_clicked()
{
    QString carNumber = numlineEdit->text().trimmed();
    QString tenantName = namelineEdit->text().trimmed();
    QString tenantID = IDlineEdit->text().trimmed();

    if (carNumber.isEmpty() || tenantName.isEmpty() || tenantID.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "请填写完整信息！");
        return;
    }

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) return;

    // 查询用户ID
    QSqlQuery userQuery(db);
    userQuery.prepare("SELECT id FROM user WHERE name = :name AND IDcard = :idcard");
    userQuery.bindValue(":name", tenantName);
    userQuery.bindValue(":idcard", tenantID);

    if (!userQuery.exec()) {
        QMessageBox::critical(this, "错误", userQuery.lastError().text());
        return;
    }

    if (!userQuery.next()) {
        QMessageBox::warning(this, "用户不存在", "未找到该用户，请先登记！");
        return;
    }

    int userId = userQuery.value(0).toInt();

    // 更新车位状态
    QSqlQuery parkQuery(db);
    parkQuery.prepare("UPDATE park SET sellout = '是', user_id = :user_id WHERE number = :number");
    parkQuery.bindValue(":user_id", userId);
    parkQuery.bindValue(":number", carNumber);

    if (!parkQuery.exec()) {
        QMessageBox::critical(this, "租赁失败", parkQuery.lastError().text());
        return;
    }

    QMessageBox::information(this, "成功", "车位【" + carNumber + "】租赁成功！");
    on_selectpushButton_clicked(); // 刷新表格
    numlineEdit->clear();
    namelineEdit->clear();
    IDlineEdit->clear();
}

// 表格选中事件（自动填充车位编号）
void Wuyecheweichuzu::on_tableView_clicked(const QModelIndex &index)
{
    if (index.isValid()) {
        QString number = model->data(model->index(index.row(), 0)).toString();
        numlineEdit->setText(number);
    }
}
