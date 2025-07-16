#include "paymenthistorywidget.h"
#include <QVBoxLayout>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QHeaderView>
#include <QSqlError>
PaymentHistoryWidget::PaymentHistoryWidget(QWidget *parent)
    : QWidget(parent), model(new QSqlQueryModel(this)), view(new QTableView(this)) {

    auto *layout = new QVBoxLayout(this);
    layout->addWidget(view);

    view->setModel(model);
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->horizontalHeader()->setStretchLastSection(true);

    loadData();
}

void PaymentHistoryWidget::loadData() {
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) return;

    model->setQuery("SELECT name AS '姓名', "
                    "fee_type AS '费用类型', "
                    "amount AS '金额(元)', "
                    "months AS '月数', "
                    "payment_method AS '方式', "
                    "payment_date AS '缴费时间' "
                    "FROM payments ORDER BY payment_date DESC", db);

    if (model->lastError().isValid()) {
        QMessageBox::warning(this, "错误", "加载缴费记录失败：" + model->lastError().text());
    }
}
