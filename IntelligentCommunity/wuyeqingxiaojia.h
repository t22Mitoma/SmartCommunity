#ifndef WUYEQINGXIAOJIA_H
#define WUYEQINGXIAOJIA_H

#include <QWidget>
#include <QSqlTableModel>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class Wuyeqingxiaojia; }
QT_END_NAMESPACE

class Wuyeqingxiaojia : public QWidget
{
    Q_OBJECT

public:
    explicit Wuyeqingxiaojia(QWidget *parent = nullptr);
    ~Wuyeqingxiaojia();

private slots:
    void on_pushButton_clicked();   // 请假
    void on_pushButton_2_clicked(); // 退出
    void on_pushButton_3_clicked(); // 销假
    void on_pushButton_4_clicked(); // 查询

private:
    Ui::Wuyeqingxiaojia *ui;
    QSqlTableModel *model;
    QSqlDatabase db;
};

#endif // WUYEQINGXIAOJIA_H
