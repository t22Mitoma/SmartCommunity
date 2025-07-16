#ifndef WUYECHEWEIXINXIGUANLI_H
#define WUYECHEWEIXINXIGUANLI_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QTableView>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QLabel>

namespace Ui {
class Wuyecheweixinxiguanli;
}

class Wuyecheweixinxiguanli : public QWidget
{
    Q_OBJECT

public:
    explicit Wuyecheweixinxiguanli(QWidget *parent = nullptr);
    ~Wuyecheweixinxiguanli();

private slots:
    void on_addButton_clicked();     // 添加车位
    void on_modifyButton_clicked();  // 修改车位
    void on_queryButton_clicked();   // 查询车位
    void on_tableView_clicked(const QModelIndex &index); // 表格选中事件

private:
    Ui::Wuyecheweixinxiguanli *ui;

    // UI控件
    QTableView *tableView;          // 车位列表表格
    QLineEdit *numEdit;             // 车位编号输入框
    QLineEdit *addrEdit;            // 车位地址输入框
    QRadioButton *yradioButton;     // 已售出单选按钮
    QRadioButton *nradioButton;     // 未售出单选按钮
    QLineEdit *useridEdit;          // 购买人ID输入框
    QPushButton *addButton;         // 添加按钮
    QPushButton *modifyButton;      // 修改按钮
    QPushButton *queryButton;       // 查询按钮

    // 数据库相关
    QSqlDatabase getDBConnection();
    QSqlQueryModel *model;          // 表格数据模型
    void refreshTableView(const QString &sql = "SELECT * FROM park"); // 刷新表格
};

#endif // WUYECHEWEIXINXIGUANLI_H
