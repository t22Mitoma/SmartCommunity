#ifndef STAFF_WIDGET_H
#define STAFF_WIDGET_H

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
class Wuyeweixiuguanli;
}

class Wuyeweixiuguanli : public QWidget
{
    Q_OBJECT

public:
    explicit Wuyeweixiuguanli(QWidget *parent = 0);
    ~Wuyeweixiuguanli();

     void refreshTableModel();

private slots:
    void on_pushButton_clicked();   //显示按钮

    void on_pushButton_3_clicked(); //删除按钮

    void on_pushButton_4_clicked(); //查询按钮

    void on_pushButton_2_clicked(); //修改按钮

    void on_lineEdit_4_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::Wuyeweixiuguanli *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
    QLabel *imageLabel;

};

#endif // STAFF_WIDGET_H
