#ifndef MONTHLYATTENDANCE_H
#define MONTHLYATTENDANCE_H

#include <QWidget>

#include <QDebug>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QTableView>
#include <string>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlRelationalTableModel>
namespace Ui {
class Wuyeyueduchuqin;
}

class Wuyeyueduchuqin : public QWidget
{
    Q_OBJECT

public:
    explicit Wuyeyueduchuqin(QWidget *parent = 0);
    ~Wuyeyueduchuqin();
private:
    Ui::Wuyeyueduchuqin *ui;
    QSqlQueryModel *model;
};

#endif // MONTHLYATTENDANCE_H
