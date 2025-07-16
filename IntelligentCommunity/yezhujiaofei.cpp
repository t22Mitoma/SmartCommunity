#include "yezhujiaofei.h"
#include <QVBoxLayout>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
YeZhuJiaoFei::YeZhuJiaoFei(QWidget *parent) : QWidget(parent) {
    auto *layout = new QVBoxLayout(this);

    nameEdit = new QLineEdit(this);
    nameEdit->setPlaceholderText("请输入姓名");

    feeTypeCombo = new QComboBox(this);
    feeTypeCombo->addItems({"物业费", "水电费", "停车费"});

    methodCombo = new QComboBox(this);
    methodCombo->addItems({"线上", "线下"});

    monthsEdit = new QLineEdit(this);
    monthsEdit->setPlaceholderText("请输入缴费月数");

    payButton = new QPushButton("缴费", this);
    totalLabel = new QLabel("总金额：0.00 元", this);

    layout->addWidget(new QLabel("姓名"));
    layout->addWidget(nameEdit);
    layout->addWidget(new QLabel("费用类型"));
    layout->addWidget(feeTypeCombo);
    layout->addWidget(new QLabel("缴费方式"));
    layout->addWidget(methodCombo);
    layout->addWidget(new QLabel("缴费月数"));
    layout->addWidget(monthsEdit);
    layout->addWidget(payButton);
    layout->addWidget(totalLabel);

    connect(payButton, &QPushButton::clicked, this, &YeZhuJiaoFei::onPayClicked);
}

void YeZhuJiaoFei::onPayClicked() {
    QString name = nameEdit->text().trimmed();
    QString type = feeTypeCombo->currentText();
    QString method = methodCombo->currentText();
    int months = monthsEdit->text().toInt();

    if (name.isEmpty() || months <= 0) {
        QMessageBox::warning(this, "错误", "请输入完整信息");
        return;
    }

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) return;

    QSqlQuery query;
    query.prepare("SELECT unit_price FROM fee_types WHERE name = :type");
    query.bindValue(":type", type);
    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, "错误", "无法获取单价");
        return;
    }

    double unitPrice = query.value(0).toDouble();
    double total = unitPrice * months;

    query.prepare("INSERT INTO payments (name, fee_type, amount, months, payment_method) "
                  "VALUES (:name, :type, :amount, :months, :method)");
    query.bindValue(":name", name);
    query.bindValue(":type", type);
    query.bindValue(":amount", total);
    query.bindValue(":months", months);
    query.bindValue(":method", method);

    if (query.exec()) {
        QMessageBox::information(this, "成功", QString("缴费成功，总金额：%1 元").arg(total));
        totalLabel->setText(QString("总金额：%1 元").arg(total));
    } else {
        QMessageBox::critical(this, "失败", "缴费失败：" + query.lastError().text());
    }
}
