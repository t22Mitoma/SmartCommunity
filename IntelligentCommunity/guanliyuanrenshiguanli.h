#ifndef GUANLIYUANRENSHIGUANLI_H
#define GUANLIYUANRENSHIGUANLI_H

#include <QWidget>
#include <QtSql/QSqlDatabase>  // 数据库连接类
#include <QtSql/QSqlQuery>     // 新增：查询类头文件（避免使用时未声明）

namespace Ui {
// 注意：此处类名需与.ui文件生成的类名完全一致
// 若.ui文件的对象名为"Guanliyuanrenshiguanli"，则应改为class Guanliyuanrenshiguanli;
class Widget;  // 暂保留原假设，需根据实际.ui文件调整
}

class Guanliyuanrenshiguanli : public QWidget
{
    Q_OBJECT

public:
    explicit Guanliyuanrenshiguanli(QWidget *parent = nullptr);
    ~Guanliyuanrenshiguanli();

private slots:
    void on_pushButton_clicked();      // 查询按钮点击事件
    void on_pushButton_2_clicked();    // 修改按钮点击事件
    void on_pushButton_3_clicked();    // 新增按钮点击事件
    void on_pushButton_4_clicked();    // 删除按钮点击事件

private:
    Ui::Widget *ui;                    // UI指针（需与namespace Ui中的类名匹配）
    QSqlDatabase db;                   // 数据库连接成员变量（核心修正）
};

#endif // GUANLIYUANRENSHIGUANLI_H
