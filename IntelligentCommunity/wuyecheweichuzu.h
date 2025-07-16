#ifndef WUYECHEWEICHUZU_H
#define WUYECHEWEICHUZU_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QTableView>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QLabel>

namespace Ui {
class Wuyecheweichuzu;
}

class Wuyecheweichuzu : public QWidget
{
    Q_OBJECT

public:
    explicit Wuyecheweichuzu(QWidget *parent = nullptr);
    ~Wuyecheweichuzu();

private slots:
    void on_selectpushButton_clicked();
    void on_yespushButton_clicked();
    void on_tableView_clicked(const QModelIndex &index); // 表格选中事件

private:
    Ui::Wuyecheweichuzu *ui;

    // UI控件
    QTableView *tableView;         // 车位列表表格
    QLineEdit *numlineEdit;        // 车位编号输入框
    QLineEdit *namelineEdit;       // 租户姓名输入框
    QLineEdit *IDlineEdit;         // 租户身份证输入框
    QPushButton *selectpushButton; // 查询未租赁车位按钮
    QPushButton *yespushButton;    // 确认租赁按钮

    // 数据库相关
    QSqlDatabase getDBConnection();
    void initDatabase();
    QSqlQueryModel *model;         // 表格数据模型
};

#endif // WUYECHEWEICHUZU_H
