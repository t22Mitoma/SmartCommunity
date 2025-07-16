#ifndef YEZHUGUZHUANGBAOXIU_H
#define YEZHUGUZHUANGBAOXIU_H
#include <QWidget>
#include <QSqlDatabase> // 新增：引入数据库头文件
#include <QSqlQuery>

namespace Ui {
class Yezhuguzhuangbaoxiu;
}

class Yezhuguzhuangbaoxiu : public QWidget
{
    Q_OBJECT

public:
    explicit Yezhuguzhuangbaoxiu(QWidget *parent = nullptr);
    ~Yezhuguzhuangbaoxiu();

private slots:
    void on_pushButton_2_clicked(); // 提交按钮槽函数（已存在）

private:
    Ui::Yezhuguzhuangbaoxiu *ui;
    QSqlDatabase db; // 新增：数据库连接对象
    bool initDatabase(); // 新增：数据库初始化函数


};

#endif // YEZHUGUZHUANGBAOXIU_H
