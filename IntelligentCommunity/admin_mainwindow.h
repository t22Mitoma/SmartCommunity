#ifndef admin_mainwindow_h
#define admin_mainwindow_h

#include <QMainWindow>

namespace Ui {
class admin_MainWindow;
}

class admin_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit admin_MainWindow(QWidget *parent = nullptr);
    ~admin_MainWindow();

private slots:
    void on_action_triggered(); // 人事管理
    void on_actionqingjiashenpi_triggered(); // 出勤管理

private:
    Ui::admin_MainWindow *ui;
};

#endif // admin_mainwindow_h
