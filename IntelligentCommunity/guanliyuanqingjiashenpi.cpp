#include "guanliyuanqingjiashenpi.h"

guanliyuanqingjiashenpi::guanliyuanqingjiashenpi(QWidget *parent)
    : QWidget(parent)
{
    // 初始化表格模型
    model = new QSqlTableModel(this, QSqlDatabase::database("adminConnection"));
    model->setTable("leave_records");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setFilter("approved = '未审批'"); // 只显示未审批的记录
    model->select();

    // 设置表头
    model->setHeaderData(0, Qt::Horizontal, "记录ID");
    model->setHeaderData(1, Qt::Horizontal, "姓名");
    model->setHeaderData(2, Qt::Horizontal, "开始日期");
    model->setHeaderData(3, Qt::Horizontal, "结束日期");
    model->setHeaderData(4, Qt::Horizontal, "销假状态");
    model->setHeaderData(5, Qt::Horizontal, "审批状态");

    // 创建表格视图
    leaveTableView = new QTableView(this);
    leaveTableView->setModel(model);
    leaveTableView->setColumnHidden(0, true); // 隐藏ID列
    leaveTableView->resizeColumnsToContents();

    // 创建按钮
    approveButton = new QPushButton("已审批", this);
    rejectButton = new QPushButton("驳回", this);
    refreshButton = new QPushButton("刷新", this);

    // 连接按钮信号到槽函数
    connect(approveButton, &QPushButton::clicked, this, &guanliyuanqingjiashenpi::approveSelectedLeave);
    connect(rejectButton, &QPushButton::clicked, this, &guanliyuanqingjiashenpi::rejectSelectedLeave);
    connect(refreshButton, &QPushButton::clicked, this, &guanliyuanqingjiashenpi::refreshTable);

    // 创建布局
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(approveButton);
    buttonLayout->addWidget(rejectButton);
    buttonLayout->addWidget(refreshButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(leaveTableView);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);
    setWindowTitle("管理员请假审批");
}

guanliyuanqingjiashenpi::~guanliyuanqingjiashenpi()
{
}

void guanliyuanqingjiashenpi::approveSelectedLeave()
{
    QModelIndexList selectedRows = leaveTableView->selectionModel()->selectedRows();

    if (selectedRows.isEmpty()) {
        QMessageBox::information(this, "提示", "请先选择要审批的记录");
        return;
    }

    for (const auto& index : selectedRows) {
        int row = index.row();
        model->setData(model->index(row, 5), "已审批"); // 更新审批状态
    }

    if (model->submitAll()) {
        QMessageBox::information(this, "成功", "审批状态已更新");
        refreshTable();
    } else {
        QMessageBox::critical(this, "错误", "更新审批状态失败: " + model->lastError().text());
    }
}

void guanliyuanqingjiashenpi::rejectSelectedLeave()
{
    QModelIndexList selectedRows = leaveTableView->selectionModel()->selectedRows();

    if (selectedRows.isEmpty()) {
        QMessageBox::information(this, "提示", "请先选择要驳回的记录");
        return;
    }

    for (const auto& index : selectedRows) {
        int row = index.row();
        model->setData(model->index(row, 5), "驳回"); // 更新审批状态
    }

    if (model->submitAll()) {
        QMessageBox::information(this, "成功", "驳回状态已更新");
        refreshTable();
    } else {
        QMessageBox::critical(this, "错误", "更新驳回状态失败: " + model->lastError().text());
    }
}

void guanliyuanqingjiashenpi::refreshTable()
{
    model->select();
}
