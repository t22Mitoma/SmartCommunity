#include "wuyeyueduchuqin.h"
#include "ui_wuyeyueduchuqin.h"
#include <qdebug.h>
#include <QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QMessageBox>

Wuyeyueduchuqin::Wuyeyueduchuqin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wuyeyueduchuqin)
{
    ui->setupUi(this);

    // --- 数据库连接部分 (建议在main.cpp中全局设置一次) ---
    // 为了兼容你原来的代码，我们先这样写，但稍作优化防止重复连

    // --- 以下是新的核心代码 ---

    // 1. 实例化模型
    model = new QSqlQueryModel(this);

    // 2. 设置查询语句，直接从"book"表获取数据
    QSqlDatabase db = QSqlDatabase::database();
    model->setQuery("SELECT * FROM book", db);

    // 3. 检查查询是否出错
    if (model->lastError().isValid()) {
        QMessageBox::critical(this, tr("数据库查询失败"), model->lastError().text());
        return;
    }

    // 4. 设置表格标题（将显示在Table View的顶部）
    model->setHeaderData(0, Qt::Horizontal, tr("姓名"));
    model->setHeaderData(1, Qt::Horizontal, tr("上班时间"));
    model->setHeaderData(2, Qt::Horizontal, tr("下班时间"));
    model->setHeaderData(3, Qt::Horizontal, tr("日期"));

    // 5. 将UI中的tableView和我们的模型关联起来
    ui->tableView->setModel(model);

    // 6. (可选，但推荐) 调整表格样式，使其更好看
    ui->tableView->resizeColumnsToContents(); // 列宽根据内容自适应
    ui->tableView->setAlternatingRowColors(true); // 隔行变色
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows); // 设置为整行选择
    ui->tableView->horizontalHeader()->setStretchLastSection(true); // 最后一列自动拉伸充满
}

Wuyeyueduchuqin::~Wuyeyueduchuqin()
{
    delete ui;
}

// 整个 on_pushButton1_clicked() 函数已经被删除，因为不再需要了。
