#ifndef OWNER_MAINWINDOW_H
#define OWNER_MAINWINDOW_H

#include <QMainWindow>
#include "yezhujiaofei.h"  // 引入业主缴费类

namespace Ui {
class Owner_MainWindow;  // 仅声明业主窗口UI
}

class Owner_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit Owner_MainWindow(QWidget *parent = 0);
    ~Owner_MainWindow();

private slots:
    void on_action_3_triggered();
    void on_action_4_triggered();
    void on_action_2_triggered();
    void on_action_triggered();  // 新增：跳转到业主缴费的槽函数
    void on_action_5_triggered();
private:
    Ui::Owner_MainWindow *ui;
    YeZhuJiaoFei *yezhuFeiWidget;  // 业主缴费窗口实例
};

#endif // OWNER_MAINWINDOW_H
