#include "owner_mainwindow.h"
#include "ui_owner_mainwindow.h"
#include "yezhuguzhuangbaoxiu.h"
#include "ui_yezhuguzhuangbaoxiu.h"
#include "yezhuguzhangchaxunpingjia.h"
#include "ui_yezhuguzhangchaxunpingjia.h"
#include "yezhucheweiguanli.h"
#include "ui_yezhucheweiguanli.h"
#include "yezhujiaofei.h"
#include "ui_yezhujiaofei.h"
#include "paymenthistorywidget.h"
#include "ui_paymenthistorywidget.h"
Owner_MainWindow::Owner_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Owner_MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("业主管理面板");
    this->setWindowIcon(QIcon(":/logo.png"));
}

Owner_MainWindow::~Owner_MainWindow()
{
    delete ui;
}

void Owner_MainWindow::on_action_3_triggered()//故障报修
{
    Yezhuguzhuangbaoxiu *yezhuguzhangbaoxiu = new Yezhuguzhuangbaoxiu;
    setCentralWidget(yezhuguzhangbaoxiu);
}

void Owner_MainWindow::on_action_2_triggered()//故障查询和评价界面
{
    Yezhuguzhangchaxunpingjia *chaxunpingjia = new Yezhuguzhangchaxunpingjia;
    setCentralWidget(chaxunpingjia);
}
void Owner_MainWindow::on_action_4_triggered()//车位管理界面
{
    // 修正类名大小写，与头文件中的定义保持一致
    YeZhuCheWeiGuanLi *cheweiguanli = new YeZhuCheWeiGuanLi;
    setCentralWidget(cheweiguanli);
}
void Owner_MainWindow::on_action_triggered()
{
    YeZhuJiaoFei *feeWidget = new YeZhuJiaoFei(this);
    setCentralWidget(feeWidget);
}
void Owner_MainWindow::on_action_5_triggered()
{
    PaymentHistoryWidget *historyWidget = new PaymentHistoryWidget(this);
    setCentralWidget(historyWidget);
}
