#ifndef PAYMENTHISTORYWIDGET_H
#define PAYMENTHISTORYWIDGET_H

#include <QWidget>
#include <QTableView>
#include <QSqlQueryModel>

class PaymentHistoryWidget : public QWidget {
    Q_OBJECT
public:
    explicit PaymentHistoryWidget(QWidget *parent = nullptr);

private:
    void loadData();

    QTableView *view;
    QSqlQueryModel *model;
};

#endif // PAYMENTHISTORYWIDGET_H
