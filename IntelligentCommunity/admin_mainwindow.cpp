#include "admin_mainwindow.h"
#include "ui_admin_mainwindow.h"
#include "guanliyuanrenshiguanli.h"
#include "ui_guanliyuanrenshiguanli.h"
#include "guanliyuanqingjiashenpi.h"
#include "ui_guanliyuanqingjiashenpi.h"

admin_MainWindow::admin_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::admin_MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("管理员管理面板");
    this->setWindowIcon(QIcon(":/logo.png"));

    Guanliyuanrenshiguanli *guanliyuanrenshiguanli = new Guanliyuanrenshiguanli;
    this->setCentralWidget(guanliyuanrenshiguanli);

    connect(ui->actionqingjiashenpi, &QAction::triggered, this, &admin_MainWindow::on_actionqingjiashenpi_triggered);
}

admin_MainWindow::~admin_MainWindow()
{
    delete ui;
}

void admin_MainWindow::on_action_triggered()
{
    Guanliyuanrenshiguanli *guanliyuanrenshiguanli = new Guanliyuanrenshiguanli;
    this->setCentralWidget(guanliyuanrenshiguanli);
}

void admin_MainWindow::on_actionqingjiashenpi_triggered()
{
    // 创建 guanliyuanqingjiashenpi 窗口实例
    guanliyuanqingjiashenpi *approvalWindow = new guanliyuanqingjiashenpi(this);
    // 设置为中央窗口
    this->setCentralWidget(approvalWindow);
}
