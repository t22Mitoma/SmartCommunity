#include "wuyejiaofei.h"
#include <QVBoxLayout>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
WuYeJiaoFei::WuYeJiaoFei(QWidget *parent) : QWidget(parent) {
    auto *layout = new QVBoxLayout(this);

    feeTypeCombo = new QComboBox(this);
    feeTypeCombo->addItems({"物业费", "水电费", "停车费"});

    priceEdit = new QLineEdit(this);
    priceEdit->setPlaceholderText("请输入新的单价");

    setPriceButton = new QPushButton("设置单价", this);

    layout->addWidget(new QLabel("选择费用类型"));
    layout->addWidget(feeTypeCombo);
    layout->addWidget(new QLabel("设置新单价"));
    layout->addWidget(priceEdit);
    layout->addWidget(setPriceButton);

    connect(setPriceButton, &QPushButton::clicked, this, &WuYeJiaoFei::onSetPriceClicked);
}

void WuYeJiaoFei::onSetPriceClicked() {
    QString type = feeTypeCombo->currentText();
    double price = priceEdit->text().toDouble();

    if (price <= 0) {
        QMessageBox::warning(this, "错误", "请输入有效的单价");
        return;
    }

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) return;

    QSqlQuery query;
    query.prepare("UPDATE fee_types SET unit_price = :price WHERE name = :name");
    query.bindValue(":price", price);
    query.bindValue(":name", type);

    if (query.exec()) {
        QMessageBox::information(this, "成功", "单价已更新");
    } else {
        QMessageBox::critical(this, "失败", "更新失败：" + query.lastError().text());
    }
}
